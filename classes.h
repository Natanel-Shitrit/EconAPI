/**
 * EconAPI
 * Copyright (C) 2021 Natanel 'LuqS' Shitrit. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_

#include "utlhashmaplarge.h"
#include "utldict.h"

//-----------------------------------------------------------------------------
// A dictionary mapping from symbol to structure
//-----------------------------------------------------------------------------

// This is a useful macro to iterate from start to end in order in a map
#define FOR_EACH_DICT( dictName, iteratorName ) \
    for( int iteratorName=(dictName).First(); iteratorName != (dictName).InvalidIndex(); iteratorName = (dictName).Next( iteratorName ) )

// faster iteration, but in an unspecified order
#define FOR_EACH_DICT_FAST( dictName, iteratorName ) \
    for ( int iteratorName = 0; iteratorName < (dictName).MaxElement(); ++iteratorName ) if ( !(dictName).IsValidIndex( iteratorName ) ) continue; else


#define MAX_PAINT_DATA_NAME 128
#define MAX_STICKER_DATA_PATH 128

// The total number of loadouts to track for each player.
#define LOADOUT_COUNT       4	// these are the number of skins (2 valid + 2 invalid)

// CS Team IDs.
#define TEAM_ANY           -1	// for some team query methods
#define	TEAM_INVALID       -1
#define TEAM_UNASSIGNED     0	// not assigned to a team
#define TEAM_SPECTATOR      1	// spectator team
#define TEAM_TERRORIST      2
#define TEAM_CT             3
#define TEAM_MAXCOUNT       4

typedef uint32 RTime32;

// The Steam backend representation of a unique item index
typedef uint16 item_definition_index_t;
typedef uint16 attrib_definition_index_t;
typedef uint32 attrib_value_t;
typedef CUtlVector< uint32 > WorkshopContributorList_t;
typedef int econ_tag_handle_t;

// Misc typedefs for clarity.
typedef uint32    equip_region_mask_t;

enum attrib_colors_t
{
    ATTRIB_COL_LEVEL = 0,
    ATTRIB_COL_NEUTRAL,
    ATTRIB_COL_POSITIVE,
    ATTRIB_COL_NEGATIVE,
    ATTRIB_COL_ITEMSET_NAME,
    ATTRIB_COL_ITEMSET_EQUIPPED,
    ATTRIB_COL_ITEMSET_MISSING,
    ATTRIB_COL_BUNDLE_ITEM,
    ATTRIB_COL_LIMITED_USE,
    ATTRIB_COL_ITEM_FLAGS,
    ATTRIB_COL_RARITY_DEFAULT,
    ATTRIB_COL_RARITY_COMMON,
    ATTRIB_COL_RARITY_UNCOMMON,
    ATTRIB_COL_RARITY_RARE,
    ATTRIB_COL_RARITY_MYTHICAL,
    ATTRIB_COL_RARITY_LEGENDARY,
    ATTRIB_COL_RARITY_ANCIENT,
    ATTRIB_COL_RARITY_IMMORTAL,
    ATTRIB_COL_RARITY_ARCANA,
    ATTRIB_COL_STRANGE,
    ATTRIB_COL_UNUSUAL,

    NUM_ATTRIB_COLORS,
};

enum EItemType
{
    k_EItemTypeNone,
    k_EItemTypeCoupon,
    k_EItemTypeCampaign,
    k_EItemTypeSelfOpeningPurchase,
    k_EItemTypeOperationCoin,
    k_EItemTypePrestigeCoin,
    k_EItemTypeTool,
    k_EItemTypeGameLicense,
    k_EItemTypePickEmChallangeCoin,
    k_EItemTypeSubscription,
};

enum item_capabilities_t
{
    ITEM_CAP_NONE                   = 0,
    ITEM_CAP_PAINTABLE              = 1 << 0,        // some items are tagged in CS:GO schema, but we don't use it
    ITEM_CAP_NAMEABLE               = 1 << 1,        // used in CS:GO on all weapons that can get a name tag
    ITEM_CAP_DECODABLE              = 1 << 2,        // used in CS:GO on supply crates containers
    ITEM_CAP_CAN_DELETE             = 1 << 3,        // used in CS:GO on supply crates containers
    ITEM_CAP_CAN_CUSTOMIZE_TEXTURE  = 1 << 4,    // NOT USED
    ITEM_CAP_USABLE                 = 1 << 5,    // NOT USED
    ITEM_CAP_USABLE_GC              = 1 << 6,        // some items are tagged in CS:GO schema, but we don't use it
    ITEM_CAP_CAN_GIFT_WRAP          = 1 << 7,    // NOT USED
    ITEM_CAP_USABLE_OUT_OF_GAME     = 1 << 8,        // some items are tagged in CS:GO schema, but we don't use it
    ITEM_CAP_CAN_COLLECT            = 1 << 9,    // NOT USED
    ITEM_CAP_CAN_CRAFT_COUNT        = 1 << 10,    // NOT USED
    ITEM_CAP_CAN_CRAFT_MARK         = 1 << 11,    // NOT USED
    ITEM_CAP_PAINTABLE_TEAM_COLORS  = 1 << 12,    // NOT USED
    ITEM_CAP_CAN_BE_RESTORED        = 1 << 13,    // NOT USED
    ITEM_CAP_CAN_USE_STRANGE_PARTS  = 1 << 14,    // NOT USED
    ITEM_CAP_PAINTABLE_UNUSUAL      = 1 << 15,    // NOT USED
    ITEM_CAP_CAN_INCREMENT          = 1 << 16,    // NOT USED
    ITEM_CAP_USES_ESSENCE           = 1 << 17,    // NOT USED
    ITEM_CAP_AUTOGRAPH              = 1 << 18,    // NOT USED
    ITEM_CAP_RECIPE                 = 1 << 19,    // NOT USED
    ITEM_CAP_CAN_STICKER            = 1 << 20,        // used in CS:GO on sticker tools, primary and secondary weapons
    ITEM_CAP_STATTRACK_SWAP         = 1 << 21,        // used in CS:GO on stattrack items
    ITEM_CAP_CAN_PATCH              = 1 << 22,        // used in CS:GO on customplayers
    NUM_ITEM_CAPS                   = 23,
};

enum
{
    MATERIAL_MAX_LIGHT_COUNT = 4,
};

struct WeaponPaintableMaterial_t
{
    char m_szName[ MAX_PAINT_DATA_NAME ];
    char m_szOriginalMaterialName[ MAX_PAINT_DATA_NAME ];
    char m_szFolderName[ MAX_PAINT_DATA_NAME ];
    int m_nViewModelSize;                        // texture size
    int m_nWorldModelSize;                        // texture size
    float m_flWeaponLength;
    float m_flUVScale;
    bool m_bBaseTextureOverride;
    bool m_bMirrorPattern;
};

struct InventoryImageData_t
{
    QAngle *m_pCameraAngles; 
    Vector *m_pCameraOffset; 
    float   m_cameraFOV; 
    void   *m_pLightDesc[ MATERIAL_MAX_LIGHT_COUNT ]; // [LightDesc_t]
    bool    m_bOverrideDefaultLight; 
};

struct StickerData_t
{
    char m_szStickerModelPath[ MAX_STICKER_DATA_PATH ];
    char m_szStickerMaterialPath[ MAX_STICKER_DATA_PATH ];
    Vector m_vWorldModelProjectionStart;
    Vector m_vWorldModelProjectionEnd;
    char m_szStickerBoneParentName[ 32 ];
};

struct item_list_entry_t
{
    // Item def
    int m_nItemDef;
    
    // Paint kit applied to it
    int m_nPaintKit;
    int m_nPaintKitSeed;
    float m_flPaintKitWear;
    
    // Sticker kit applied to it
    uint32 m_nStickerKit;

    // music kit applied to it
    uint32 m_nMusicKit;
    
    bool m_bIsNestedList;
    bool m_bIsUnusualList;
    mutable bool m_bAlreadyUsedInRecursiveCreation;
};

struct bundleinfo_t
{
    CUtlVector <item_list_entry_t> vecItemEntries;
};

class IEconTool
{
private:
    const char *m_pszTypeName;
    const char *m_pszUseString;
    const char *m_pszUsageRestriction;
    item_capabilities_t m_unCapabilities;
    CUtlVector<int> m_vecBonusItemDef;
};

class CEconLootListDefinition
{
public:
    struct loot_list_additional_drop_t
    {
        float       m_fChance;
        bool        m_bPremiumOnly;
        const char *m_pszLootListDefName;
    };
    
    struct static_attrib_t
    {
        union attribute_data_union_t
        {
            float asFloat;
            uint32 asUint32;
            byte *asBlobPointer;
        };

        attrib_definition_index_t    iDefIndex;
        attribute_data_union_t m_value;
        bool    m_bForceGCToGenerate;
    };

    struct lootlist_attrib_t
    {
        static_attrib_t    m_staticAttrib;
        float    m_flWeight;
        float    m_flRangeMin;
        float    m_flRangeMax;

        CCopyableUtlVector< uint32 > m_vecValues;
    };

    struct random_attrib_t
    {
        float               m_flChanceOfRandomAttribute;
        float               m_flTotalAttributeWeight;
        bool                m_bPickAllAttributes;
        CUtlVector<lootlist_attrib_t> m_RandomAttributes;
    };

public:
    int                                GetAdditionalDropCount( void ) const { return m_AdditionalDrops.Count(); }
    const loot_list_additional_drop_t* GetAdditionalDrop( int iIndex ) const  { return m_AdditionalDrops.IsValidIndex(iIndex) ? &m_AdditionalDrops[iIndex] : nullptr; }
    const char *GetName() const                                         { return m_pszName; }
    int         GetItemCount( void ) const                              { return m_ItemEntries.Count(); }
    const item_list_entry_t* GetItem( int iIndex ) const                { return m_ItemEntries.IsValidIndex(iIndex) ? &m_ItemEntries[iIndex] : nullptr; }
    uint32      GetHeroID( void ) const                                 { return m_unHeroID; }
    bool        IsPublicListContents( void ) const                      { return m_bPublicListContents; }
    bool        ContainsStickersAutographedByProplayers( void ) const   { return m_bContainsStickersAutographedByProplayers; }
    bool        ContainsStickersRepresentingOrganizations( void ) const { return m_bContainsStickersRepresentingOrganizations; }
    bool        ContainsPatchesRepresentingOrganizations( void ) const  { return m_bContainsPatchesRepresentingOrganizations; }
    bool        WillProduceStattrak( void ) const                       { return m_bWillProduceStattrak; }
    float       GetTotalWeight( void ) const                            { return m_flTotalWeight; }
    // TODO: m_flWeights
    // TODO: m_RandomAttribs
    bool        IsServerList( void ) const                              { return m_bWillProduceStattrak; }
    // TODO: UNKNOWNS
private: 
    void*                           m_pVTable; // 0 (4)
    CUtlVector<loot_list_additional_drop_t>    m_AdditionalDrops; // 4 (+20)
    const char*                     m_pszName; // 24 (4)
    CUtlVector<item_list_entry_t>   m_ItemEntries; // 28 (20)
    uint32                            m_unHeroID;             // 48 (4)
    bool                            m_bPublicListContents;    // 52 (1) // do not show loot list contents to users (ie., when listing crate contents on Steam)
    bool                            m_bContainsStickersAutographedByProplayers;   // 53 (1)
    bool                            m_bContainsStickersRepresentingOrganizations;   // 54 (1)
    bool                            m_bContainsPatchesRepresentingOrganizations;   // 55 (1)
    bool                            m_bWillProduceStattrak; // 56 (1)
    // [Padding] 57 (3)
    float                           m_flTotalWeight; // 60 (4)
    CUtlVector<float>               m_flWeights; // 64 (20)
    CUtlVector<random_attrib_t*>    m_RandomAttribs; // 84 (20)
    bool                            m_bServerList; // 104 (1)
    bool                        unknown105; // 105 (1)
    // [Padding] 106 (2)
    int                         unknown108; // 108 (4)
    int                         unknown112; // 112 (4)
    int                         unknown116; // 116 (4)
    int                         unknown120; // 120 (4)
    int                         unknown124; // 124 (4)
};

class CEconItemDefinition
{
public:
    // booleans
    bool IsEnabled() const                      { return m_bEnabled; }
    bool HasProperName() const                  { return m_bProperName; }
    bool ShouldLoadOnDemand() const             { return m_bLoadOnDemand; }
    bool HasBeenLoaded() const                  { return m_bHasBeenLoaded; }
    bool HideBodyGroupsDeployedOnly() const     { return m_bHideBodyGroupsDeployedOnly; }
    bool ShouldAttachToHands() const            { return m_bAttachToHands; }
    bool ShouldAttachToHandsVMOnly() const      { return m_bAttachToHandsVMOnly; }
    bool ShouldFlipViewModel() const            { return m_bFlipViewModel; }
    bool IsActingAsWearable() const             { return m_bActAsWearable; }
    bool ShoulDisableStyleSelector() const      { return m_bDisableStyleSelection; }
    bool IsHidden() const                       { return m_bHidden; }
    bool ShouldShowInArmory() const             { return m_bShouldShowInArmory; }
    bool IsBaseItem() const                     { return m_bBaseItem; }
    bool IsDefaultSlotItem() const              { return m_bDefaultSlotItem; }
    bool IsImported() const                     { return m_bImported; }
    bool IsOnePerAccountCDKEY() const           { return m_bOnePerAccountCDKEY; }
    bool IsPackBundle() const                   { return m_bIsPackBundle; }
    bool IsPackItem() const                     { return m_pOwningPackBundle != NULL; }
    bool IsAllowedInMatch() const               { return m_bAllowedInThisMatch; }
    bool IsPublicItem() const                   { return m_bPublicItem; }
    bool IgnoreInCollectionView() const         { return m_bIgnoreInCollectionView; }

    // integers
    uint8 GetMinItemLevel() const           { return m_unMinItemLevel; }
    uint8 GetMaxItemLevel() const           { return m_unMaxItemLevel; }
    uint8 GetItemRarity() const             { return m_nItemRarity; }
    uint8 GetItemQuality() const            { return m_nItemQuality; }
    uint8 GetForcedItemQuality() const      { return m_nForcedItemQuality; }
    uint8 GetDefaultDropItemQuality() const { return m_nDefaultDropItemQuality; }
    uint8 GetDefaultDropQuantity() const    { return m_nDefaultDropQuantity; }
    uint8 GetPopularitySeed() const         { return m_nPopularitySeed; }
    uint16 GetDefinitionIndex() const       { return m_nDefIndex; }
    uint32 GetItemTypeID() const            { return m_unItemTypeID; }
    uint32 GetNumConcreteItems() const      { return m_unNumConcreteItems; }

    int GetNumSupportedStickerSlots() const { return m_vStickerModels.Count(); }
    int GetSoundMaterialID() const          { return m_nSoundMaterialID; }
    int GetArmoryRemap() const              { return m_iArmoryRemap; }
    int GetStoreRemap() const               { return m_iStoreRemap; }
    int GetDropType() const                 { return m_iDropType; }
    int GetSubType() const                  { return m_iSubType; }
    
    RTime32 GetExpirationTime() const   { return m_rtExpiration; }
    RTime32 GetDefCreationTime() const  { return m_rtDefCreation; }

    EItemType GetEconItemType() const           { return m_eItemType; }
    item_capabilities_t GetCapabilities() const { return m_iCapabilities; }

    equip_region_mask_t GetEquipRegionMask() const          { return m_unEquipRegionMask; }
    equip_region_mask_t GetEquipRegionConflictMask() const  { return m_unEquipRegionConflictMask; }

    // strings
    const char* GetPrefab() const                   { return m_szPrefab; }
    const char* GetBaseName() const                 { return m_pszItemBaseName; }
    const char* GetTypeName() const                 { return m_pszItemTypeName; }
    const char* GetDescription() const              { return m_pszItemDesc; }
    const char* GetInventoryModel() const           { return m_pszInventoryModel; }
    const char* GetInventoryImage() const           { return m_pszInventoryImage; }
    const char* GetBasePlayerDisplayModel() const   { return m_pszBaseDisplayModel; }
    const char* GetWorldDisplayModel() const        { return m_pszWorldDisplayModel; }
    const char* GetWorldDroppedModel() const        { return m_pszWorldDroppedModel; }
    const char* GetHolsteredModel() const           { return m_pszHolsteredModel; }
    const char* GetWorldExtraWearableModel() const  { return m_pszWorldExtraWearableModel; }
    const char* GetIconDefaultImage() const         { return m_pszIconDefaultImage; }
    const char* GetBrassModelOverride() const       { return m_pszBrassModelOverride; }
    const char* GetZoomInSound() const              { return m_pszZoomInSound; }
    const char* GetZoomOutSound() const             { return m_pszZoomOutSound; }
    const char* GetIconURLSmall() const             { return m_sIconURLSmall.Get(); }
    const char* GetIconURLLarge() const             { return m_sIconURLLarge.Get(); }
    const char* GetUnknown1() const                 { return m_sUnknown1.Get(); }
    const char* GetUnknown2() const                 { return m_sUnknown2.Get(); }
    const char* GetParticleFile() const             { return m_pszParticleFile; }
    const char* GetParticleSnapshotFile() const     { return m_pszParticleSnapshotFile; }
    const char* GetLootListName() const             { return m_pszLootListName; }
    const char* GetItemClassname() const            { return m_pszItemClassname; }
    const char* GetItemLogClassname() const         { return m_pszItemLogClassname; }
    const char* GetItemIconClassname() const        { return m_pszItemIconClassname; }
    const char* GetDefinitionName() const           { return m_pszDefinitionName; }
    const char* GetArmoryDescription() const        { return m_pszArmoryDesc; }
    const char* GetClassToken() const               { return m_pszClassToken; }
    const char* GetSlotToken() const                { return m_pszSlotToken; }
    const char* GetHolidayRestriction() const       { return m_pszHolidayRestriction; }

    // other
    CEconItemDefinition* GetOwningPackBundle() const { return m_pOwningPackBundle; }
private:
    void* m_pVTable; // 0 (4)
    KeyValues* m_pKVItem; // 4 (4)
    // The number used to refer to this definition in the DB
    item_definition_index_t    m_nDefIndex; // 8 (4)

    // List of associated items, such as multiple different keys for the same crate.
    CUtlVector< item_definition_index_t > m_nAssociatedItemsDefIndexes; // 12+ (20)

    // False if this definition has been turned off and we're not using it to generate items
    bool        m_bEnabled; // 32 (1)

    // [Padding] 33 (3)

    // The prefab used by the item.
    const char* m_szPrefab; // 36 (4)

    // These values specify the range of item levels that an item based off this definition can be generated within.
    uint8       m_unMinItemLevel; // 40 (1)
    uint8       m_unMaxItemLevel; // 41 (1)

    // This specifies an item's rarity.
    uint8       m_nItemRarity; // 42 (1)

    // This specifies an item quality that items from this definition must be set to. Used mostly to specify unique item definitions.
    uint8       m_nItemQuality; // 43 (1)
    uint8       m_nForcedItemQuality; // 44 (1)
    uint8       m_nDefaultDropItemQuality; // 45 (1)

    // Default drop quantity
    uint8       m_nDefaultDropQuantity; // 46 (1)

    // [Padding] 47 (1)

    // Static attributes (ones that are always on these items)
    CUtlVector<CEconLootListDefinition::static_attrib_t> m_vecStaticAttributes; // 48 (20)

    // Seeds the popular item list with this number of the item when the list is reset.
    uint8       m_nPopularitySeed; // 68 (1)
    
    // [Padding] 69 (3)

    // Portraits KV
    KeyValues*  m_pPortraitsKV; // 72 (4)

    // ---------------------------------------------
    // Display related data
    // ---------------------------------------------
    // The base name of this item. i.e. "The Kritz-Krieg".
    const char* m_pszItemBaseName; // 76 (4)
    bool        m_bProperName; // 80 (1)// If set, the name will have "The" prepended to it, unless it's got a non-unique quality
                                        // in which case it'll have "A" prepended to the quality. i.e. A Community Kritzkrieg

    // [Padding] 81 (3)

    // The base type of this item. i.e. "Rocket Launcher" or "Shotgun".
    // This is often the same as the base name, but not always.
    const char        *m_pszItemTypeName; // 84 (4)

    // A unique identifier for m_pszItemTypeName
    uint32            m_unItemTypeID; // 88 (4)

    // The item's non-attribute description.
    const char        *m_pszItemDesc; // 92 (4)

    // expiration time
    RTime32            m_rtExpiration; // 96 (4)

    // item def creation time
    RTime32            m_rtDefCreation; // 100 (4)

    // The .mdl file used for this item when it's displayed in inventory-style boxes.
    const char        *m_pszInventoryModel; // 104 (4)
    // Alternatively, the image used for this item when it's displayed in inventory-style boxes. If specified, it's used over the model.
    const char        *m_pszInventoryImage; // 108 (4)
    // An optional image that's overlayed over the top of the base inventory image. It'll be RGB colored by the tint color of the item.
    CUtlVector<const char*>    m_pszInventoryOverlayImages; // 112 (20)
    int                m_iInventoryImagePosition[2]; // 132,136 (8)
    int                m_iInventoryImageSize[2]; // 140,144 (8)

    const char        *m_pszBaseDisplayModel; // 148 (4)
    bool            m_bLoadOnDemand; // 152 (1)
    bool            m_bHasBeenLoaded; // 153 (1)

    bool            m_bHideBodyGroupsDeployedOnly; // 154 (1)

    // [Padding] 155 (1)

    // The .mdl file used for the world view.
    // This is inferior to using a c_model, but because the geometry of the sticky bomb launcher's
    // world model is significantly different from the view model the demoman pack requires
    // using two separate models for now.
    const char        *m_pszWorldDisplayModel; // 156 (4)
    const char        *m_pszWorldDroppedModel; // 160 (4)
    const char        *m_pszHolsteredModel; // 164 (4)
    const char        *m_pszWorldExtraWearableModel; // 168 (4)       // Some weapons attach an extra wearable item to the player
    char m_szWorldDroppedModel[80]; // 172 (80)

    // Sticker model paths
    CUtlVector<StickerData_t>  m_vStickerModels; // 252 (20)

    // This is the name of the default image used for the inventory until the generated image is ready
    const char        *m_pszIconDefaultImage; // 272 (4)

    // If set, we use the base hands model for a viewmodel, and bonemerge the above player model
    bool            m_bAttachToHands; // 276 (1)
    bool            m_bAttachToHandsVMOnly; // 277 (1)

    // If set, we will force the view model to render flipped. Good for models built left handed.
    bool            m_bFlipViewModel; // 278 (1)

    // This is a wearable that sits in a non-wearable loadout slot
    bool            m_bActAsWearable; // 279 (1)

    // The possible sets this item is a member of
    mutable CUtlVector< int > m_iItemSets; // 280 (20) - 55 89 E5 57 56 53 83 EC 2C 8B 7D 08 8B 75 0C 8B 9F 24 01 00 00

    // Asset Modifiers & Info
    void *m_pAssetInfo; // 300 (4) [AssetInfo]

    // Another way to group econ items with similar properties, separate from item_class.
    // (items of the same class may need to have different types). 
    EItemType        m_eItemType; // 304 (4)

    // Optional override for specifying a custom shell ejection model
    const char        *m_pszBrassModelOverride; // 308 (4)

    const char* m_pszZoomInSound; // 312 (4)
    const char* m_pszZoomOutSound; // 316 (4)

    IEconTool        *m_pTool; // 320 (4)
    bundleinfo_t    *m_BundleInfo; // 324 (4)
    item_capabilities_t m_iCapabilities; // 328 (4)

    uint32            m_unNumConcreteItems; // 332 (4)   // This is the number of items that will actually end up in a user's inventory - this can be 0 for some items (e.g. map stamps in TF), 1 for a "regular" item, or many for bundles, etc.

    int                m_nSoundMaterialID; // 336 (4)

    bool            m_bDisableStyleSelection; // 340 (1)

    // [Padding] 341 (3)

    CUtlString        m_sIconURLSmall; // 344 (16)
    CUtlString        m_sIconURLLarge; // 360 (16)
    CUtlString        m_sUnknown1; // 376 (16)
    CUtlString        m_sUnknown2; // 392 (16)

    //particle file
    const char        *m_pszParticleFile; // 408 (4)            // Some items have custom particle files attached to them
    const char        *m_pszParticleSnapshotFile; // 412 (4)    // Some weapons override a generic effect with a custom snapshot

    const char        *m_pszLootListName; // 416 (4)            // Optionally specified loot list for a crate item (instead of a supply crate series). 

    CUtlVector<int> m_nCharacterPaintKitIndices; // 420 (20)

    CUtlVector< WeaponPaintableMaterial_t > m_PaintData; // 440 (20)
    InventoryImageData_t*                   m_pInventoryImageData; // 460 (4)

    // ---------------------------------------------
    // Creation related data
    // ---------------------------------------------
    // The entity classname for this item.
    const char        *m_pszItemClassname; // 464 (4)

    // The entity name that will be displayed in log files.
    const char        *m_pszItemLogClassname; // 468 (4)

    // The name of the icon used in the death notices.
    const char        *m_pszItemIconClassname; // 472 (4)

    // This is the script file name of this definition. Used to generate items by script name.
    const char        *m_pszDefinitionName; // 476 (4)

    bool            m_bHidden; // 480 (1)
    bool            m_bShouldShowInArmory; // 481 (1)
    bool            m_bBaseItem; // 482 (1)
    bool            m_bDefaultSlotItem; // 483 (1)
    bool            m_bImported; // 484 (1)
    bool            m_bOnePerAccountCDKEY; // 485 (1)

    // A pack bundle is a bundle that contains items that are not for sale individually
    bool            m_bIsPackBundle; // 486 (1)
    
    // [Padding] 487 (1)

    // A pack item is an item which is not for sale individually and is only for sale as part of a pack bundle. A 'regular' bundle can only include a pack bundle by explicitly including all of the pack bundle's items individually.
    // If this pointer is non-NULL, this item is considered to be a pack item (see CEconItemDefinition::IsPackItem()).
    CEconItemDefinition*    m_pOwningPackBundle; // 488 (4)

    // Contains information on how to describe items with this attribute in the Armory
    const char        *m_pszArmoryDesc; // 492 (4)

    // ---------------------------------------------
    // Remapping data for armory/store
    // ---------------------------------------------
    int                m_iArmoryRemap; // 496 (4)
    int                m_iStoreRemap; // 500 (4)
    const char        *m_pszArmoryRemap; // 504 (4)
    const char        *m_pszStoreRemap; // 508 (4)

    // ---------------------------------------------
    // Crafting related data
    // ---------------------------------------------
    const char        *m_pszClassToken; // 512 (4)
    const char        *m_pszSlotToken; // 516 (4)

    // ---------------------------------------------
    // Gameplay related data
    // ---------------------------------------------
    // How to behave when the player wearing the item dies.
    int                m_iDropType; // 520 (4)

    // Holiday restriction. Item only has an appearance when the holiday is in effect.
    const char        *m_pszHolidayRestriction; // 524 (4)

    // Temporary. Revisit this in the engineer update. Enables an additional buildable.
    int                m_iSubType; // 528 (4)

    // Whitelist support for tournament mode
    bool            m_bAllowedInThisMatch; // 532 (1)

    // [Padding] 533 (3)

    // this will hold a pointer to the criteria that should be used to generate the real item
    void* m_pProxyCriteria; // 536 (4) [CItemSelectionCriteria*]

    equip_region_mask_t    m_unEquipRegionMask; // 540 (4)          // which equip regions does this item cover directly
    equip_region_mask_t m_unEquipRegionConflictMask; // 544 (4)     // which equip regions does equipping this item prevent from having something in them

    // Alternate icons.
    CUtlMap<uint32, const char*>*        m_pMapAlternateIcons; // 548 (4)

    CUtlVector<econ_tag_handle_t>    m_vecTags; // 552 (20)
    CUtlVector<const CEconItemDefinition *> m_vecContainingBundleItemDefs; // 572 (20) // Item definition indices for any bundles which contain this item
    WorkshopContributorList_t m_vecSteamWorkshopContributors; // 592 (20)

    friend class CEconItemSchema;
    bool            m_bPublicItem; // 612 (1)
    bool            m_bIgnoreInCollectionView; // 613 (1)

    // [Padding] 614 (2)

    // SIZE == 616
};

class CCStrike15ItemDefinition : public CEconItemDefinition
{
public:
    int         GetUsedByTeam();
    int         GetLoadoutSlot(int iTeam);
    bool        CanBeUsedByTeam( int iTeam ) const { return m_vbClassUsability.IsBitSet( iTeam ); }
private:
    // The load-out slot that this item can be placed into.
    int                     m_iDefaultLoadoutSlot; // 616 (4)
    int                     m_iGearSlot; // 620 (4)
    int                     m_iGearSlotPosition; // 624 (4)
    int                     m_iAnimationSlot; // 628 (4)

    // The .mdl file used for this item when it's being carried by a player.
    const char              *m_pszPlayerDisplayModel[LOADOUT_COUNT]; // 632 (4 * 4 = 16)

    // Specifies which class can use this item.
    CBitVec<LOADOUT_COUNT>  m_vbClassUsability; // 648 (4 * 1 = 4)
    int                     m_iLoadoutSlots[LOADOUT_COUNT];        // Slot that each class places the item into.
    bool m_bIsSupplyCrate : 1;
    bool m_bItemSharesEquipSlot : 1;
};

class CPaintKit
{
public:
    int         GetID( void ) const                 { return nID; }
    const char *GetName( void ) const               { return sName.Get(); }
    const char *GetDescriptionString( void ) const  { return sDescriptionString.Get(); }
    const char *GetDescriptionTag( void ) const     { return sDescriptionTag.Get(); }
    const char *GetPattern( void ) const            { return sPattern.Get(); }
    const char *GetLogoMaterial( void ) const       { return sLogoMaterial.Get(); }
    int         GetRarity( void ) const             { return nRarity; }
    int         GetStyle( void ) const              { return nStyle; }
    // todo: add color natives
    float       GetWearRemapMin( void ) const       { return flWearRemapMin; }
    float       GetWearRemapMax( void ) const       { return flWearRemapMax; }
    float       GetPatternScale( void ) const       { return flPatternScale; }
    const char *GetVmtPath( void ) const            { return sVmtPath.Get(); }

private:
    enum { NUM_COLORS = 4 };

    // Generic fields
    int nID;
    CUtlString sName;
    CUtlString sDescriptionString;
    CUtlString sDescriptionTag;
    CUtlString sSameNameFamilyAggregate;    // NEW
    
    // (Generally) Weapon paint kit fields
    // Note that some fields may affect item generation for other paint kit types;
    // in particular the wear settings.
    CUtlString sPattern;
    CUtlString sNormal;                     // NEW
    CUtlString sLogoMaterial;
    int bBaseDiffuseOverride;//bool
    int nRarity;
    int nStyle;
    Color rgbaColor[ NUM_COLORS ];
    Color rgbaLogoColor[ NUM_COLORS ];
    float flWearDefault;
    float flWearRemapMin;
    float flWearRemapMax;
    unsigned char nFixedSeed;
    unsigned char uchPhongExponent;
    unsigned char uchPhongAlbedoBoost;
    unsigned char uchPhongIntensity;
    float flPatternScale;
    float flPatternOffsetXStart;
    float flPatternOffsetXEnd;
    float flPatternOffsetYStart;
    float flPatternOffsetYEnd;
    float flPatternRotateStart;
    float flPatternRotateEnd;
    float flLogoScale;
    float flLogoOffsetX;
    float flLogoOffsetY;
    float flLogoRotation;
    int bIgnoreWeaponSizeScale;// bool
    int nViewModelExponentOverrideSize;
    int bOnlyFirstMaterial;// bool
    float flPearlescent;

    // Character paint kit fields
    CUtlString sVmtPath;
    KeyValues* kvVmtOverrides;
};

class CStickerKit
{
public:
    int         GetID( void ) const                     { return nID; }
    int         GetRarity( void ) const                 { return nRarity; }
    const char *GetName( void ) const                   { return sName.Get(); }
    const char *GetDescriptionString( void ) const      { return sDescriptionString.Get(); }
    const char *GetsItemName( void ) const              { return sItemName.Get(); }
    const char *GetMaterialPath( void ) const           { return sMaterialPath.Get(); }
    const char *GetMaterialPathNoDrips( void ) const    { return sMaterialPathNoDrips.Get(); }
    const char *GetInventoryImage( void ) const         { return m_strInventoryImage.Get(); }

    int         GetEventID( void ) const                { return m_nEventID; }
    int         GetEventTeamID( void ) const            { return m_nEventTeamID; }
    int         GetPlayerID( void ) const               { return m_nPlayerID; }

    bool        IsMaterialPathIsAbsolute( void ) const  { return bMaterialPathIsAbsolute; }

    float       GetScaleMin( void ) const               { return flScaleMin; }
    float       GetScaleMax( void ) const               { return flScaleMax; }

    float       GetWearMin( void ) const                { return flWearMin; }
    float       GetWearMax( void ) const                { return flWearMax; }

    const char *GetIconURLSmall() const                 { return m_sIconURLSmall.Get(); }
    const char *GetIconURLLarge() const                 { return m_sIconURLLarge.Get(); }

private:
    int nID;
    int nRarity;
    CUtlString sName;
    CUtlString sDescriptionString;
    CUtlString sItemName;
    CUtlString sMaterialPath;
    CUtlString sMaterialPathNoDrips;
    CUtlString m_strInventoryImage;

    int m_nEventID;
    int m_nEventTeamID;
    int m_nPlayerID;

    bool bMaterialPathIsAbsolute;

    float flRotateStart;
    float flRotateEnd;

    float flScaleMin;
    float flScaleMax;

    float flWearMin;
    float flWearMax;

    CUtlString m_sIconURLSmall;
    CUtlString m_sIconURLLarge;
    KeyValues *m_pKVItem;
};

class CEconMusicDefinition
{
public:
    uint32      GetID( void ) const                     { return nID; }
    const char* GetName( void ) const                   { return m_strName.Get(); }
    const char* GetNameLocToken( void ) const           { return m_strNameLocToken.Get(); }
    const char* GetDescription( void ) const            { return m_strLocDescription.Get(); }
    const char* GetInventoryImage( void ) const         { return m_strInventoryImage.Get(); }
    const char* GetPedestalDisplayModel( void ) const   { return m_strPedestalDisplayModel.Get(); }

private:
    int             nID;
    CUtlConstString m_strName;
    CUtlConstString m_strNameLocToken;
    CUtlConstString m_strLocDescription;
    CUtlConstString m_strPedestalDisplayModel;
    CUtlConstString m_strInventoryImage;
};

class CEconItemSetDefinition
{
public:
    const char* GetName( void ) const                       { return m_pszName; }
    const char* GetLocKey( void ) const                     { return m_pszLocalizedName; }
    const char* GetUnlocalizedName( void ) const            { return m_pszUnlocalizedName; }
    const char* GetLocDescription( void ) const             { return m_pszLocalizedDescription; }
    int         GetBundle( void ) const                     { return m_iBundleItemDef; }
    int         IsCollection( void ) const                  { return m_bIsCollection; }
    int         IsHiddenSet( void ) const                   { return m_bIsHiddenSet; }
    int         GetItemCount( void ) const                  { return m_ItemEntries.Count(); }
    const item_list_entry_t* GetItem( int iIndex ) const    { return &m_ItemEntries[iIndex]; }
    item_definition_index_t GetCraftReward( void ) const    { return m_nCraftReward; }
private: 
    void* m_pVTable;
    const char    *m_pszName;
    const char    *m_pszLocalizedName;
    const char    *m_pszUnlocalizedName;
    const char    *m_pszLocalizedDescription;
    CUtlVector<item_list_entry_t> m_ItemEntries;
    int            m_iBundleItemDef;
    bool           m_bIsCollection;
    bool           m_bIsHiddenSet;
    item_definition_index_t    m_nCraftReward;

    struct itemset_attrib_t
    {
        int        m_iAttribDefIndex;
        attrib_value_t    m_valValue;
    };
    CUtlVector<itemset_attrib_t>    m_iAttributes;
};

class CEconItemRarityDefinition
{
public:
    int32               GetDBValue( void ) const            { return m_nValue; }
    const char         *GetName( void ) const               { return !m_strName.IsEmpty() ? m_strName.String() : "unknown"; }
    const char         *GetLocKey( void ) const             { return m_strLocKey.String(); }
    const char         *GetWepLocKey( void ) const          { return m_strWepLocKey.String(); }
    const char         *GetCharacterLocKey( void ) const    { return m_strCharacterLocKey.String(); }
    const char         *GetLootList( void ) const           { return m_strLootList.String(); }
    const char         *GetRecycleLootList( void ) const    { return m_strRecycleLootList.String(); }
    const char         *GetDropSound( void ) const          { return m_strDropSound.String(); }    
    attrib_colors_t     GetAttribColor( void ) const        { return m_iAttribColor; }
    const char         *GetNextRarity( void ) const         { return m_strNextRarity.String(); }
    int                 GetWhiteCount( void ) const         { return m_iWhiteCount; }
    int                 GetBlackCount( void ) const         { return m_iBlackCount; }
    float               GetWeight( void ) const             { return m_flWeight; }
private:
    // The value that the game/DB will know this rarity by
    int32        m_nValue;
    attrib_colors_t        m_iAttribColor;

    // The English name of the rarity
    CUtlString    m_strName;

    // The localization key for this rarity.
    CUtlString  m_strLocKey;
    // The localization key for this rarity, for weapons.
    CUtlString  m_strWepLocKey;
    // The localization key for this rarity, for characters.
    CUtlString  m_strCharacterLocKey;

    // The loot list name associated with this rarity.
    CUtlString  m_strLootList;
    CUtlString  m_strRecycleLootList;
    CUtlString  m_strDropSound;
    
    CUtlString  m_strNextRarity;

    int            m_iWhiteCount;
    int            m_iBlackCount;

    float        m_flWeight;
};

class CEconItemQualityDefinition
{
public:
    int32       GetDBValue( void ) const                    { return m_nValue; }
    const char *GetName( void ) const                       { return !m_strName.IsEmpty() ? m_strName.Get() : "unknown"; }
    uint32      GetWeight( void ) const                     { return m_unWeight; }
    bool        GetRequiresExplicitMatches( void ) const    { return m_bExplicitMatchesOnly; }
    bool        CanSupportSet( void ) const                 { return m_bCanSupportSet; }
    const char *GetHexColor( void ) const                   { return !m_strHexColor.IsEmpty() ? m_strHexColor.Get() : "B2B2B2"; }
private:
    // The value that the game/DB will know this quality by
    int32            m_nValue;

    // The English name of the quality
    CUtlConstString    m_strName;

    // The weight used for choosing the quality. The higher the weight, the more likely it will be chosen.
    uint32        m_unWeight; 

    // Whether or not items chosen to be of this quality only match item definitions that are explicitly defined as being of this quality
    bool        m_bExplicitMatchesOnly;

    // if this is true the support tool is allowed to set this quality level on any item
    bool            m_bCanSupportSet;

    // A hex string representing the color this quality should display as. Used primarily for display on the Web.
    CUtlConstString    m_strHexColor;
};

class CEconItemSchema
{
public:
    static void* operator new(size_t) throw();
    static void operator delete(void*) { };

    // CEconItemDefinition
    CUtlHashMapLarge<int, CEconItemDefinition*>* GetItemDefinitionMap();
    CEconItemDefinition* GetItemDefinition(int iIndex) { return GetItemDefinitionMap()->IsValidIndex(iIndex) ? GetItemDefinitionMap()->Element(iIndex) : nullptr; }
    CEconItemDefinition* GetItemDefinitionByName(const char* pszDefName);
    CEconItemDefinition* GetItemDefinitionByDefIndex(uint16_t iItemIndex);

    // CPaintKit
    CUtlMap<int, CPaintKit*, int, CDefLess<int>>* GetPaintKitMap();
    CPaintKit* GetPaintKit(int iIndex) { return GetPaintKitMap()->IsValidIndex(iIndex) ? GetPaintKitMap()->Element(iIndex) : nullptr; }
    CPaintKit* GetPaintKitByName(const char* pszDefName);
    CPaintKit* GetPaintKitByID(uint32 iItemIndex);

    // CStickerKit
    CUtlMap<int, CStickerKit*, int, CDefLess<int>>* GetStickerKitMap();
    CStickerKit* GetStickerKit(int iIndex) { return GetStickerKitMap()->IsValidIndex(iIndex) ? GetStickerKitMap()->Element(iIndex) : nullptr; }
    CStickerKit* GetStickerKitByName(const char* pszDefName);
    CStickerKit* GetStickerKitByID(uint32 iID);

    // CEconMusicDefinition
    CUtlMap<int, CEconMusicDefinition*, int, CDefLess<int>>* GetMusicDefinitionMap();
    CEconMusicDefinition* GetMusicDefinition(int iIndex) { return GetMusicDefinitionMap()->IsValidIndex(iIndex) ? GetMusicDefinitionMap()->Element(iIndex) : nullptr; }
    CEconMusicDefinition* GetMusicDefinitionByName(const char* pszDefName);
    CEconMusicDefinition* GetMusicDefinitionByID(uint32 iItemIndex);

    // CEconItemSetDefinition
    CUtlMap<const char*, CEconItemSetDefinition, int>* GetItemSetDefinitionMap();
    CEconItemSetDefinition* GetItemSetDefinition(int iIndex) { return GetItemSetDefinitionMap()->IsValidIndex(iIndex) ? &GetItemSetDefinitionMap()->Element(iIndex) : nullptr; }
    CEconItemSetDefinition* GetItemSetByName(const char* pszName);

    // CEconItemRarityDefinition
    CUtlMap<int, CEconItemRarityDefinition, int, CDefLess<int>>* GetItemRarityDefinitionMap();
    CEconItemRarityDefinition* GetItemRarityDefinition(int iIndex) { return GetItemRarityDefinitionMap()->IsValidIndex(iIndex) ? &GetItemRarityDefinitionMap()->Element(iIndex) : nullptr; }
    CEconItemRarityDefinition* GetItemRarityDefinitionByName(const char* pszName);
    CEconItemRarityDefinition* GetItemRarityDefinitionByDBValue(uint32 iValue);

    // CEconItemQualityDefinition
    CUtlMap<int, CEconItemQualityDefinition, int, CDefLess<int>>* GetItemQualityDefinitionMap();
    CEconItemQualityDefinition* GetItemQualityDefinition(int iIndex) { return GetItemQualityDefinitionMap()->IsValidIndex(iIndex) ? &GetItemQualityDefinitionMap()->Element(iIndex) : nullptr; }
    CEconItemQualityDefinition* GetItemQualityDefinitionByName(const char* pszName);
    CEconItemQualityDefinition* GetItemQualityDefinitionByDBValue(uint32 iValue);

    // CEconLootListDefinition
    CUtlDict<CEconLootListDefinition>*  GetLootListDefinitionDict();
    CEconLootListDefinition*            GetLootListDefinition(int iIndex) { return GetLootListDefinitionDict()->IsValidIndex(iIndex) ? &GetLootListDefinitionDict()->Element(iIndex) : nullptr; }
    CEconLootListDefinition*            GetLootListDefinitionByName(const char* pszName);
    const char*                         GetLootListDefinitionName(CEconLootListDefinition* pLootListDefinition);
};

extern CEconItemSchema* g_pCEconItemSchema;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_