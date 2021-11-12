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

#if defined _EconAPI_included
  #endinput
#endif
#define _EconAPI_included


enum EconAPI_ModelType
{
    ViewModel = 0,
    WorldModel,
    DroppedModel
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
    public static native CEconItemDefinition Get(int index);
    public static native int Count();

    public static native CEconItemDefinition FindByName(const char[] name);
    public static native CEconItemDefinition FindByDefIndex(int def_index);

    /**
     * Gets the definition index.
     *
     * @return             Returns definition index.
     *
     * @error              CEconItemDefinition == NULL.
     */
    property int DefinitionIndex
    {
        public native get();
    }

    /**
     * Gets the item definition name.
     *
     * @param buffer      Destination string buffer.
     * @param len         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetDefinitionName(char[] buffer, int len);

    /**
     * Gets LoadoutSlot.
     *
     * @param iTeam        Team index or 0 if independently.
     *
     * @return             Returns loadout slot index.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetLoadoutSlot(int iTeam = 0);

    /**
     * Gets the used by team.
     *
     * @return             Returns team index or 0 if both team.
     */
    property int UsedByTeam
    {
        public native get();
    }

    /**
     * Gets the amount slot for stickers.
     * @note On agents, places are counted according
     *       to patch locations on the model.
     *
     * @return             Returns sticker slot count.
     *
     * @error              CEconItemDefinition == NULL.
     */
    property int NumSupportedStickerSlots
    {
        public native get();
    }

    /**
     * Gets the item econ image path in resource/flash/.
     * Example: "econ/weapons/base_weapons/weapon_knife"
     *
     * @note Add ".png" in the end of string for full formatting.
     *
     * @param buffer      Destination string buffer.
     * @param len         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetEconImage(char[] buffer, int len);

    /**
     * Gets the item model path.
     *
     * @param iModelType   Model type.
     * @param buffer      Destination string buffer.
     * @param len         Maximum length of output string buffer.
     *                     Max size PLATFORM_MAX_PATH.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL or model type invalid.
     */
    public native int GetModel(EconAPI_ModelType iModelType, char[] buffer, int len);
}

methodmap CPaintKit
{
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
    public native int GetPattern(char[] buffer, int len);

    property int ID
    {
        public native get();
    }

    property int Rarity
    {
        public native get();
    }
    
    property int Style
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

    property float PatternScale
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

methodmap CEconItemSetItem
{
    property CEconItemDefinition ItemDef
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

    public native CEconItemSetItem GetItem(int index);
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

methodmap CEconLootListDefinition
{
    public static native CEconLootListDefinition Get(int index);
    public static native int Count();

    public native CEconLootListDefinition FindByName(char[] buffer);
    
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
    MarkNativeAsOptional("CEconItemDefinition.DefinitionIndex.get");
    MarkNativeAsOptional("CEconItemDefinition.GetDefinitionName");
    MarkNativeAsOptional("CEconItemDefinition.GetLoadoutSlot");
    MarkNativeAsOptional("CEconItemDefinition.UsedByTeam.get");
    MarkNativeAsOptional("CEconItemDefinition.NumSupportedStickerSlots.get");
    MarkNativeAsOptional("CEconItemDefinition.GetEconImage");
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
    MarkNativeAsOptional("CPaintKit.GetPattern");
    MarkNativeAsOptional("CPaintKit.Rarity.get");
    MarkNativeAsOptional("CPaintKit.Style.get");
    MarkNativeAsOptional("CPaintKit.MinWear.get");
    MarkNativeAsOptional("CPaintKit.MaxWear.get");
    MarkNativeAsOptional("CPaintKit.PatternScale.get");
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
    
    // CEconItemSetItem
    MarkNativeAsOptional("CEconItemSetItem.ItemDef.get");
    MarkNativeAsOptional("CEconItemSetItem.PaintKit.get");
    MarkNativeAsOptional("CEconItemSetItem.PaintKitSeed.get");
    MarkNativeAsOptional("CEconItemSetItem.PaintKitWear.get");
    MarkNativeAsOptional("CEconItemSetItem.StickerKit.get");
    MarkNativeAsOptional("CEconItemSetItem.MusicKit.get");

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
}
#endif