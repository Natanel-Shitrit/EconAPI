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

#include "extension.h"
#include "classes.h"

void* CEconItemSchema::operator new(size_t) throw()
{
    //Called once, no static needed
    CEconItemSchema* (*GetItemSchema)(void);

    if (!g_pGameConf[GameConf_CSST]->GetMemSig("GetItemSchema", (void**)&GetItemSchema) || !GetItemSchema)
    {
        smutils->LogError(myself, "Failed to get GetItemSchema function.");

        return nullptr;
    }

#ifdef PLATFORM_WINDOWS
    return GetItemSchema() + sizeof(void*);
#else
    return GetItemSchema();
#endif
};

// CEconItemDefinition
CUtlHashMapLarge<int, CEconItemDefinition*>* CEconItemSchema::GetItemDefinitionMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapItems", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapItems offset.");

        return nullptr;
    }
    
    return (CUtlHashMapLarge<int, CEconItemDefinition*>*)((intptr_t)this + offset);
}

CEconItemDefinition* CEconItemSchema::GetItemDefinitionByName(const char* pszDefName)
{
    auto pMapItemDef = GetItemDefinitionMap();

    if (pMapItemDef)
    {
        FOR_EACH_MAP_FAST(*pMapItemDef, i)
        {
            if (!strcmp(pszDefName, pMapItemDef->Element(i)->GetDefinitionName()))
            {
                return pMapItemDef->Element(i);
            }
        }
    }

    return nullptr;
}

CEconItemDefinition* CEconItemSchema::GetItemDefinitionByDefIndex(uint16_t iItemIndex)
{
    auto pMapItemDef = GetItemDefinitionMap();

    if (pMapItemDef)
    {
        int iIndex = pMapItemDef->Find(iItemIndex);
        
        if (pMapItemDef->IsValidIndex(iIndex))
        {
            return pMapItemDef->Element(iIndex);
        }
    }

    return nullptr;
}

int CEconItemDefinition::GetLoadoutSlot(int iTeam)
{
    static int (VCallingConvention* GetLoadoutSlot)(void*, int) = nullptr;

    if (GetLoadoutSlot == nullptr && !g_pGameConf[GameConf_EconAPI]->GetMemSig("CCStrike15ItemDefinition::GetLoadoutSlot", (void**)&GetLoadoutSlot) || !GetLoadoutSlot)
    {
        smutils->LogError(myself, "Failed to get CCStrike15ItemDefinition::GetLoadoutSlot function.");

        return -1;
    }

    return GetLoadoutSlot(this, iTeam);
}

int CEconItemDefinition::GetUsedByTeam()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CCStrike15ItemDefinition::m_vbClassUsability", &offset))
    {
        smutils->LogError(myself, "Failed to get CCStrike15ItemDefinition::m_vbClassUsability offset.");

        return -1;
    }

    CBitVec<4>* pClassUsability = (CBitVec<4>*)((intptr_t)this + offset);
    
    if (pClassUsability->IsBitSet(2) && pClassUsability->IsBitSet(3))
    {
        return 0;
    }

    if (pClassUsability->IsBitSet(3))
    {
        return 3;
    }

    if (pClassUsability->IsBitSet(2))
    {
        return 2;
    }
    
    return 0;
}

int CEconItemDefinition::GetNumSupportedStickerSlots()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::GetNumSupportedStickerSlots", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::GetNumSupportedStickerSlots offset.");

        return -1;
    }

    return ((int(VCallingConvention*)(void*))(*(void***)this)[offset])(this);
}

const char* CEconItemDefinition::GetInventoryImage()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::GetInventoryImage", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::GetInventoryImage offset.");

        return nullptr;
    }

    return ((const char*(VCallingConvention*)(void*))(*(void***)this)[offset])(this);
}

const char* CEconItemDefinition::GetBasePlayerDisplayModel()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::GetBasePlayerDisplayModel", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::GetBasePlayerDisplayModel offset.");

        return nullptr;
    }

    return ((const char*(VCallingConvention*)(void*))(*(void***)this)[offset])(this);
}

