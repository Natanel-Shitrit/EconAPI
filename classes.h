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
#include "utlstring.h"
#include "string_t.h"

//-----------------------------------------------------------------------------
// A dictionary mapping from symbol to structure
//-----------------------------------------------------------------------------

// This is a useful macro to iterate from start to end in order in a map
#define FOR_EACH_DICT( dictName, iteratorName ) \
	for( int iteratorName=(dictName).First(); iteratorName != (dictName).InvalidIndex(); iteratorName = (dictName).Next( iteratorName ) )

// faster iteration, but in an unspecified order
#define FOR_EACH_DICT_FAST( dictName, iteratorName ) \
	for ( int iteratorName = 0; iteratorName < (dictName).MaxElement(); ++iteratorName ) if ( !(dictName).IsValidIndex( iteratorName ) ) continue; else


typedef uint32 RTime32;

// The Steam backend representation of a unique item index
typedef uint64	itemid_t;
typedef uint16 item_definition_index_t;
typedef uint16 attrib_definition_index_t;
typedef uint32 attrib_value_t;

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

class CEconItemDefinition
{
public:
    uint16 GetDefinitionIndex() { return m_nDefIndex; }
    int GetLoadoutSlot(int iTeam);
    int GetUsedByTeam();
    int GetNumSupportedStickerSlots();
    const char* GetInventoryImage();
    const char* GetBasePlayerDisplayModel();
    const char* GetWorldDisplayModel();
    const char* GetWorldDroppedModel();
    const char* GetDefinitionName();

private: // Not used, just for offset.
    void* m_pVTable;
    KeyValues* m_pKVItem;
public: // Used.
    uint16 m_nDefIndex; //8
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
private: // Not used, just for offset.
    void* m_pVTable;
private: // Used.
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

        attrib_definition_index_t	iDefIndex;
        attribute_data_union_t m_value;
        bool	m_bForceGCToGenerate;
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
	uint32				            m_unHeroID;             // 48 (4)
	bool				            m_bPublicListContents;	// 52 (1) // do not show loot list contents to users (ie., when listing crate contents on Steam)
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