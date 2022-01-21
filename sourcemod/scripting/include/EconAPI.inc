/**
 * EconAPI
 * Copyright (C) 2021-2022 Natanel 'LuqS' Shitrit. All rights reserved.
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

#if defined _EconAPI_included
  #endinput
#endif
#define _EconAPI_included

#define PAINT_KIT_NUM_COLORS 4

enum ModelType
{
    ViewModel = 0,
    WorldModel,
    DroppedModel,
    HolsteredModel,
    WorldExtraWearableModel,
    InventoryModel
}

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
    k_EItemTypeSubscription
}

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
    ITEM_CAP_CAN_PATCH              = 1 << 22,        // used in CS:GO on patch tools, on customplayers
    NUM_ITEM_CAPS                   = 23
}

enum EAssetClassAttrExportRule_t
{
    k_EAssetClassAttrExportRule_Default     = 0,
    k_EAssetClassAttrExportRule_Bucketed    = ( 1 << 0 ),    // attribute exports bucketed value to Steam Community
    k_EAssetClassAttrExportRule_Skip        = ( 1 << 1 ),    // attribute value is not exported to Steam Community
    k_EAssetClassAttrExportRule_GCOnly      = ( 1 << 2 ),    // attribute only lives on GC and not exported to any external request
}

// Coloring for attribute lines
enum attrib_effect_types_t
{
    ATTRIB_EFFECT_NEUTRAL = 0,
    ATTRIB_EFFECT_POSITIVE,
    ATTRIB_EFFECT_NEGATIVE,

    NUM_EFFECT_TYPES,
}

enum CEconItemDefinition
{
    CEconItemDefinition_NULL = 0
}

enum CPaintKit
{
    CPaintKit_NULL = 0
}

enum CStickerKit
{
    CStickerKit_NULL = 0
}

enum CEconMusicDefinition
{
    CEconMusicDefinition_NULL = 0
}

enum CEconItemSetDefinition
{
    CEconItemSetDefinition_NULL = 0
}

enum CEconItemRarityDefinition
{
    CEconItemRarityDefinition_NULL = 0
}

enum CEconItemQualityDefinition
{
    CEconItemQualityDefinition_NULL = 0
}

methodmap CEconItemDefinition
{
    /**
     * Gets a 'CEconItemDefinition' by index (not definition index!).
     *
     * @return              'CEconItemDefinition' item in the given index, or null if invalid index.
     *
     * @note                Invalid index: index < 0 or index >= CEconItemDefinition.Count().
     */
    public static native CEconItemDefinition Get(int index);
    
    /**
     * Gets the number of 'CEconItemDefinition's.
     *
     * @return              Number of 'CEconItemDefinition's.
     */
    public static native int Count();

    /**
     * Finds a 'CEconItemDefinition' by name.
     *
     * @return              'CEconItemDefinition' item with the given name, or null if not found.
     */
    public static native CEconItemDefinition FindByName(const char[] name);
    
    /**
     * Finds a 'CEconItemDefinition' by definition index.
     *
     * @return              'CEconItemDefinition' item with the given definition index, or null if not found.
     */
    public static native CEconItemDefinition FindByDefIndex(int def_index);


    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsEnabled
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool HasProperName
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShouldLoadOnDemand
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool HasBeenLoaded
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool HideBodyGroupsDeployedOnly
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShouldAttachToHands
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShouldAttachToHandsVMOnly
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShouldFlipViewModel
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsActingAsWearable
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShoulDisableStyleSelector
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsHidden
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool ShouldShowInArmory
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsBaseItem
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsDefaultSlotItem
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsImported
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsOnePerAccountCDKEY
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsPackBundle
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsPackItem
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsAllowedInMatch
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IsPublicItem
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property bool IgnoreInCollectionView
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int MinItemLevel
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int MaxItemLevel
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' item rarity.
     *
     * @return             Item rarity (CEconItemRarityDefinition).
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property CEconItemRarityDefinition ItemRarity
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' item quality.
     *
     * @return             Item quality (CEconItemQualityDefinition).
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property CEconItemQualityDefinition ItemQuality
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' forced item quality.
     *
     * @return             Forced item quality (CEconItemQualityDefinition).
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property CEconItemQualityDefinition ForcedItemQuality
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' default drop item quality.
     *
     * @return             Default drop item quality (CEconItemQualityDefinition).
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property CEconItemQualityDefinition DefaultDropItemQuality
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' default drop quantity.
     *
     * @return             Default drop quantity.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int DefaultDropQuantity
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int PopularitySeed
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int DefinitionIndex
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int ItemTypeID
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int NumConcreteItems
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int NumSupportedStickerSlots
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int SoundMaterialID
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int ArmoryRemap
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int StoreRemap
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int DropType
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int SubType
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int ExpirationTime
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int DefCreationTime
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int EconItemType
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int Capabilities
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int EquipRegionMask
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @return             Item .
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int EquipRegionConflictMask
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetBaseName(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetTypeName(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetDescription(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' econ image path inside "resource/flash/".
     * Example: "econ/weapons/base_weapons/weapon_knife"
     *
     * @note Add ".png" in the end of string for full formatting.
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetInventoryImage(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetIconDefaultImage(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetBrassModelOverride(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetZoomInSound(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetZoomOutSound(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetIconURLSmall(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetIconURLLarge(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetUnknown1(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetUnknown2(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetParticleFile(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetParticleSnapshotFile(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetLootListName(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetItemClassname(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetItemLogClassname(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetItemIconClassname(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' definition name.
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetDefinitionName(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetArmoryDescription(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetClassToken(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetSlotToken(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' .
     *
     * @param buffer       Data string buffer.
     * @param len          Maximum length of buffer.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetHolidayRestriction(char[] buffer, int len);

    /**
     * Gets the 'CEconItemDefinition' team (where the item is used).
     *
     * @return             Team index or 0 for both.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    property int UsedByTeam
    {
        public native get();
    }

    /**
     * Gets the 'CEconItemDefinition' loadout slot.
     *
     * @param team         Team index (0 for non-specific team slot).
     *
     * @return             Loadout slot index.
     *
     * @error              Invalid CEconItemDefinition. (NULL)
     */
    public native int GetLoadoutSlot(int team = 0);

    /**
     * Gets the item model path.
     *
     * @param model_type   Model type.
     * @param buffer       Destination string buffer.
     * @param len          Maximum length of output string buffer.
     *                     Max size PLATFORM_MAX_PATH.
     *
     * @return             Number of characters written.
     *
     * @error              Invalid model_type or invalid CEconItemDefinition. (NULL)
     */
    public native int GetModel(ModelType model_type, char[] buffer, int len);
}

methodmap CPaintKit
{
	property int NumColors
	{
		public get() { return PAINT_KIT_NUM_COLORS; }
	}

    public static native CPaintKit Get(int index);
    public static native int Count();

    public static native CPaintKit FindByID(int id);
    public static native CPaintKit FindByName(const char[] name);
    
    /**
     * Gets the item name.
     *
     * @param buffer        Destination string buffer.
     * @param len           Maximum length of output string buffer.
     *
     * @return              Returns length or 0 if failed.
     *
     * @error               CPaintKit == NULL.
     */
    public native int GetName(char[] buffer, int len);
    public native int GetDescription(char[] buffer, int len);
    public native int GetDescriptionTag(char[] buffer, int len);
    public native int GetSameNameFamilyAggregate(char[] buffer, int len);
    public native int GetPattern(char[] buffer, int len);
    public native int GetNormal(char[] buffer, int len);
    public native int GetLogoMaterial(char[] buffer, int len);

    property int ID
    {
        public native get();
    }

    property CEconItemRarityDefinition Rarity
    {
        public native get();
    }
    
    property int Style
    {
        public native get();
    }
    
    public native void GetRGBAColor(int index, int color[4]);
    public native void GetRGBALogoColor(int index, int color[4]);

    property float DefaultWear
    {
        public native get();
    }

    property float MinWear
    {
        public native get();
    }
    
    property float MaxWear
    {
        public native get();
    }
    
    property int FixedSeed
    {
        public native get();
    }
    
    property int PhongExponent
    {
        public native get();
    }
    
    property int PhongAlbedoBoost
    {
        public native get();
    }
    
    property int PhongIntensity
    {
        public native get();
    }

    property float PatternScale
    {
        public native get();
    }

    property float PatternOffsetXStart
    {
        public native get();
    }

    property float PatternOffsetXEnd
    {
        public native get();
    }

    property float PatternOffsetYStart
    {
        public native get();
    }

    property float PatternOffsetYEnd
    {
        public native get();
    }

    property float PatternRotateStart
    {
        public native get();
    }

    property float PatternRotateEnd
    {
        public native get();
    }

    property float LogoScale
    {
        public native get();
    }

    property float LogoOffsetX
    {
        public native get();
    }

    property float LogoOffsetY
    {
        public native get();
    }

    property float LogoRotation
    {
        public native get();
    }

    property bool IgnoreWeaponSizeScale
    {
        public native get();
    }

    property int ViewModelExponentOverrideSize
    {
        public native get();
    }

    property bool OnlyFirstMaterial
    {
        public native get();
    }

    property bool UseNormal
    {
        public native get();
    }

    property float Pearlescent
    {
        public native get();
    }

    public native int GetVmtPath(char[] buffer, int len);
}

methodmap CStickerKit
{
    public static native CStickerKit Get(int index);
    public static native int Count();

    public static native CStickerKit FindByID(int id);
    public static native CStickerKit FindByName(const char[] name);
    
    property int ID
    {
        public native get();
    }
    
    /**
     * Gets the item name.
     *
     * @param buffer        Destination string buffer.
     * @param len           Maximum length of output string buffer.
     *
     * @return              Returns length or 0 if failed.
     *
     * @error               CStickerKit == NULL.
     */
    public native int GetName(char[] buffer, int len);
    public native int GetDescriptionString(char[] buffer, int len);
    public native int GetsItemName(char[] buffer, int len);
    public native int GetMaterialPath(char[] buffer, int len);
    public native int GetMaterialPathNoDrips(char[] buffer, int len);
    public native int GetInventoryImage(char[] buffer, int len);

    property int EventID
    {
        public native get();
    }

    property int EventTeamID
    {
        public native get();
    }

    property int PlayerID
    {
        public native get();
    }

    property bool IsMaterialPathIsAbsolute
    {
        public native get();
    }

    property float RotateStart
    {
        public native get();
    }

    property float RotateEnd
    {
        public native get();
    }

    property float ScaleMin
    {
        public native get();
    }

    property float ScaleMax
    {
        public native get();
    }

    public native int GetIconURLSmall(char[] buffer, int len);
    public native int GetIconURLLarge(char[] buffer, int len);
}

methodmap CEconMusicDefinition
{
    public static native CEconMusicDefinition Get(int index);
    public static native int Count();

    public static native CEconMusicDefinition FindByName(const char[] name);
    public static native CEconMusicDefinition FindByID(int id);
    
    property int ID
    {
        public native get();
    }
    
    /**
     * Gets the item name.
     *
     * @param buffer      Destination string buffer.
     * @param len         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconMusicDefinition == NULL.
     */
    public native int GetName(char[] buffer, int len);
    
    public native int GetNameLocToken(char[] buffer, int len);
    public native int GetLocDescription(char[] buffer, int len);
    public native int GetPedestalDisplayModel(char[] buffer, int len);
    public native int GetInventoryImage(char[] buffer, int len);
}

methodmap CEconItemListEntry
{
    property CEconItemDefinition ItemDef
    {
        public native get();
    }

    property CEconLootListDefinition LootList
    {
        public native get();
    }

    property CPaintKit PaintKit
    {
        public native get();
    }

    property int PaintKitSeed
    {
        public native get();
    }

    property float PaintKitWear
    {
        public native get();
    }

    property CStickerKit StickerKit
    {
        public native get();
    }

    property CEconMusicDefinition MusicKit
    {
        public native get();
    }
}

methodmap CEconItemAttributeDefinition
{
    public static native CEconItemAttributeDefinition Get(int index);
    public static native int Count();

    public static native CEconItemAttributeDefinition FindByName(const char[] name);

    property int DefinitionIndex
    {
        public native get();
    }

    public native int GetDefinitionName(char[] buffer, int len);

    property bool IsHidden
    {
        public native get();
    }

    property bool IsWebSchemaOutputForced
    {
        public native get();
    }

    property bool IsStoredAsInteger
    {
        public native get();
    }

    property bool IsInstanceData
    {
        public native get();
    }

    property EAssetClassAttrExportRule_t AssetClassAttrExportRule
    {
        public native get();
    }

    property int AssetClassBucket
    {
        public native get();
    }

    property attrib_effect_types_t EffectType
    {
        public native get();
    }

    property int DescriptionFormat
    {
        public native get();
    }

    public native int GetDescription(char[] buffer, int len);
    public native int GetDescriptionTag(char[] buffer, int len);
    public native int GetArmoryDescription(char[] buffer, int len);

    property int Score
    {
        public native get();
    }

    public native int GetAttributeClass(char[] buffer, int len);
}

methodmap CEconItemSetDefinitionAttribute
{
    property int AttributeDefIndex
    {
        public native get();
    }

    property any Value
    {
        public native get();
    }
}

methodmap CEconItemSetDefinition
{
    public static native CEconItemSetDefinition Get(int index);
    public static native int Count();

    public static native CEconItemSetDefinition FindByName(const char[] name);
    
    public native int GetName(char[] buffer, int len);
    public native int GetLocalizedName(char[] buffer, int len);
    public native int GetLocalizedDescription(char[] buffer, int len);
    
    property int BundleItemDef
    {
        public native get();
    }

    property int IsCollection
    {
        public native get();
    }

    property int IsHiddenSet
    {
        public native get();
    }

    property int ItemCount
    {
        public native get();
    }

    public native CEconItemListEntry GetItem(int index);

    property CEconItemDefinition CraftReward
    {
        public native get();
    }

    property int AttributeCount
    {
        public native get();
    }

    public native CEconItemSetDefinitionAttribute GetAttribute(int index);
}

methodmap CEconItemRarityDefinition
{
    public static native CEconItemRarityDefinition Get(int index);
    public static native int Count();

    public static native CEconItemRarityDefinition FindByName(const char[] name);
    public static native CEconItemRarityDefinition FindByDBValue(int value);

    property int DBValue
    {
        public native get();
    }

    public native int GetName(char[] buffer, int len);
    public native int GetLocKey(char[] buffer, int len);
    public native int GetWepLocKey(char[] buffer, int len);
    public native int GetCharacterLocKey(char[] buffer, int len);
    public native int GetLootList(char[] buffer, int len);
    public native int GetRecycleLootList(char[] buffer, int len);
    public native int GetDropSound(char[] buffer, int len);

    property int AttribColor
    {
        public native get();
    }

    public native int GetNextRarity(char[] buffer, int len);
    
    property int WhiteCount
    {
        public native get();
    }
    
    property int BlackCount
    {
        public native get();
    }
    
    property int Weight
    {
        public native get();
    }
}

methodmap CEconItemQualityDefinition
{
    public static native CEconItemQualityDefinition Get(int index);
    public static native int Count();

    public static native CEconItemQualityDefinition FindByName(const char[] name);
    public static native CEconItemQualityDefinition FindByDBValue(int value);

    property int DBValue
    {
        public native get();
    }

    public native int GetName(char[] buffer, int len);
    
    property int Weight
    {
        public native get();
    }

    property bool RequiresExplicitMatches
    {
        public native get();
    }
    
    property bool CanSupportSet
    {
        public native get();
    }

    public native int GetHexColor(char[] buffer, int len);
}

methodmap CEconAdditionalDrop
{
    property float Chance
    {
        public native get();
    }

    property bool PremiumOnly
    {
        public native get();
    }

    property CEconLootListDefinition LootListDefinition
    {
        public native get();
    }
}

methodmap CEconLootListDefinition
{
    public static native CEconLootListDefinition Get(int index);
    public static native int Count();

    public static native CEconLootListDefinition FindByName(char[] buffer);
    
    public native int GetName(char[] buffer, int len);

    property int HeroID
    {
        public native get();
    }
    
    property bool PublicListContents
    {
        public native get();
    }
    
    property bool ContainsAutographedStickers
    {
        public native get();
    }
    
    property bool ContainsOrganizationsStickers
    {
        public native get();
    }
    
    property bool ContainsOrganizationsPatches
    {
        public native get();
    }
    
    property bool WillProduceStattrak
    {
        public native get();
    }
    
    property float TotalWeight
    {
        public native get();
    }
    
    property bool ServerList
    {
        public native get();
    }

    property int AdditionalDropCount
    {
        public native get();
    }

    public native CEconAdditionalDrop GetAdditionalDrop(int index);

    property int ItemCount
    {
        public native get();
    }

    public native CEconItemListEntry GetItem(int index);
}

public Extension __ext_EconAPI = 
{
    name = "EconAPI",
    file = "EconAPI.ext",
#if defined AUTOLOAD_EXTENSIONS
    autoload = 1,
#else
    autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
    required = 1,
#else
    required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_EconAPI_SetNTVOptional()
{
    // CEconItemDefinition
    MarkNativeAsOptional("CEconItemDefinition.Get");
    MarkNativeAsOptional("CEconItemDefinition.Count");
    MarkNativeAsOptional("CEconItemDefinition.FindByDefIndex");
    MarkNativeAsOptional("CEconItemDefinition.FindByName");
    MarkNativeAsOptional("CEconItemDefinition.IsEnabled.get");
    MarkNativeAsOptional("CEconItemDefinition.HasProperName.get");
    MarkNativeAsOptional("CEconItemDefinition.ShouldLoadOnDemand.get");
    MarkNativeAsOptional("CEconItemDefinition.HasBeenLoaded.get");
    MarkNativeAsOptional("CEconItemDefinition.HideBodyGroupsDeployedOnly.get");
    MarkNativeAsOptional("CEconItemDefinition.ShouldAttachToHands.get");
    MarkNativeAsOptional("CEconItemDefinition.ShouldAttachToHandsVMOnly.get");
    MarkNativeAsOptional("CEconItemDefinition.ShouldFlipViewModel.get");
    MarkNativeAsOptional("CEconItemDefinition.IsActingAsWearable.get");
    MarkNativeAsOptional("CEconItemDefinition.ShoulDisableStyleSelector.get");
    MarkNativeAsOptional("CEconItemDefinition.IsHidden.get");
    MarkNativeAsOptional("CEconItemDefinition.ShouldShowInArmory.get");
    MarkNativeAsOptional("CEconItemDefinition.IsBaseItem.get");
    MarkNativeAsOptional("CEconItemDefinition.IsDefaultSlotItem.get");
    MarkNativeAsOptional("CEconItemDefinition.IsImported.get");
    MarkNativeAsOptional("CEconItemDefinition.IsOnePerAccountCDKEY.get");
    MarkNativeAsOptional("CEconItemDefinition.IsPackBundle.get");
    MarkNativeAsOptional("CEconItemDefinition.IsPackItem.get");
    MarkNativeAsOptional("CEconItemDefinition.IsAllowedInMatch.get");
    MarkNativeAsOptional("CEconItemDefinition.IsPublicItem.get");
    MarkNativeAsOptional("CEconItemDefinition.IgnoreInCollectionView.get");

    MarkNativeAsOptional("CEconItemDefinition.MinItemLevel.get");
    MarkNativeAsOptional("CEconItemDefinition.MaxItemLevel.get");
    MarkNativeAsOptional("CEconItemDefinition.ItemRarity.get");
    MarkNativeAsOptional("CEconItemDefinition.ItemQuality.get");
    MarkNativeAsOptional("CEconItemDefinition.ForcedItemQuality.get");
    MarkNativeAsOptional("CEconItemDefinition.DefaultDropItemQuality.get");
    MarkNativeAsOptional("CEconItemDefinition.DefaultDropQuantity.get");
    MarkNativeAsOptional("CEconItemDefinition.PopularitySeed.get");
    MarkNativeAsOptional("CEconItemDefinition.DefinitionIndex.get");
    MarkNativeAsOptional("CEconItemDefinition.ItemTypeID.get");
    MarkNativeAsOptional("CEconItemDefinition.NumConcreteItems.get");
    MarkNativeAsOptional("CEconItemDefinition.NumSupportedStickerSlots.get");
    MarkNativeAsOptional("CEconItemDefinition.SoundMaterialID.get");
    MarkNativeAsOptional("CEconItemDefinition.ArmoryRemap.get");
    MarkNativeAsOptional("CEconItemDefinition.StoreRemap.get");
    MarkNativeAsOptional("CEconItemDefinition.DropType.get");
    MarkNativeAsOptional("CEconItemDefinition.SubType.get");
    MarkNativeAsOptional("CEconItemDefinition.ExpirationTime.get");
    MarkNativeAsOptional("CEconItemDefinition.DefCreationTime.get");
    MarkNativeAsOptional("CEconItemDefinition.EconItemType.get");
    MarkNativeAsOptional("CEconItemDefinition.Capabilities.get");
    MarkNativeAsOptional("CEconItemDefinition.EquipRegionMask.get");
    MarkNativeAsOptional("CEconItemDefinition.EquipRegionConflictMask.get");

    MarkNativeAsOptional("CEconItemDefinition.GetBaseName");
    MarkNativeAsOptional("CEconItemDefinition.GetTypeName");
    MarkNativeAsOptional("CEconItemDefinition.GetDescription");
    MarkNativeAsOptional("CEconItemDefinition.GetInventoryImage");
    MarkNativeAsOptional("CEconItemDefinition.GetIconDefaultImage");
    MarkNativeAsOptional("CEconItemDefinition.GetBrassModelOverride");
    MarkNativeAsOptional("CEconItemDefinition.GetZoomInSound");
    MarkNativeAsOptional("CEconItemDefinition.GetZoomOutSound");
    MarkNativeAsOptional("CEconItemDefinition.GetIconURLSmall");
    MarkNativeAsOptional("CEconItemDefinition.GetIconURLLarge");
    MarkNativeAsOptional("CEconItemDefinition.GetUnknown1");
    MarkNativeAsOptional("CEconItemDefinition.GetUnknown2");
    MarkNativeAsOptional("CEconItemDefinition.GetParticleFile");
    MarkNativeAsOptional("CEconItemDefinition.GetParticleSnapshotFile");
    MarkNativeAsOptional("CEconItemDefinition.GetLootListName");
    MarkNativeAsOptional("CEconItemDefinition.GetItemClassname");
    MarkNativeAsOptional("CEconItemDefinition.GetItemLogClassname");
    MarkNativeAsOptional("CEconItemDefinition.GetItemIconClassname");
    MarkNativeAsOptional("CEconItemDefinition.GetDefinitionName");
    MarkNativeAsOptional("CEconItemDefinition.GetArmoryDescription");
    MarkNativeAsOptional("CEconItemDefinition.GetClassToken");
    MarkNativeAsOptional("CEconItemDefinition.GetSlotToken");
    MarkNativeAsOptional("CEconItemDefinition.GetHolidayRestriction");

    MarkNativeAsOptional("CEconItemDefinition.UsedByTeam.get");
    MarkNativeAsOptional("CEconItemDefinition.GetLoadoutSlot");
    MarkNativeAsOptional("CEconItemDefinition.GetModel");

    // CPaintKit
    MarkNativeAsOptional("CPaintKit.Get");
    MarkNativeAsOptional("CPaintKit.Count");
    MarkNativeAsOptional("CPaintKit.FindByID");
    MarkNativeAsOptional("CPaintKit.FindByName");
    MarkNativeAsOptional("CPaintKit.ID.get");
    MarkNativeAsOptional("CPaintKit.GetName");
    MarkNativeAsOptional("CPaintKit.GetDescription");
    MarkNativeAsOptional("CPaintKit.GetDescriptionTag");
    MarkNativeAsOptional("CPaintKit.GetGetSameNameFamilyAggregate");
    MarkNativeAsOptional("CPaintKit.GetPattern");
    MarkNativeAsOptional("CPaintKit.GetNormal");
    MarkNativeAsOptional("CPaintKit.GetLogoMaterial");
    MarkNativeAsOptional("CPaintKit.Rarity.get");
    MarkNativeAsOptional("CPaintKit.Style.get");
    MarkNativeAsOptional("CPaintKit.GetRGBAColor");
    MarkNativeAsOptional("CPaintKit.GetRGBALogoColor");
    MarkNativeAsOptional("CPaintKit.DefaultWear.get");
    MarkNativeAsOptional("CPaintKit.MinWear.get");
    MarkNativeAsOptional("CPaintKit.MaxWear.get");
    MarkNativeAsOptional("CPaintKit.FixedSeed.get");
    MarkNativeAsOptional("CPaintKit.PhongExponent.get");
    MarkNativeAsOptional("CPaintKit.PhongAlbedoBoost.get");
    MarkNativeAsOptional("CPaintKit.PhongIntensity.get");
    MarkNativeAsOptional("CPaintKit.PatternScale.get");
    MarkNativeAsOptional("CPaintKit.PatternOffsetXStart.get");
    MarkNativeAsOptional("CPaintKit.PatternOffsetXEnd.get");
    MarkNativeAsOptional("CPaintKit.PatternOffsetYStart.get");
    MarkNativeAsOptional("CPaintKit.PatternOffsetYEnd.get");
    MarkNativeAsOptional("CPaintKit.PatternRotateStart.get");
    MarkNativeAsOptional("CPaintKit.PatternRotateEnd.get");
    MarkNativeAsOptional("CPaintKit.LogoScale.get");
    MarkNativeAsOptional("CPaintKit.LogoOffsetX.get");
    MarkNativeAsOptional("CPaintKit.LogoOffsetY.get");
    MarkNativeAsOptional("CPaintKit.LogoRotation.get");
    MarkNativeAsOptional("CPaintKit.IgnoreWeaponSizeScale.get");
    MarkNativeAsOptional("CPaintKit.ViewModelExponentOverrideSize.get");
    MarkNativeAsOptional("CPaintKit.OnlyFirstMaterial.get");
    MarkNativeAsOptional("CPaintKit.UseNormal.get");
    MarkNativeAsOptional("CPaintKit.Pearlescent.get");
    MarkNativeAsOptional("CPaintKit.GetVmtPath");

    // CStickerKit
    MarkNativeAsOptional("CStickerKit.Get");
    MarkNativeAsOptional("CStickerKit.Count");
    MarkNativeAsOptional("CStickerKit.FindByID");
    MarkNativeAsOptional("CStickerKit.FindByName");
    MarkNativeAsOptional("CStickerKit.ID.get");
    MarkNativeAsOptional("CStickerKit.GetName");
    MarkNativeAsOptional("CStickerKit.GetDescriptionString");
    MarkNativeAsOptional("CStickerKit.GetsItemName");
    MarkNativeAsOptional("CStickerKit.GetMaterialPath");
    MarkNativeAsOptional("CStickerKit.GetMaterialPathNoDrips");
    MarkNativeAsOptional("CStickerKit.GetInventoryImage");
    MarkNativeAsOptional("CStickerKit.EventID.get");
    MarkNativeAsOptional("CStickerKit.EventTeamID.get");
    MarkNativeAsOptional("CStickerKit.PlayerID.get");
    MarkNativeAsOptional("CStickerKit.IsMaterialPathIsAbsolute.get");
    MarkNativeAsOptional("CStickerKit.RotateStart.get");
    MarkNativeAsOptional("CStickerKit.RotateEnd.get");
    MarkNativeAsOptional("CStickerKit.ScaleMin.get");
    MarkNativeAsOptional("CStickerKit.ScaleMax.get");
    MarkNativeAsOptional("CStickerKit.GetIconURLSmall");
    MarkNativeAsOptional("CStickerKit.GetIconURLLarge");

    // CEconMusicDefinition
    MarkNativeAsOptional("CEconMusicDefinition.Get");
    MarkNativeAsOptional("CEconMusicDefinition.Count");
    MarkNativeAsOptional("CEconMusicDefinition.FindByName");
    MarkNativeAsOptional("CEconMusicDefinition.FindByID");
    MarkNativeAsOptional("CEconMusicDefinition.ID.get");
    MarkNativeAsOptional("CEconMusicDefinition.GetName");
    MarkNativeAsOptional("CEconMusicDefinition.GetNameLocToken");
    MarkNativeAsOptional("CEconMusicDefinition.GetLocDescription");
    MarkNativeAsOptional("CEconMusicDefinition.GetPedestalDisplayModel");
    MarkNativeAsOptional("CEconMusicDefinition.GetInventoryImage");
    
    // CEconItemListEntry
    MarkNativeAsOptional("CEconItemListEntry.ItemDef.get");
    MarkNativeAsOptional("CEconItemListEntry.LootList.get");
    MarkNativeAsOptional("CEconItemListEntry.PaintKit.get");
    MarkNativeAsOptional("CEconItemListEntry.PaintKitSeed.get");
    MarkNativeAsOptional("CEconItemListEntry.PaintKitWear.get");
    MarkNativeAsOptional("CEconItemListEntry.StickerKit.get");
    MarkNativeAsOptional("CEconItemListEntry.MusicKit.get");

    // CEconItemSetDefinitionAttribute
    MarkNativeAsOptional("CEconItemSetDefinitionAttribute.AttributeDefIndex.get");
    MarkNativeAsOptional("CEconItemSetDefinitionAttribute.Value.get");

    // CEconItemSetDefinition
    MarkNativeAsOptional("CEconItemSetDefinition.Get");
    MarkNativeAsOptional("CEconItemSetDefinition.Count");
    MarkNativeAsOptional("CEconItemSetDefinition.FindByName");
    MarkNativeAsOptional("CEconItemSetDefinition.GetName");
    MarkNativeAsOptional("CEconItemSetDefinition.GetLocalizedName");
    MarkNativeAsOptional("CEconItemSetDefinition.GetLocalizedDescription");
    MarkNativeAsOptional("CEconItemSetDefinition.BundleItemDef.get");
    MarkNativeAsOptional("CEconItemSetDefinition.IsCollection.get");
    MarkNativeAsOptional("CEconItemSetDefinition.IsHiddenSet.get");
    MarkNativeAsOptional("CEconItemSetDefinition.ItemCount.get");
    MarkNativeAsOptional("CEconItemSetDefinition.GetItem");
    MarkNativeAsOptional("CEconItemSetDefinition.CraftReward.get");
    MarkNativeAsOptional("CEconItemSetDefinition.AttributeCount.get");
    MarkNativeAsOptional("CEconItemSetDefinition.GetAttribute");
    
    // CEconItemRarityDefinition
    MarkNativeAsOptional("CEconItemRarityDefinition.Get");
    MarkNativeAsOptional("CEconItemRarityDefinition.Count");
    MarkNativeAsOptional("CEconItemRarityDefinition.FindByName");
    MarkNativeAsOptional("CEconItemRarityDefinition.FindByDBValue");
    MarkNativeAsOptional("CEconItemRarityDefinition.DBValue.get");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetName");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetLocKey");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetWepLocKey");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetCharacterLocKey");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetLootList");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetRecycleLootList");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetDropSound");
    MarkNativeAsOptional("CEconItemRarityDefinition.AttribColor.get");
    MarkNativeAsOptional("CEconItemRarityDefinition.GetNextRarity");
    MarkNativeAsOptional("CEconItemRarityDefinition.WhiteCount.get");
    MarkNativeAsOptional("CEconItemRarityDefinition.BlackCount.get");
    MarkNativeAsOptional("CEconItemRarityDefinition.Weight.get");
    
    // CEconItemQualityDefinition
    MarkNativeAsOptional("CEconItemQualityDefinition.Get");
    MarkNativeAsOptional("CEconItemQualityDefinition.Count");
    MarkNativeAsOptional("CEconItemQualityDefinition.FindByName");
    MarkNativeAsOptional("CEconItemQualityDefinition.FindByDBValue");
    MarkNativeAsOptional("CEconItemQualityDefinition.DBValue.get");
    MarkNativeAsOptional("CEconItemQualityDefinition.GetName");
    MarkNativeAsOptional("CEconItemQualityDefinition.Weight.get");
    MarkNativeAsOptional("CEconItemQualityDefinition.RequiresExplicitMatches.get");
    MarkNativeAsOptional("CEconItemQualityDefinition.CanSupportSet.get");
    MarkNativeAsOptional("CEconItemQualityDefinition.GetHexColor");

    // CEconAdditionalDrop
    MarkNativeAsOptional("CEconAdditionalDrop.Chance.get");
    MarkNativeAsOptional("CEconAdditionalDrop.PremiumOnly.get");
    MarkNativeAsOptional("CEconAdditionalDrop.LootListDefinition.get");

    // CEconLootListDefinition
    MarkNativeAsOptional("CEconLootListDefinition.Get");
    MarkNativeAsOptional("CEconLootListDefinition.Count");
    MarkNativeAsOptional("CEconLootListDefinition.FindByName");
    MarkNativeAsOptional("CEconLootListDefinition.GetName");
    MarkNativeAsOptional("CEconLootListDefinition.HeroID.get");
    MarkNativeAsOptional("CEconLootListDefinition.PublicListContents.get");
    MarkNativeAsOptional("CEconLootListDefinition.ContainsAutographedStickers.get");
    MarkNativeAsOptional("CEconLootListDefinition.ContainsOrganizationsStickers.get");
    MarkNativeAsOptional("CEconLootListDefinition.ContainsOrganizationsPatches.get");
    MarkNativeAsOptional("CEconLootListDefinition.WillProduceStattrak.get");
    MarkNativeAsOptional("CEconLootListDefinition.TotalWeight.get");
    MarkNativeAsOptional("CEconLootListDefinition.ServerList.get");
    MarkNativeAsOptional("CEconLootListDefinition.AdditionalDropCount.get");
    MarkNativeAsOptional("CEconLootListDefinition.GetAdditionalDrop");
    MarkNativeAsOptional("CEconLootListDefinition.ItemCount.get");
    MarkNativeAsOptional("CEconLootListDefinition.GetItem");

    // CEconItemAttributeDefinition
    MarkNativeAsOptional("CEconItemAttributeDefinition.Get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.Count");
    MarkNativeAsOptional("CEconItemAttributeDefinition.FindByDefinitionName");
    MarkNativeAsOptional("CEconItemAttributeDefinition.DefinitionIndex.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.GetDefinitionName");
    MarkNativeAsOptional("CEconItemAttributeDefinition.IsHidden.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.IsWebSchemaOutputForced.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.IsStoredAsInteger.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.IsInstanceData.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.AssetClassAttrExportRule.get"
    MarkNativeAsOptional("CEconItemAttributeDefinition.AssetClassBucket.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.EffectType.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.DescriptionFormat.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.GetDescription");
    MarkNativeAsOptional("CEconItemAttributeDefinition.GetDescriptionTag");
    MarkNativeAsOptional("CEconItemAttributeDefinition.GetArmoryDescription");
    MarkNativeAsOptional("CEconItemAttributeDefinition.Score.get");
    MarkNativeAsOptional("CEconItemAttributeDefinition.GetAttributeClass");
}
#endif