const char* CEconItemDefinition::GetWorldDisplayModel()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::GetWorldDisplayModel", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::GetWorldDisplayModel offset.");

        return nullptr;
    }

    return ((const char*(VCallingConvention*)(void*))(*(void***)this)[offset])(this);
}

const char* CEconItemDefinition::GetWorldDroppedModel()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::GetWorldDroppedModel", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::GetWorldDroppedModel offset.");

        return nullptr;
    }

    return ((const char*(VCallingConvention*)(void*))(*(void***)this)[offset])(this);
}

const char* CEconItemDefinition::GetDefinitionName()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemDefinition::m_pszDefinitionName", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemDefinition::m_pszDefinitionName offset.");

        return nullptr;
    }

    return *(const char**)((intptr_t)this + offset);
}


// CPaintKit
CUtlMap<int, CPaintKit*, int, CDefLess<int>>* CEconItemSchema::GetPaintKitMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapPaintKits", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapPaintKits offset.");

        return nullptr;
    }
    
    return (CUtlMap<int, CPaintKit*, int, CDefLess<int>>*)((intptr_t)this + offset);
}

CPaintKit* CEconItemSchema::GetPaintKitByName(const char* pszName)
{
    auto pPaintKitMap = GetPaintKitMap();

    if (pPaintKitMap)
    {
        FOR_EACH_MAP_FAST(*pPaintKitMap, i)
        {
            if (!strcmp(pszName, pPaintKitMap->Element(i)->GetName()))
            {
                return pPaintKitMap->Element(i);
            }
        }
    }

    return nullptr;
}

CPaintKit* CEconItemSchema::GetPaintKitByID(uint32 nID)
{
    auto pPaintKitMap = GetPaintKitMap();

    if (pPaintKitMap)
    {
        int iIndex = pPaintKitMap->Find(nID);
        
        if (pPaintKitMap->IsValidIndex(iIndex))
        {
            return pPaintKitMap->Element(iIndex);
        }
    }

    return nullptr;
}

// CStickerKit
CUtlMap<int, CStickerKit*, int, CDefLess<int>>* CEconItemSchema::GetStickerKitMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapStickerKits", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapStickerKits offset.");

        return nullptr;
    }
    
    return (CUtlMap<int, CStickerKit*, int, CDefLess<int>>*)((intptr_t)this + offset);
}

CStickerKit* CEconItemSchema::GetStickerKitByName(const char* pszName)
{
    auto pStickerKitMap = GetStickerKitMap();

    if (pStickerKitMap)
    {
        FOR_EACH_MAP_FAST(*pStickerKitMap, i)
        {
            if (!strcmp(pszName, pStickerKitMap->Element(i)->GetName()))
            {
                return pStickerKitMap->Element(i);
            }
        }
    }

    return nullptr;
}

CStickerKit* CEconItemSchema::GetStickerKitByID(uint32 nID)
{
    auto pStickerKitMap = GetStickerKitMap();

    if (pStickerKitMap)
    {
        int iIndex = pStickerKitMap->Find(nID);
        
        if (pStickerKitMap->IsValidIndex(iIndex))
        {
            return pStickerKitMap->Element(iIndex);
        }
    }

    return nullptr;
}

// CEconMusicDefinition
CUtlMap<int, CEconMusicDefinition*, int, CDefLess<int>>* CEconItemSchema::GetMusicDefinitionMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapMusicDefs", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapMusicDefs offset.");

        return nullptr;
    }
    
    return (CUtlMap<int, CEconMusicDefinition*, int, CDefLess<int>>*)((intptr_t)this + offset);
}

CEconMusicDefinition* CEconItemSchema::GetMusicDefinitionByName(const char* pszName)
{
    auto pMapMusicDef = GetMusicDefinitionMap();

    if (pMapMusicDef)
    {
        FOR_EACH_MAP_FAST(*pMapMusicDef, i)
        {
            if (!strcmp(pszName, pMapMusicDef->Element(i)->GetName()))
            {
                return pMapMusicDef->Element(i);
            }
        }
    }

    return nullptr;
}

CEconMusicDefinition* CEconItemSchema::GetMusicDefinitionByID(uint32 nID)
{
    auto pMapMusicDef = GetMusicDefinitionMap();

    if (pMapMusicDef)
    {
        int iIndex = pMapMusicDef->Find(nID);
        
        if (pMapMusicDef->IsValidIndex(iIndex))
        {
            return pMapMusicDef->Element(iIndex);
        }
    }

    return nullptr;
}

