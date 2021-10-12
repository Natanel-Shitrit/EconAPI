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

enum CEconMusicDefinition
{
    CEconMusicDefinition_NULL = 0
}

enum CEconItemSetDefinition
{
    CEconItemSetDefinition_NULL = 0
}

methodmap CEconItemDefinition	// < Address
{
    // CEconItemDefinition is not Handle, CloseHandle() - NOT NEEDED !!!!!!!!!!!!!!!!!!!!!
    // Always check, if not wounded CEconItemDefinition - NULL ( if(pItemDefinition) ) !!!!!!!!!!!!!!!!!!!!!

    /*
    // such a shame
    property int ItemCount
    {
        public static native get();
    }
    */
    
    public static native int ItemCount();
    public static native CEconItemDefinition FindByName(const char[] name);
    public static native CEconItemDefinition FindByIndex(int def_index);

    /**
     * Gets the definition index.
     *
     * @return             Returns definition index.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetDefinitionIndex();

    /**
     * Gets the item definition name.
     *
     * @param sBuffer      Destination string buffer.
     * @param iLen         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetDefinitionName(char[] sBuffer, int iLen);

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
    public native int GetUsedByTeam();

    /**
     * Gets the amount slot for stickers.
     * @note On agents, places are counted according
     *       to patch locations on the model.
     *
     * @return             Returns sticker slot count.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetNumSupportedStickerSlots();

    /**
     * Gets the item econ image path in resource/flash/.
     * Example: "econ/weapons/base_weapons/weapon_knife"
     *
     * @note Add ".png" in the end of string for full formatting.
     *
     * @param sBuffer      Destination string buffer.
     * @param iLen         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL.
     */
    public native int GetEconImage(char[] sBuffer, int iLen);

    /**
     * Gets the item model path.
     *
     * @param iModelType   Model type.
     * @param sBuffer      Destination string buffer.
     * @param iLen         Maximum length of output string buffer.
     *                     Max size PLATFORM_MAX_PATH.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconItemDefinition == NULL or model type invalid.
     */
    public native int GetModel(EconAPI_ModelType iModelType, char[] sBuffer, int iLen);
}

methodmap CPaintKit	// < Address
{
    // CPaintKit is not Handle, CloseHandle() - NOT NEEDED !!!!!!!!!!!!!!!!!!!!!
    // Always check, if not wounded CPaintKit - NULL ( if(pPaintKit) ) !!!!!!!!!!!!!!!!!!!!!
    
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

    property float Rarity
    {
        public native get();
    }
    
    property float Style
    {
        public native get();
    }
    
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

    public native int GetVmtPath(char[] buffer, int len);
}

methodmap CEconMusicDefinition	// < Address
{
    // CEconMusicDefinition is not Handle, CloseHandle() - NOT NEEDED !!!!!!!!!!!!!!!!!!!!!
    // Always check, if not wounded CEconMusicDefinition - NULL ( if(pMusicDefinition) ) !!!!!!!!!!!!!!!!!!!!!
    
    public static native CEconMusicDefinition FindByName(const char[] name);
    public static native CEconMusicDefinition FindByID(int id);
    
    property int ID
    {
        public native get();
    }
    
    /**
     * Gets the item name.
     *
     * @param sBuffer      Destination string buffer.
     * @param iLen         Maximum length of output string buffer.
     *
     * @return             Returns length or 0 if failed.
     *
     * @error              CEconMusicDefinition == NULL.
     */
    public native int GetName(char[] sBuffer, int iLen);
    
    public native int GetNameLocToken(char[] sBuffer, int iLen);
    public native int GetLocDescription(char[] sBuffer, int iLen);
    public native int GetPedestalDisplayModel(char[] sBuffer, int iLen);
    public native int GetInventoryImage(char[] sBuffer, int iLen);
}

methodmap CEconItemSetDefinition	// < Address
{
    // CEconItemSetDefinition is not Handle, CloseHandle() - NOT NEEDED !!!!!!!!!!!!!!!!!!!!!
    // Always check, if not wounded CEconItemSetDefinition - NULL ( if(pMusicDefinition) ) !!!!!!!!!!!!!!!!!!!!!
    
    public static native CEconItemSetDefinition FindByName(const char[] name);
    
    public native int GetLocalizedName(char[] sBuffer, int iLen);
    //public native int GetUnlocalizedName(char[] sBuffer, int iLen);
    public native int GetLocalizedDescription(char[] sBuffer, int iLen);
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
    MarkNativeAsOptional("CEconItemDefinition.ItemCount.get");
    MarkNativeAsOptional("CEconItemDefinition.FindByIndex");
    MarkNativeAsOptional("CEconItemDefinition.FindByName");
    MarkNativeAsOptional("CEconItemDefinition.GetDefinitionIndex");
    MarkNativeAsOptional("CEconItemDefinition.GetDefinitionName");
    MarkNativeAsOptional("CEconItemDefinition.GetLoadoutSlot");
    MarkNativeAsOptional("CEconItemDefinition.GetUsedByTeam");
    MarkNativeAsOptional("CEconItemDefinition.GetNumSupportedStickerSlots");
    MarkNativeAsOptional("CEconItemDefinition.GetEconImage");
    MarkNativeAsOptional("CEconItemDefinition.GetModel");

    // CPaintKit
    MarkNativeAsOptional("CPaintKit.FindByID");
    MarkNativeAsOptional("CPaintKit.FindByName");
    MarkNativeAsOptional("CPaintKit.ID.get");
    MarkNativeAsOptional("CPaintKit.GetName");
    MarkNativeAsOptional("CPaintKit.GetDescription");
    MarkNativeAsOptional("CPaintKit.GetDescriptionTag");
    MarkNativeAsOptional("CPaintKit.GetPattern");
    MarkNativeAsOptional("CPaintKit.Rarity.get");
    MarkNativeAsOptional("CPaintKit.Style.get");
    MarkNativeAsOptional("CPaintKit.DefaultWear.get");
    MarkNativeAsOptional("CPaintKit.MinWear.get");
    MarkNativeAsOptional("CPaintKit.MaxWear.get");
    MarkNativeAsOptional("CPaintKit.GetVmtPath");

    // CEconMusicDefinition
    MarkNativeAsOptional("CEconMusicDefinition.FindByName");
    MarkNativeAsOptional("CEconMusicDefinition.FindByID");
    MarkNativeAsOptional("CEconMusicDefinition.ID.get");
    MarkNativeAsOptional("CEconMusicDefinition.GetName");
    MarkNativeAsOptional("CEconMusicDefinition.GetNameLocToken");
    MarkNativeAsOptional("CEconMusicDefinition.GetLocDescription");
    MarkNativeAsOptional("CEconMusicDefinition.GetPedestalDisplayModel");
    MarkNativeAsOptional("CEconMusicDefinition.GetInventoryImage");
    
    // CEconItemSetDefinition
    MarkNativeAsOptional("CEconItemSetDefinition.FindByName");
    MarkNativeAsOptional("CEconItemSetDefinition.GetLocalizedName");
    MarkNativeAsOptional("CEconItemSetDefinition.GetLocalizedDescription");
}
#endif