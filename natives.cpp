#include "extension.h"
#include "natives.h"
#include "classes.h"

// CEconItemDefinition //
static cell_t CEconItemDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemDefMap = g_pCEconItemSchema->GetItemDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemDefMap);
        
    return pItemDefMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(pItemDefMap->Element(params[1])) : 0;
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
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetLoadoutSlot(params[2]);
}

static cell_t CEconItemDefinition_GetUsedByTeam(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

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

    switch (static_cast<EconAPI_ModelType>(params[2]))
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
            return pContext->ThrowNativeError("Invalid EconAPI_ModelType value");
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

    auto pPaintKitMap = g_pCEconItemSchema->GetPaintKitMap();

    SM_NATIVE_ERROR_IF_NULL(pPaintKitMap);
    
    return pPaintKitMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(pPaintKitMap->Element(params[1])) : 0;
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

// CEconMusicDefinition //
static cell_t CEconMusicDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pMusicDefinitionMap = g_pCEconItemSchema->GetMusicDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pMusicDefinitionMap);
    
    return pMusicDefinitionMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(pMusicDefinitionMap->Element(params[1])) : 0;
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

// CEconItemSetDefinition //
static cell_t CEconItemSetDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemSetsMap = g_pCEconItemSchema->GetItemSetsMap();

    SM_NATIVE_ERROR_IF_NULL(pItemSetsMap);
    
    return pItemSetsMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(&pItemSetsMap->Element(params[1])) : 0;
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
    const char* sBuf = pItemSetDefinition->m_pszName;

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

    return pItemSetDefinition->m_bIsCollection;
}

static cell_t CEconItemSetDefinition_IsHiddenSet(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->m_bIsHiddenSet;
}

// CEconItemRarityDefinition
static cell_t CEconItemRarityDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    auto pItemRarityDefinitionMap = g_pCEconItemSchema->GetItemRarityDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemRarityDefinitionMap);
    
    return pItemRarityDefinitionMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(&pItemRarityDefinitionMap->Element(params[1])) : 0;
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

    auto pItemQualityDefinitionMap = g_pCEconItemSchema->GetItemQualityDefinitionMap();

    SM_NATIVE_ERROR_IF_NULL(pItemQualityDefinitionMap);
    
    return pItemQualityDefinitionMap->IsValidIndex(params[1]) ? reinterpret_cast<cell_t>(&pItemQualityDefinitionMap->Element(params[1])) : 0;
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


extern const sp_nativeinfo_t g_ExtensionNatives[] =
{
    // CEconItemDefinition
    { "CEconItemDefinition.Get",                            CEconItemDefinition_Get },
    { "CEconItemDefinition.Count",                          CEconItemDefinition_Count },
    { "CEconItemDefinition.FindByDefIndex",                 CEconItemDefinition_FindByDefIndex },
    { "CEconItemDefinition.FindByName",                     CEconItemDefinition_FindByName },
    { "CEconItemDefinition.DefinitionIndex.get",            CEconItemDefinition_GetDefinitionIndex },
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

    { nullptr,  nullptr }
};