// CEconItemSetDefinition
CUtlMap<const char*, CEconItemSetDefinition, int>* CEconItemSchema::GetItemSetsMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapItemSets", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapItemSets offset.");

        return nullptr;
    }
    
    return (CUtlMap<const char*, CEconItemSetDefinition, int>*)((intptr_t)this + offset);
}

CEconItemSetDefinition* CEconItemSchema::GetItemSetByName(const char* pszName)
{
    auto pMapItemSet = GetItemSetsMap();

    if (pMapItemSet)
    {
        FOR_EACH_MAP_FAST(*pMapItemSet, i)
        {
            if (!strcmp(pszName, pMapItemSet->Element(i).GetName()))
            {
                return &pMapItemSet->Element(i);
            }
        }
    }

    return nullptr;
}

// CEconItemRarityDefinition
CUtlMap<int, CEconItemRarityDefinition, int, CDefLess<int>>* CEconItemSchema::GetItemRarityDefinitionMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapRarities", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapRarities offset.");

        return nullptr;
    }
    
    return (CUtlMap<int, CEconItemRarityDefinition, int, CDefLess<int>>*)((intptr_t)this + offset);
}

CEconItemRarityDefinition* CEconItemSchema::GetItemRarityDefinitionByName(const char* pszName)
{
    auto pItemRarityDefinitionMap = GetItemRarityDefinitionMap();

    if (pItemRarityDefinitionMap)
    {
        FOR_EACH_MAP_FAST(*pItemRarityDefinitionMap, i)
        {
            if (!strcmp(pszName, pItemRarityDefinitionMap->Element(i).GetName()))
            {
                return &pItemRarityDefinitionMap->Element(i);
            }
        }
    }

    return nullptr;
}

CEconItemRarityDefinition* CEconItemSchema::GetItemRarityDefinitionByDBValue(uint32 iValue)
{
    auto pItemRarityDefinitionMap = GetItemRarityDefinitionMap();

    if (pItemRarityDefinitionMap)
    {
        int iIndex = pItemRarityDefinitionMap->Find(iValue);
        
        if (pItemRarityDefinitionMap->IsValidIndex(iIndex))
        {
            return &pItemRarityDefinitionMap->Element(iIndex);
        }
    }

    return nullptr;
}

// CEconItemQualityDefinition
CUtlMap<int, CEconItemQualityDefinition, int, CDefLess<int>>* CEconItemSchema::GetItemQualityDefinitionMap()
{
    static int offset = -1;

    if (offset == -1 && !g_pGameConf[GameConf_EconAPI]->GetOffset("CEconItemSchema::m_mapQualities", &offset))
    {
        smutils->LogError(myself, "Failed to get CEconItemSchema::m_mapQualities offset.");

        return nullptr;
    }
    
    return (CUtlMap<int, CEconItemQualityDefinition, int, CDefLess<int>>*)((intptr_t)this + offset);
}

CEconItemQualityDefinition* CEconItemSchema::GetItemQualityDefinitionByName(const char* pszName)
{
    auto pItemQualityDefinitionMap = GetItemQualityDefinitionMap();

    if (pItemQualityDefinitionMap)
    {
        FOR_EACH_MAP_FAST(*pItemQualityDefinitionMap, i)
        {
            if (!strcmp(pszName, pItemQualityDefinitionMap->Element(i).GetName()))
            {
                return &pItemQualityDefinitionMap->Element(i);
            }
        }
    }

    return nullptr;
}

CEconItemQualityDefinition* CEconItemSchema::GetItemQualityDefinitionByDBValue(uint32 iValue)
{
    auto pItemQualityDefinitionMap = GetItemQualityDefinitionMap();

    if (pItemQualityDefinitionMap)
    {
        int iIndex = pItemQualityDefinitionMap->Find(iValue);
        
        if (pItemQualityDefinitionMap->IsValidIndex(iIndex))
        {
            return &pItemQualityDefinitionMap->Element(iIndex);
        }
    }

    return nullptr;
}