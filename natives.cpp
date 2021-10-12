#include "extension.h"
#include "natives.h"
#include "classes.h"

// CEconItemDefinition //
static cell_t CEconItemDefinition_ItemCount(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        auto pMapItemDef = g_pCEconItemSchema->GetItemDefinitionMap();

        if (pMapItemDef)
        {
            return pMapItemDef->Count();
        }
        
        smutils->LogError(myself, "pMapItemDef == nullptr.");
    }
    else
    {
        smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");
    }

    return 0;
}

static cell_t CEconItemDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        char* strSource; pContext->LocalToString(params[1], &strSource);

        CEconItemDefinition* pItemDefinition = g_pCEconItemSchema->GetItemDefinitionByName(strSource);

        return reinterpret_cast<cell_t>(pItemDefinition);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CEconItemDefinition_FindByIndex(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        CEconItemDefinition* pItemDefinition = g_pCEconItemSchema->GetItemDefinitionByDefIndex(params[1]);

        return reinterpret_cast<cell_t>(pItemDefinition);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CEconItemDefinition_GetDefinitionIndex(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        return pItemDefinition->GetDefinitionIndex();
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetDefinitionName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        size_t numBytes = 0;
        const char* sBuf = pItemDefinition->GetDefinitionName();

        if (sBuf)
        {
            pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
        }

        return numBytes;
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetLoadoutSlot(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        return pItemDefinition->GetLoadoutSlot(params[2]);
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetUsedByTeam(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        return pItemDefinition->GetUsedByTeam();
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetNumSupportedStickerSlots(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        return pItemDefinition->GetNumSupportedStickerSlots();
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetEconImage(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
        size_t numBytes = 0;
        const char* sBuf = pItemDefinition->GetInventoryImage();

        if (sBuf)
        {
            pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
        }

        return numBytes;
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconItemDefinition_GetModel(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    if (pItemDefinition)
    {
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

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}


// CPaintKit //
static cell_t CPaintKit_FindByID(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        CPaintKit* pPaintKit = g_pCEconItemSchema->GetPaintKitByID(params[1]);

        return reinterpret_cast<cell_t>(pPaintKit);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CPaintKit_FindByName(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        char* strSource; pContext->LocalToString(params[1], &strSource);

        CPaintKit* pPaintKit = g_pCEconItemSchema->GetPaintKitByName(strSource);

        return reinterpret_cast<cell_t>(pPaintKit);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CPaintKit_GetID(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pPaintKit->GetID();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}

static cell_t CPaintKit_GetName(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pPaintKit)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pPaintKit)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pPaintKit)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pPaintKit)
    {
        return pPaintKit->GetRarity();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}

static cell_t CPaintKit_GetStyle(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pPaintKit->GetStyle();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}

static cell_t CPaintKit_GetDefaultWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pPaintKit->GetWearDefault();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}


static cell_t CPaintKit_GetMinWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pPaintKit->GetWearRemapMin();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}


static cell_t CPaintKit_GetMaxWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pPaintKit->GetWearRemapMax();
    }

    return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
}

static cell_t CPaintKit_GetVmtPath(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    if (!pPaintKit)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetVmtPath();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

// CEconMusicDefinition //
static cell_t CEconMusicDefinition_FindByID(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        CEconMusicDefinition* pMusicDefinition = g_pCEconItemSchema->GetMusicDefinitionByID(params[1]);

        return reinterpret_cast<cell_t>(pMusicDefinition);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CEconMusicDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        char* strSource; pContext->LocalToString(params[1], &strSource);

        CEconMusicDefinition* pMusicDefinition = g_pCEconItemSchema->GetMusicDefinitionByName(strSource);

        return reinterpret_cast<cell_t>(pMusicDefinition);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CEconMusicDefinition_GetID(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    if (pMusicDefinition)
    {
        return pMusicDefinition->GetID();
    }

    return pContext->ThrowNativeError("CEconItemDefinition == nullptr");
}

static cell_t CEconMusicDefinition_GetName(IPluginContext* pContext, const cell_t* params)
{
    CEconMusicDefinition* pMusicDefinition = reinterpret_cast<CEconMusicDefinition*>(params[1]);

    if (!pMusicDefinition)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pMusicDefinition)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pMusicDefinition)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pMusicDefinition)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

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

    if (!pMusicDefinition)
    {
        return pContext->ThrowNativeError("CEconMusicDefinition == nullptr");
    }

    size_t numBytes = 0;
    const char* sBuf = pMusicDefinition->GetInventoryImage();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}


// CEconItemSetDefinition //
static cell_t CEconItemSetDefinition_FindByName(IPluginContext* pContext, const cell_t* params)
{
    if (g_pCEconItemSchema)
    {
        char* strSource; pContext->LocalToString(params[1], &strSource);

        CEconItemSetDefinition* pItemSetDefinition = g_pCEconItemSchema->GetItemSetByName(strSource);

        return reinterpret_cast<cell_t>(pItemSetDefinition);
    }

    smutils->LogError(myself, "g_pCEconItemSchema == nullptr.");

    return 0;
}

static cell_t CEconItemSetDefinition_GetLocalizedName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    if (!pItemSetDefinition)
    {
        return pContext->ThrowNativeError("CEconItemSetDefinition == nullptr");
    }

    size_t numBytes = 0;
    const char* sBuf = pItemSetDefinition->m_pszLocalizedName;

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemSetDefinition_GetLocalizedDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    if (!pItemSetDefinition)
    {
        return pContext->ThrowNativeError("CEconItemSetDefinition == nullptr");
    }

    size_t numBytes = 0;
    const char* sBuf = pItemSetDefinition->m_pszLocalizedDescription;

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

extern const sp_nativeinfo_t g_ExtensionNatives[] =
{
    // CEconItemDefinition
    { "CEconItemDefinition.ItemCount",                      CEconItemDefinition_ItemCount },
    { "CEconItemDefinition.FindByName",                     CEconItemDefinition_FindByName },
    { "CEconItemDefinition.FindByIndex",                    CEconItemDefinition_FindByIndex },
    { "CEconItemDefinition.GetDefinitionIndex",             CEconItemDefinition_GetDefinitionIndex },
    { "CEconItemDefinition.GetDefinitionName",              CEconItemDefinition_GetDefinitionName },
    { "CEconItemDefinition.GetLoadoutSlot",                 CEconItemDefinition_GetLoadoutSlot },
    { "CEconItemDefinition.GetUsedByTeam",                  CEconItemDefinition_GetUsedByTeam },
    { "CEconItemDefinition.GetNumSupportedStickerSlots",    CEconItemDefinition_GetNumSupportedStickerSlots },
    { "CEconItemDefinition.GetEconImage",                   CEconItemDefinition_GetEconImage },
    { "CEconItemDefinition.GetModel",                       CEconItemDefinition_GetModel },

    // CPaintKit
    { "CPaintKit.FindByID",                                 CPaintKit_FindByID },
    { "CPaintKit.FindByName",                               CPaintKit_FindByName },
    { "CPaintKit.ID.get",                                   CPaintKit_GetID },
    { "CPaintKit.GetName",                                  CPaintKit_GetName },
    { "CPaintKit.GetDescription",                           CPaintKit_GetDescription },
    { "CPaintKit.GetDescriptionTag",                        CPaintKit_GetDescriptionTag },
    { "CPaintKit.GetPattern",                               CPaintKit_GetPattern },
    { "CPaintKit.Rarity.get",                               CPaintKit_GetRarity },
    { "CPaintKit.Style.get",                                CPaintKit_GetStyle },
    { "CPaintKit.DefaultWear.get",                          CPaintKit_GetDefaultWear },
    { "CPaintKit.MinWear.get",                              CPaintKit_GetMinWear },
    { "CPaintKit.MaxWear.get",                              CPaintKit_GetMaxWear },
    { "CPaintKit.GetVmtPath",                               CPaintKit_GetVmtPath },

    // CEconMusicDefinition
    { "CEconMusicDefinition.FindByID",                      CEconMusicDefinition_FindByID },
    { "CEconMusicDefinition.FindByName",                    CEconMusicDefinition_FindByName },
    { "CEconMusicDefinition.ID.get",                        CEconMusicDefinition_GetID },
    { "CEconMusicDefinition.GetName",                       CEconMusicDefinition_GetName },
    { "CEconMusicDefinition.GetNameLocToken",               CEconMusicDefinition_GetNameLocToken },
    { "CEconMusicDefinition.GetLocDescription",             CEconMusicDefinition_GetLocDescription },
    { "CEconMusicDefinition.GetPedestalDisplayModel",       CEconMusicDefinition_GetPedestalDisplayModel },
    { "CEconMusicDefinition.GetInventoryImage",             CEconMusicDefinition_GetInventoryImage },

    // CEconItemSetDefinition
    { "CEconItemSetDefinition.FindByName",                  CEconItemSetDefinition_FindByName },
    { "CEconItemSetDefinition.GetLocalizedName",            CEconItemSetDefinition_GetLocalizedName },
    { "CEconItemSetDefinition.GetLocalizedDescription",     CEconItemSetDefinition_GetLocalizedDescription },

    { nullptr,  nullptr }
};