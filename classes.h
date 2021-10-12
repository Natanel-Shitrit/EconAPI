#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_

#include "utlhashmaplarge.h"
#include "utlstring.h"
#include "string_t.h"

typedef uint32 RTime32;
typedef uint16 item_definition_index_t;
typedef uint32 attrib_value_t;

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
    float       GetWearDefault( void ) const        { return flWearDefault; }
    float       GetWearRemapMin( void ) const       { return flWearRemapMin; }
    float       GetWearRemapMax( void ) const       { return flWearRemapMax; }
    const char *GetVmtPath( void ) const            { return sVmtPath.Get(); }

public:
    enum { NUM_COLORS = 4 };

    // Generic fields
    int nID;
    CUtlString sName;
    CUtlString sDescriptionString;
    CUtlString sDescriptionTag;
    
    // (Generally) Weapon paint kit fields
    // Note that some fields may affect item generation for other paint kit types;
    // in particular the wear settings.
    CUtlString sPattern;
    CUtlString sLogoMaterial;
    bool bBaseDiffuseOverride;
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
    bool bIgnoreWeaponSizeScale;
    int nViewModelExponentOverrideSize;
    bool bOnlyFirstMaterial;

    // Character paint kit fields
    CUtlString sVmtPath;
    KeyValues* kvVmtOverrides;
};

class CEconMusicDefinition
{
public:
    uint32      GetID( void ) const                     { return nID; }
    const char *GetName( void ) const                   { return m_strName.Get(); }
    const char *GetNameLocToken( void ) const           { return m_strNameLocToken.Get(); }
    const char *GetDescription( void ) const            { return m_strLocDescription.Get(); }
    const char *GetInventoryImage( void ) const         { return m_strInventoryImage.Get(); }
    const char *GetPedestalDisplayModel( void ) const   { return m_strPedestalDisplayModel.Get(); }

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
private:
    void* m_pVTable;
public:
    const char            *m_pszName;    //    e.g. "set_dust"
    // const char            *m_pszSetName;    //    unused
    const char            *m_pszLocalizedName;
    const char            *m_pszUnlocalizedName;
    const char            *m_pszLocalizedDescription;
    CUtlVector<item_list_entry_t> m_ItemEntries;
    int                    m_iBundleItemDef;    // Item def of the store bundle for this set, if any
    bool                m_bIsCollection;
    bool                m_bIsHiddenSet;        // If true, this set and any bonuses will only be visible if the whole set is equipped.
    item_definition_index_t    m_nCraftReward;

    struct itemset_attrib_t
    {
        int        m_iAttribDefIndex;
        attrib_value_t    m_valValue;
    };
    CUtlVector<itemset_attrib_t>    m_iAttributes;
};

class CEconItemSchema
{
public:
    static void* operator new(size_t) throw();
    static void operator delete(void*) { };

    // CEconItemDefinition
    CUtlHashMapLarge<int, CEconItemDefinition*>* GetItemDefinitionMap();
    CEconItemDefinition* GetItemDefinitionByName(const char* pszDefName);
    CEconItemDefinition* GetItemDefinitionByDefIndex(uint16_t iItemIndex);

    // CPaintKit
    CUtlMap<int, CPaintKit*, int, CDefLess<int>>* GetPaintKitMap();
    CPaintKit* GetPaintKitByName(const char* pszDefName);
    CPaintKit* GetPaintKitByID(uint32 iItemIndex);

    // CEconMusicDefinition
    CUtlMap<int, CEconMusicDefinition*, int, CDefLess<int>>* GetMusicDefinitionMap();
    CEconMusicDefinition* GetMusicDefinitionByName(const char* pszDefName);
    CEconMusicDefinition* GetMusicDefinitionByID(uint32 iItemIndex);

    // CEconItemSetDefinition
    CUtlMap<const char*, CEconItemSetDefinition, int>* GetItemSetsMap();
    CEconItemSetDefinition* GetItemSetByName(const char* pszName);
};

extern CEconItemSchema* g_pCEconItemSchema;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_