/**
 * EconAPI
 * Copyright (C) 2021 Natanel 'LuqS' Shitrit
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
#include "natives.h"
#include "classes.h"

// CEconItemDefinition //
static cell_t CEconItemDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
        
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemDefinition(params[1]));
}

static cell_t CEconItemDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemDefMap = g_pCEconItemSchema->GetItemDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemDefMap);
    
    return pItemDefMap->Count();
}

static cell_t CEconItemDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemDefinitionByName(strSource));
}

static cell_t CEconItemDefinition_FindByDefIndex(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemDefinitionByDefIndex(params[1]));
}

static cell_t CEconItemDefinition_GetDefinitionIndex(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetDefinitionIndex();
}

static cell_t CEconItemDefinition_GetItemRarity(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemRarityDefinition(pItemDefinition->GetItemRarity()));
}

static cell_t CEconItemDefinition_GetItemQuality(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemQualityDefinition(pItemDefinition->GetItemQuality()));
}

static cell_t CEconItemDefinition_GetForcedItemQuality(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemQualityDefinition(pItemDefinition->GetForcedItemQuality()));
}

static cell_t CEconItemDefinition_GetDefaultDropItemQuality(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemQualityDefinition(pItemDefinition->GetDefaultDropItemQuality()));
}

static cell_t CEconItemDefinition_GetDefaultDropQuantity(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetDefaultDropQuantity();
}

static cell_t CEconItemDefinition_GetDefinitionName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetDefinitionName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetLoadoutSlot(IPluginContext* pContext, const cell_t* params)
{
    CCStrike15ItemDefinition* pItemDefinition = reinterpret_cast<CCStrike15ItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetLoadoutSlot(params[2]);
}

static cell_t CEconItemDefinition_GetUsedByTeam(IPluginContext* pContext, const cell_t* params)
{
    CCStrike15ItemDefinition* pItemDefinition = reinterpret_cast<CCStrike15ItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetUsedByTeam();
}

static cell_t CEconItemDefinition_GetNumSupportedStickerSlots(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetNumSupportedStickerSlots();
}

static cell_t CEconItemDefinition_GetEconImage(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetInventoryImage();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetModel(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf;

    switch (static_cast<ModelType>(params[2]))
    {
        case ViewModel:
        {
            sBuf = pItemDefinition->GetBasePlayerDisplayModel();
            break;
        }
        case WorldModel:
        {
            sBuf = pItemDefinition->GetWorldDisplayModel();
            break;
        }
        case DroppedModel:
        {
            sBuf = pItemDefinition->GetWorldDroppedModel();
            break;
        }
        default:
        {
            return pContext->ThrowNativeError("Invalid ModelType value");
        }
    }

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[3], params[4], sBuf, &numBytes);
    }

    return numBytes;
}

// CPaintKit //
static cell_t CPaintKit_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetPaintKit(params[1]));
}

static cell_t CPaintKit_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pPaintKitMap = g_pCEconItemSchema->GetPaintKitMap();

    SM_NATIVE_ERROR_IF_NULL(pPaintKitMap);
    
    return pPaintKitMap->Count();
}

static cell_t CPaintKit_FindByID(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetPaintKitByID(params[1]));
}

static cell_t CPaintKit_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetPaintKitByName(strSource));
}

static cell_t CPaintKit_GetID(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetID();
}

static cell_t CPaintKit_GetName(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetDescription(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetDescriptionString();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetDescriptionTag(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetDescriptionTag();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetPattern(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetPattern();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetRarity(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);
    
    return pPaintKit->GetRarity();
}

static cell_t CPaintKit_GetStyle(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetStyle();
}

static cell_t CPaintKit_GetMinWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetWearRemapMin());
}

static cell_t CPaintKit_GetMaxWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetWearRemapMax());
}

static cell_t CPaintKit_GetPatternScale(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternScale());
}

static cell_t CPaintKit_GetVmtPath(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetVmtPath();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

// CStickerKit //
static cell_t CStickerKit_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetStickerKit(params[1]));
}

static cell_t CStickerKit_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pStickerKitMap = g_pCEconItemSchema->GetStickerKitMap();

    SM_NATIVE_ERROR_IF_NULL(pStickerKitMap);
    
    return pStickerKitMap->Count();
}

static cell_t CStickerKit_FindByID(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetStickerKitByID(params[1]));
}

static cell_t CStickerKit_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetStickerKitByName(strSource));
}

static cell_t CStickerKit_GetID(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return pStickerKit->GetID();
}

static cell_t CStickerKit_GetName(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetDescriptionString(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetDescriptionString();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetsItemName(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetsItemName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetMaterialPath(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetMaterialPath();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetMaterialPathNoDrips(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetMaterialPathNoDrips();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetInventoryImage(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetInventoryImage();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetEventID(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return pStickerKit->GetEventID();
}

static cell_t CStickerKit_GetEventTeamID(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return pStickerKit->GetEventTeamID();
}

static cell_t CStickerKit_GetPlayerID(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return pStickerKit->GetPlayerID();
}

static cell_t CStickerKit_IsMaterialPathIsAbsolute(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return pStickerKit->IsMaterialPathIsAbsolute();
}

static cell_t CStickerKit_GetScaleMin(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetScaleMin());
}

static cell_t CStickerKit_GetScaleMax(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetScaleMax());
}

static cell_t CStickerKit_GetWearMin(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetWearMin());
}

static cell_t CStickerKit_GetWearMax(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetWearMax());
}

static cell_t CStickerKit_GetIconURLSmall(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetIconURLSmall();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CStickerKit_GetIconURLLarge(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    size_t numBytes = 0;
    const char* sBuf = pStickerKit->GetIconURLLarge();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

// CEconMusicDefinition //
static cell_t CEconMusicDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetMusicDefinition(params[1]));
}

static cell_t CEconMusicDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pMusicDefinitionMap = g_pCEconItemSchema->GetMusicDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinitionMap);
    
    return pMusicDefinitionMap->Count();
}

static cell_t CEconMusicDefinition_FindByID(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetMusicDefinitionByID(params[1]));
}

static cell_t CEconMusicDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    CEconMusicDefinition* pMusicDefinition = g_pCEconItemSchema->GetMusicDefinitionByName(strSource);

    return reinterpret_cast<cell_t>(pMusicDefinition);
}

static cell_t CEconMusicDefinition_GetID(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    return pMusicDefinition->GetID();
}

static cell_t CEconMusicDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconMusicDefinition_GetNameLocToken(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetNameLocToken();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconMusicDefinition_GetLocDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconMusicDefinition_GetPedestalDisplayModel(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetPedestalDisplayModel();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconMusicDefinition_GetInventoryImage(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinition);

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetInventoryImage();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

// CEconItemListEntry //
static cell_t CEconItemListEntry_GetItemDef(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemDefinitionByDefIndex(pItemListEntry->m_nItemDef));
}

static cell_t CEconItemListEntry_GetPaintKit(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetPaintKitByID(pItemListEntry->m_nPaintKit));
}

static cell_t CEconItemListEntry_GetPaintKitSeed(IPluginContext* pContext, const cell_t* params)
{
    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);

    return reinterpret_cast<cell_t>(pItemListEntry->m_nPaintKitSeed);
}

static cell_t CEconItemListEntry_GetPaintKitWear(IPluginContext* pContext, const cell_t* params)
{
    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);

    return sp_ftoc(pItemListEntry->m_flPaintKitWear);
}

static cell_t CEconItemListEntry_GetStickerKit(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetStickerKitByID(pItemListEntry->m_nStickerKit));
}

static cell_t CEconItemListEntry_GetMusicKit(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetMusicDefinitionByID(pItemListEntry->m_nMusicKit));
}


// CEconItemSetDefinition //
static cell_t CEconItemSetDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemSetDefinition(params[1]));
}

static cell_t CEconItemSetDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pMusicDefinitionMap = g_pCEconItemSchema->GetMusicDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinitionMap);
    
    return pMusicDefinitionMap->Count();
}

static cell_t CEconItemSetDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    CEconItemSetDefinition* pItemSetDefinition = g_pCEconItemSchema->GetItemSetByName(strSource);

    return reinterpret_cast<cell_t>(pItemSetDefinition);
}

static cell_t CEconItemSetDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemSetDefinition->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemSetDefinition_GetLocalizedName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemSetDefinition->GetLocKey();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemSetDefinition_GetLocalizedDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemSetDefinition->GetLocDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemSetDefinition_GetBundleItemDef(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->GetBundle();
}

static cell_t CEconItemSetDefinition_IsCollection(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->IsCollection();
}

static cell_t CEconItemSetDefinition_IsHiddenSet(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->IsHiddenSet();
}

static cell_t CEconItemSetDefinition_GetItemCount(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->GetItemCount();
}

static cell_t CEconItemSetDefinition_GetItem(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return reinterpret_cast<cell_t>(pItemSetDefinition->GetItem(params[2]));
}

// CEconItemRarityDefinition
static cell_t CEconItemRarityDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemRarityDefinition(params[1]));
}

static cell_t CEconItemRarityDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemRarityDefinitionMap = g_pCEconItemSchema->GetItemRarityDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinitionMap);
    
    return pItemRarityDefinitionMap->Count();
}

static cell_t CEconItemRarityDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    CEconItemRarityDefinition* pItemSetDefinition = g_pCEconItemSchema->GetItemRarityDefinitionByName(strSource);

    return reinterpret_cast<cell_t>(pItemSetDefinition);
}

static cell_t CEconItemRarityDefinition_FindByDBValue(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemRarityDefinitionByDBValue(params[1]));
}

static cell_t CEconItemRarityDefinition_GetDBValue(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    return pItemRarityDefinition->GetDBValue();
}

static cell_t CEconItemRarityDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetLocKey(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetLocKey();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetWepLocKey(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetWepLocKey();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetCharacterLocKey(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetCharacterLocKey();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetLootList(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetLootList();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetRecycleLootList(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetRecycleLootList();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetDropSound(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetDropSound();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetAttribColor(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    return pItemRarityDefinition->GetAttribColor();
}

static cell_t CEconItemRarityDefinition_GetNextRarity(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemRarityDefinition->GetNextRarity();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemRarityDefinition_GetWhiteCount(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    return pItemRarityDefinition->GetWhiteCount();
}

static cell_t CEconItemRarityDefinition_GetBlackCount(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    return pItemRarityDefinition->GetBlackCount();
}

static cell_t CEconItemRarityDefinition_GetWeight(IPluginContext* pContext, const cell_t* params)
{
    CEconItemRarityDefinition* pItemRarityDefinition = reinterpret_cast<CEconItemRarityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinition);

    return sp_ftoc(pItemRarityDefinition->GetWeight());
}

// CEconItemQualityDefinition
static cell_t CEconItemQualityDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemQualityDefinition(params[1]));
}

static cell_t CEconItemQualityDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemQualityDefinitionMap = g_pCEconItemSchema->GetItemQualityDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinitionMap);
    
    return pItemQualityDefinitionMap->Count();
}

static cell_t CEconItemQualityDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    CEconItemQualityDefinition* pItemSetDefinition = g_pCEconItemSchema->GetItemQualityDefinitionByName(strSource);

    return reinterpret_cast<cell_t>(pItemSetDefinition);
}

static cell_t CEconItemQualityDefinition_FindByDBValue(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemQualityDefinitionByDBValue(params[1]));
}

static cell_t CEconItemQualityDefinition_GetDBValue(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    return pItemQualityDefinition->GetDBValue();
}

static cell_t CEconItemQualityDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemQualityDefinition->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemQualityDefinition_GetWeight(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    return pItemQualityDefinition->GetWeight();
}

static cell_t CEconItemQualityDefinition_GetRequiresExplicitMatches(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    return pItemQualityDefinition->GetRequiresExplicitMatches();
}

static cell_t CEconItemQualityDefinition_CanSupportSet(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    return pItemQualityDefinition->CanSupportSet();
}

static cell_t CEconItemQualityDefinition_GetHexColor(IPluginContext* pContext, const cell_t* params)
{
    CEconItemQualityDefinition* pItemQualityDefinition = reinterpret_cast<CEconItemQualityDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemQualityDefinition->GetHexColor();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

// CEconLootListDefinition
static cell_t CEconLootListDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetLootListDefinition(params[1]));
}

static cell_t CEconLootListDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    auto pLootListDefinitionDict = g_pCEconItemSchema->GetLootListDefinitionDict();

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinitionDict);

    return pLootListDefinitionDict->Count();
}

static cell_t CEconLootListDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetLootListDefinitionByName(strSource));
}

static cell_t CEconLootListDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    size_t numBytes = 0;
    const char* sBuf = pLootListDefinition->GetName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconLootListDefinition_GetHeroID(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->GetHeroID();
}

static cell_t CEconLootListDefinition_IsPublicListContents(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->IsPublicListContents();
}

static cell_t CEconLootListDefinition_ContainsStickersAutographedByProplayers(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->ContainsStickersAutographedByProplayers();
}

static cell_t CEconLootListDefinition_ContainsStickersRepresentingOrganizations(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->ContainsStickersRepresentingOrganizations();
}

static cell_t CEconLootListDefinition_ContainsPatchesRepresentingOrganizations(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->ContainsPatchesRepresentingOrganizations();
}

static cell_t CEconLootListDefinition_WillProduceStattrak(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->WillProduceStattrak();
}

static cell_t CEconLootListDefinition_GetTotalWeight(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return sp_ftoc(pLootListDefinition->GetTotalWeight());
}

static cell_t CEconLootListDefinition_IsServerList(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->IsServerList();
}

static cell_t CEconLootListDefinition_GetAdditionalDropCount(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return reinterpret_cast<cell_t>(pLootListDefinition->GetAdditionalDropCount());
}

static cell_t CEconLootListDefinition_GetAdditionalDrop(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return reinterpret_cast<cell_t>(pLootListDefinition->GetAdditionalDrop(params[2]));
}

static cell_t CEconLootListDefinition_GetItemCount(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->GetItemCount();
}

static cell_t CEconLootListDefinition_GetItem(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return reinterpret_cast<cell_t>(pLootListDefinition->GetItem(params[2]));
}

// CEconAdditionalDrop
static cell_t CEconAdditionalDrop_GetChance(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition::loot_list_additional_drop_t* pAdditionalDrop = reinterpret_cast<CEconLootListDefinition::loot_list_additional_drop_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pAdditionalDrop);

    return sp_ftoc(pAdditionalDrop->m_fChance);
}

static cell_t CEconAdditionalDrop_GetPremiumOnly(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition::loot_list_additional_drop_t* pAdditionalDrop = reinterpret_cast<CEconLootListDefinition::loot_list_additional_drop_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pAdditionalDrop);

    return pAdditionalDrop->m_bPremiumOnly;
}

static cell_t CEconAdditionalDrop_GetLootListDefinition(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconLootListDefinition::loot_list_additional_drop_t* pAdditionalDrop = reinterpret_cast<CEconLootListDefinition::loot_list_additional_drop_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pAdditionalDrop);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetLootListDefinitionByName(pAdditionalDrop->m_pszLootListDefName));
}
/*
static cell_t CEconLootListDefinition_(IPluginContext* pContext, const cell_t* params)
{
    CEconLootListDefinition* pLootListDefinition = reinterpret_cast<CEconLootListDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pLootListDefinition);

    return pLootListDefinition->_____();
}
*/
extern const sp_nativeinfo_t g_ExtensionNatives[] =
{
    // CEconItemDefinition
    { "CEconItemDefinition.Get",                            CEconItemDefinition_Get },
    { "CEconItemDefinition.Count",                          CEconItemDefinition_Count },
    { "CEconItemDefinition.FindByDefIndex",                 CEconItemDefinition_FindByDefIndex },
    { "CEconItemDefinition.FindByName",                     CEconItemDefinition_FindByName },
    { "CEconItemDefinition.DefinitionIndex.get",            CEconItemDefinition_GetDefinitionIndex },
    { "CEconItemDefinition.ItemRarity.get",                 CEconItemDefinition_GetItemRarity },
    { "CEconItemDefinition.ItemQuality.get",                CEconItemDefinition_GetItemQuality },
    { "CEconItemDefinition.ForcedItemQuality.get",          CEconItemDefinition_GetForcedItemQuality },
    { "CEconItemDefinition.DefaultDropItemQuality.get",     CEconItemDefinition_GetDefaultDropItemQuality },
    { "CEconItemDefinition.DefaultDropQuantity.get",        CEconItemDefinition_GetDefaultDropQuantity },
    { "CEconItemDefinition.GetDefinitionName",              CEconItemDefinition_GetDefinitionName },
    { "CEconItemDefinition.GetLoadoutSlot",                 CEconItemDefinition_GetLoadoutSlot },
    { "CEconItemDefinition.UsedByTeam.get",                 CEconItemDefinition_GetUsedByTeam },
    { "CEconItemDefinition.NumSupportedStickerSlots.get",   CEconItemDefinition_GetNumSupportedStickerSlots },
    { "CEconItemDefinition.GetEconImage",                   CEconItemDefinition_GetEconImage },
    { "CEconItemDefinition.GetModel",                       CEconItemDefinition_GetModel },

    // CPaintKit
    { "CPaintKit.Get",                                      CPaintKit_Get },
    { "CPaintKit.Count",                                    CPaintKit_Count },
    { "CPaintKit.FindByID",                                 CPaintKit_FindByID },
    { "CPaintKit.FindByName",                               CPaintKit_FindByName },
    { "CPaintKit.ID.get",                                   CPaintKit_GetID },
    { "CPaintKit.GetName",                                  CPaintKit_GetName },
    { "CPaintKit.GetDescription",                           CPaintKit_GetDescription },
    { "CPaintKit.GetDescriptionTag",                        CPaintKit_GetDescriptionTag },
    { "CPaintKit.GetPattern",                               CPaintKit_GetPattern },
    { "CPaintKit.Rarity.get",                               CPaintKit_GetRarity },
    { "CPaintKit.Style.get",                                CPaintKit_GetStyle },
    { "CPaintKit.MinWear.get",                              CPaintKit_GetMinWear },
    { "CPaintKit.MaxWear.get",                              CPaintKit_GetMaxWear },
    { "CPaintKit.PatternScale.get",                         CPaintKit_GetPatternScale },
    { "CPaintKit.GetVmtPath",                               CPaintKit_GetVmtPath },

    // CStickerKit
    { "CStickerKit.Get",                                    CStickerKit_Get },
    { "CStickerKit.Count",                                  CStickerKit_Count },
    { "CStickerKit.FindByID",                               CStickerKit_FindByID },
    { "CStickerKit.FindByName",                             CStickerKit_FindByName },
    { "CStickerKit.ID.get",                                 CStickerKit_GetID },
    { "CStickerKit.GetName",                                CStickerKit_GetName },
    { "CStickerKit.GetDescriptionString",                   CStickerKit_GetDescriptionString },
    { "CStickerKit.GetsItemName",                           CStickerKit_GetsItemName },
    { "CStickerKit.GetMaterialPath",                        CStickerKit_GetMaterialPath },
    { "CStickerKit.GetMaterialPathNoDrips",                 CStickerKit_GetMaterialPathNoDrips },
    { "CStickerKit.GetInventoryImage",                      CStickerKit_GetInventoryImage },
    { "CStickerKit.EventID.get",                            CStickerKit_GetEventID },
    { "CStickerKit.EventTeamID.get",                        CStickerKit_GetEventTeamID },
    { "CStickerKit.PlayerID.get",                           CStickerKit_GetPlayerID },
    { "CStickerKit.IsMaterialPathIsAbsolute.get",           CStickerKit_IsMaterialPathIsAbsolute },
    { "CStickerKit.ScaleMin.get",                           CStickerKit_GetScaleMin },
    { "CStickerKit.ScaleMax.get",                           CStickerKit_GetScaleMax },
    { "CStickerKit.WearMin.get",                            CStickerKit_GetWearMin },
    { "CStickerKit.WearMax.get",                            CStickerKit_GetWearMax },
    { "CStickerKit.GetIconURLSmall",                        CStickerKit_GetIconURLSmall },
    { "CStickerKit.GetIconURLLarge",                        CStickerKit_GetIconURLLarge },

    // CEconMusicDefinition
    { "CEconMusicDefinition.Get",                           CEconMusicDefinition_Get },
    { "CEconMusicDefinition.Count",                         CEconMusicDefinition_Count },
    { "CEconMusicDefinition.FindByID",                      CEconMusicDefinition_FindByID },
    { "CEconMusicDefinition.FindByName",                    CEconMusicDefinition_FindByName },
    { "CEconMusicDefinition.ID.get",                        CEconMusicDefinition_GetID },
    { "CEconMusicDefinition.GetName",                       CEconMusicDefinition_GetName },
    { "CEconMusicDefinition.GetNameLocToken",               CEconMusicDefinition_GetNameLocToken },
    { "CEconMusicDefinition.GetLocDescription",             CEconMusicDefinition_GetLocDescription },
    { "CEconMusicDefinition.GetPedestalDisplayModel",       CEconMusicDefinition_GetPedestalDisplayModel },
    { "CEconMusicDefinition.GetInventoryImage",             CEconMusicDefinition_GetInventoryImage },

    // CEconItemListEntry
    { "CEconItemListEntry.ItemDef.get",                     CEconItemListEntry_GetItemDef },
    { "CEconItemListEntry.PaintKit.get",                    CEconItemListEntry_GetPaintKit },
    { "CEconItemListEntry.PaintKitSeed.get",                CEconItemListEntry_GetPaintKitSeed },
    { "CEconItemListEntry.PaintKitWear.get",                CEconItemListEntry_GetPaintKitWear },
    { "CEconItemListEntry.StickerKit.get",                  CEconItemListEntry_GetStickerKit },
    { "CEconItemListEntry.MusicKit.get",                    CEconItemListEntry_GetMusicKit },

    // CEconItemSetDefinition
    { "CEconItemSetDefinition.Get",                         CEconItemSetDefinition_Get },
    { "CEconItemSetDefinition.Count",                       CEconItemSetDefinition_Count },
    { "CEconItemSetDefinition.FindByName",                  CEconItemSetDefinition_FindByName },
    { "CEconItemSetDefinition.GetName",                     CEconItemSetDefinition_GetName },
    { "CEconItemSetDefinition.GetLocalizedName",            CEconItemSetDefinition_GetLocalizedName },
    { "CEconItemSetDefinition.GetLocalizedDescription",     CEconItemSetDefinition_GetLocalizedDescription },
    { "CEconItemSetDefinition.BundleItemDef.get",           CEconItemSetDefinition_GetBundleItemDef },
    { "CEconItemSetDefinition.IsCollection.get",            CEconItemSetDefinition_IsCollection },
    { "CEconItemSetDefinition.IsHiddenSet.get",             CEconItemSetDefinition_IsHiddenSet },
    { "CEconItemSetDefinition.ItemCount.get",               CEconItemSetDefinition_GetItemCount },
    { "CEconItemSetDefinition.GetItem",                     CEconItemSetDefinition_GetItem },

    // CEconItemRarityDefinition
    { "CEconItemRarityDefinition.Get",                      CEconItemRarityDefinition_Get },
    { "CEconItemRarityDefinition.Count",                    CEconItemRarityDefinition_Count },
    { "CEconItemRarityDefinition.FindByName",               CEconItemRarityDefinition_FindByName },
    { "CEconItemRarityDefinition.FindByDBValue",            CEconItemRarityDefinition_FindByDBValue },
    { "CEconItemRarityDefinition.DBValue.get",              CEconItemRarityDefinition_GetDBValue },
    { "CEconItemRarityDefinition.GetName",                  CEconItemRarityDefinition_GetName },
    { "CEconItemRarityDefinition.GetLocKey",                CEconItemRarityDefinition_GetLocKey },
    { "CEconItemRarityDefinition.GetWepLocKey",             CEconItemRarityDefinition_GetWepLocKey },
    { "CEconItemRarityDefinition.GetCharacterLocKey",       CEconItemRarityDefinition_GetCharacterLocKey },
    { "CEconItemRarityDefinition.GetLootList",              CEconItemRarityDefinition_GetLootList },
    { "CEconItemRarityDefinition.GetRecycleLootList",       CEconItemRarityDefinition_GetRecycleLootList },
    { "CEconItemRarityDefinition.GetDropSound",             CEconItemRarityDefinition_GetDropSound },
    { "CEconItemRarityDefinition.AttribColor.get",          CEconItemRarityDefinition_GetAttribColor },
    { "CEconItemRarityDefinition.GetNextRarity",            CEconItemRarityDefinition_GetNextRarity },
    { "CEconItemRarityDefinition.WhiteCount.get",           CEconItemRarityDefinition_GetWhiteCount },
    { "CEconItemRarityDefinition.BlackCount.get",           CEconItemRarityDefinition_GetBlackCount },
    { "CEconItemRarityDefinition.Weight.get",               CEconItemRarityDefinition_GetWeight },

    // CEconItemQualityDefinition
    { "CEconItemQualityDefinition.Get",                         CEconItemQualityDefinition_Get },
    { "CEconItemQualityDefinition.Count",                       CEconItemQualityDefinition_Count },
    { "CEconItemQualityDefinition.FindByName",                  CEconItemQualityDefinition_FindByName },
    { "CEconItemQualityDefinition.FindByDBValue",               CEconItemQualityDefinition_FindByDBValue },
    { "CEconItemQualityDefinition.DBValue.get",                 CEconItemQualityDefinition_GetDBValue },
    { "CEconItemQualityDefinition.GetName",                     CEconItemQualityDefinition_GetName },
    { "CEconItemQualityDefinition.Weight.get",                  CEconItemQualityDefinition_GetWeight },
    { "CEconItemQualityDefinition.RequiresExplicitMatches.get", CEconItemQualityDefinition_GetRequiresExplicitMatches },
    { "CEconItemQualityDefinition.CanSupportSet.get",           CEconItemQualityDefinition_CanSupportSet },
    { "CEconItemQualityDefinition.GetHexColor",                 CEconItemQualityDefinition_GetHexColor },

    // CEconAdditionalDrop
    { "CEconAdditionalDrop.Chance.get",                         CEconAdditionalDrop_GetChance },
    { "CEconAdditionalDrop.PremiumOnly.get",                    CEconAdditionalDrop_GetPremiumOnly },
    { "CEconAdditionalDrop.LootListDefinition.get",             CEconAdditionalDrop_GetLootListDefinition },

    // CEconLootListDefinition
    { "CEconLootListDefinition.Get",                                CEconLootListDefinition_Get },
    { "CEconLootListDefinition.Count",                              CEconLootListDefinition_Count },
    { "CEconLootListDefinition.FindByName",                         CEconLootListDefinition_FindByName },
    { "CEconLootListDefinition.GetName",                            CEconLootListDefinition_GetName },
    { "CEconLootListDefinition.HeroID.get",                         CEconLootListDefinition_GetHeroID },
    { "CEconLootListDefinition.PublicListContents.get",             CEconLootListDefinition_IsPublicListContents },
    { "CEconLootListDefinition.ContainsAutographedStickers.get",    CEconLootListDefinition_ContainsStickersAutographedByProplayers },
    { "CEconLootListDefinition.ContainsOrganizationsStickers.get",  CEconLootListDefinition_ContainsStickersRepresentingOrganizations },
    { "CEconLootListDefinition.ContainsOrganizationsPatches.get",   CEconLootListDefinition_ContainsPatchesRepresentingOrganizations },
    { "CEconLootListDefinition.WillProduceStattrak.get",            CEconLootListDefinition_WillProduceStattrak },
    { "CEconLootListDefinition.TotalWeight.get",                    CEconLootListDefinition_GetTotalWeight },
    { "CEconLootListDefinition.ServerList.get",                     CEconLootListDefinition_IsServerList },
    { "CEconLootListDefinition.AdditionalDropCount.get",            CEconLootListDefinition_GetAdditionalDropCount },
    { "CEconLootListDefinition.GetAdditionalDrop",                  CEconLootListDefinition_GetAdditionalDrop },
    { "CEconLootListDefinition.ItemCount.get",                      CEconLootListDefinition_GetItemCount },
    { "CEconLootListDefinition.GetItem",                            CEconLootListDefinition_GetItem },

    { nullptr,  nullptr }
};