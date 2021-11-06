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
#include "utlstring.h"
#include "string_t.h"

typedef uint32 RTime32;
typedef uint16 item_definition_index_t;
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
	const char *GetInventoryImage( void ) const	        { return m_strInventoryImage.Get(); }

    int         GetEventID( void ) const                { return m_nEventID; }
    int         GetEventTeamID( void ) const            { return m_nEventTeamID; }
    int         GetPlayerID( void ) const               { return m_nPlayerID; }

    bool        IsMaterialPathIsAbsolute( void ) const  { return bMaterialPathIsAbsolute; }

    float       GetScaleMin( void ) const               { return flScaleMin; }
    float       GetScaleMax( void ) const               { return flScaleMax; }

    float       GetWearMin( void ) const                { return flWearMin; }
    float       GetWearMax( void ) const                { return flWearMax; }

	const char *GetIconURLSmall() const			        { return m_sIconURLSmall.Get(); }
	const char *GetIconURLLarge() const			        { return m_sIconURLLarge.Get(); }

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
    const char* GetName( void ) const                    { return m_pszName; }
    const char* GetLocKey( void ) const                  { return m_pszLocalizedName; }
    const char* GetUnlocalizedName( void ) const         { return m_pszUnlocalizedName; }
    const char* GetLocDescription( void ) const          { return m_pszLocalizedDescription; }
    int            GetBundle( void ) const                  { return m_iBundleItemDef; }
    int            GetItemCount( void ) const               { return m_ItemEntries.Count(); }
    int            GetItemDef( int iIndex ) const           { return m_ItemEntries[iIndex].m_nItemDef; }
    int            GetItemPaintKit( int iIndex ) const      { return m_ItemEntries[iIndex].m_nPaintKit; }
    item_definition_index_t GetCraftReward( void ) const { return m_nCraftReward; }
private: // Not used, just for offset.
    void* m_pVTable;
public: // Used.
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
    CEconItemDefinition* GetItemDefinitionByName(const char* pszDefName);
    CEconItemDefinition* GetItemDefinitionByDefIndex(uint16_t iItemIndex);

    // CPaintKit
    CUtlMap<int, CPaintKit*, int, CDefLess<int>>* GetPaintKitMap();
    CPaintKit* GetPaintKitByName(const char* pszDefName);
    CPaintKit* GetPaintKitByID(uint32 iItemIndex);

    // CStickerKit
    CUtlMap<int, CStickerKit*, int, CDefLess<int>>* GetStickerKitMap();
    CStickerKit* GetStickerKitByName(const char* pszDefName);
    CStickerKit* GetStickerKitByID(uint32 iID);

    // CEconMusicDefinition
    CUtlMap<int, CEconMusicDefinition*, int, CDefLess<int>>* GetMusicDefinitionMap();
    CEconMusicDefinition* GetMusicDefinitionByName(const char* pszDefName);
    CEconMusicDefinition* GetMusicDefinitionByID(uint32 iItemIndex);

    // CEconItemSetDefinition
    CUtlMap<const char*, CEconItemSetDefinition, int>* GetItemSetsMap();
    CEconItemSetDefinition* GetItemSetByName(const char* pszName);

    // CEconItemRarityDefinition
    CUtlMap<int, CEconItemRarityDefinition, int, CDefLess<int>>* GetItemRarityDefinitionMap();
    CEconItemRarityDefinition* GetItemRarityDefinitionByName(const char* pszName);
    CEconItemRarityDefinition* GetItemRarityDefinitionByDBValue(uint32 iValue);

    // CEconItemQualityDefinition
    CUtlMap<int, CEconItemQualityDefinition, int, CDefLess<int>>* GetItemQualityDefinitionMap();
    CEconItemQualityDefinition* GetItemQualityDefinitionByName(const char* pszName);
    CEconItemQualityDefinition* GetItemQualityDefinitionByDBValue(uint32 iValue);
};

extern CEconItemSchema* g_pCEconItemSchema;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CLASSES_H_