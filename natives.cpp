/**
 * EconAPI
 * Copyright (C) 2021-2022 Natanel 'LuqS' Shitrit
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

// booleans
static cell_t CEconItemDefinition_IsEnabled(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsEnabled();
}

static cell_t CEconItemDefinition_HasProperName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->HasProperName();
}

static cell_t CEconItemDefinition_ShouldLoadOnDemand(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShouldLoadOnDemand();
}

static cell_t CEconItemDefinition_HasBeenLoaded(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->HasBeenLoaded();
}

static cell_t CEconItemDefinition_HideBodyGroupsDeployedOnly(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->HideBodyGroupsDeployedOnly();
}

static cell_t CEconItemDefinition_ShouldAttachToHands(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShouldAttachToHands();
}

static cell_t CEconItemDefinition_ShouldAttachToHandsVMOnly(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShouldAttachToHandsVMOnly();
}

static cell_t CEconItemDefinition_ShouldFlipViewModel(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShouldFlipViewModel();
}

static cell_t CEconItemDefinition_IsActingAsWearable(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsActingAsWearable();
}

static cell_t CEconItemDefinition_ShoulDisableStyleSelector(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShoulDisableStyleSelector();
}

static cell_t CEconItemDefinition_IsHidden(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsHidden();
}

static cell_t CEconItemDefinition_ShouldShowInArmory(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->ShouldShowInArmory();
}

static cell_t CEconItemDefinition_IsBaseItem(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsBaseItem();
}

static cell_t CEconItemDefinition_IsDefaultSlotItem(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsDefaultSlotItem();
}

static cell_t CEconItemDefinition_IsImported(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsImported();
}

static cell_t CEconItemDefinition_IsOnePerAccountCDKEY(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsOnePerAccountCDKEY();
}

static cell_t CEconItemDefinition_IsPackBundle(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsPackBundle();
}

static cell_t CEconItemDefinition_IsPackItem(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsPackItem();
}

static cell_t CEconItemDefinition_IsAllowedInMatch(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsAllowedInMatch();
}

static cell_t CEconItemDefinition_IsPublicItem(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IsPublicItem();
}

static cell_t CEconItemDefinition_IgnoreInCollectionView(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->IgnoreInCollectionView();
}

// integers
static cell_t CEconItemDefinition_GetMinItemLevel(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetMinItemLevel();
}

static cell_t CEconItemDefinition_GetMaxItemLevel(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetMaxItemLevel();
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

static cell_t CEconItemDefinition_GetPopularitySeed(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetPopularitySeed();
}

static cell_t CEconItemDefinition_GetDefinitionIndex(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetDefinitionIndex();
}

static cell_t CEconItemDefinition_GetItemTypeID(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetItemTypeID();
}

static cell_t CEconItemDefinition_GetNumConcreteItems(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetNumConcreteItems();
}

static cell_t CEconItemDefinition_GetNumSupportedStickerSlots(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetNumSupportedStickerSlots();
}

static cell_t CEconItemDefinition_GetSoundMaterialID(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetSoundMaterialID();
}

static cell_t CEconItemDefinition_GetArmoryRemap(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetArmoryRemap();
}

static cell_t CEconItemDefinition_GetStoreRemap(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetStoreRemap();
}

static cell_t CEconItemDefinition_GetDropType(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetDropType();
}

static cell_t CEconItemDefinition_GetSubType(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetSubType();
}

static cell_t CEconItemDefinition_GetExpirationTime(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetExpirationTime();
}

static cell_t CEconItemDefinition_GetDefCreationTime(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetDefCreationTime();
}

static cell_t CEconItemDefinition_GetEconItemType(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetEconItemType();
}

static cell_t CEconItemDefinition_GetCapabilities(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetCapabilities();
}

static cell_t CEconItemDefinition_GetEquipRegionMask(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetEquipRegionMask();
}

static cell_t CEconItemDefinition_GetEquipRegionConflictMask(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);
    
    return pItemDefinition->GetEquipRegionConflictMask();
}

// strings
static cell_t CEconItemDefinition_GetBaseName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetBaseName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetTypeName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetTypeName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetInventoryImage(IPluginContext* pContext, const cell_t* params)
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

static cell_t CEconItemDefinition_GetIconDefaultImage(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetIconDefaultImage();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetBrassModelOverride(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetBrassModelOverride();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetZoomInSound(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetZoomInSound();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetZoomOutSound(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetZoomOutSound();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetIconURLSmall(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetIconURLSmall();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetIconURLLarge(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetIconURLLarge();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetUnknown1(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetUnknown1();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetUnknown2(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetUnknown2();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetParticleFile(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetParticleFile();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetParticleSnapshotFile(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetParticleSnapshotFile();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetLootListName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetLootListName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetItemClassname(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetItemClassname();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetItemLogClassname(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetItemLogClassname();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetItemIconClassname(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetItemIconClassname();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
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

static cell_t CEconItemDefinition_GetArmoryDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetArmoryDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetClassToken(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetClassToken();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetSlotToken(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetSlotToken();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemDefinition_GetHolidayRestriction(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemDefinition->GetHolidayRestriction();

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
        case HolsteredModel:
        {
            sBuf = pItemDefinition->GetHolsteredModel();
            break;
        }
        case WorldExtraWearableModel:
        {
            sBuf = pItemDefinition->GetWorldExtraWearableModel();
            break;
        }
        case InventoryModel:
        {
            sBuf = pItemDefinition->GetInventoryModel();
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

static cell_t CEconItemSetDefinition_GetWorkshopContributorsCount(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetWorkshopContributorsCount();
}

static cell_t CEconItemSetDefinition_GetWorkshopContributor(IPluginContext* pContext, const cell_t* params)
{
    CEconItemDefinition* pItemDefinition = reinterpret_cast<CEconItemDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemDefinition);

    return pItemDefinition->GetWorkshopContributor(params[2]);
}

// CCStrike15ItemDefinition
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

static cell_t CPaintKit_GetSameNameFamilyAggregate(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetSameNameFamilyAggregate();

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

static cell_t CPaintKit_GetNormal(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetNormal();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetLogoMaterial(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    size_t numBytes = 0;
    const char* sBuf = pPaintKit->GetLogoMaterial();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CPaintKit_GetRarity(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemRarityDefinition(pPaintKit->GetRarity()));
}

static cell_t CPaintKit_GetStyle(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetStyle();
}

static cell_t CPaintKit_GetRGBAColor(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    cell_t* color_buffer;
    pContext->LocalToPhysAddr(params[3], &color_buffer);

    pPaintKit->GetRGBAColor(params[2], color_buffer);

    return 0;
}

static cell_t CPaintKit_GetRGBALogoColor(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    cell_t* color_buffer;
    pContext->LocalToPhysAddr(params[3], &color_buffer);

    pPaintKit->GetRGBALogoColor(params[2], color_buffer);

    return 0;
}

static cell_t CPaintKit_GetDefaultWear(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetWearDefault());
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

static cell_t CPaintKit_GetFixedSeed(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetFixedSeed();
}

static cell_t CPaintKit_GetPhongExponent(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetPhongExponent();
}

static cell_t CPaintKit_GetPhongAlbedoBoost(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetPhongAlbedoBoost();
}

static cell_t CPaintKit_GetPhongIntensity(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetPhongIntensity();
}

static cell_t CPaintKit_GetPatternScale(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternScale());
}

static cell_t CPaintKit_GetPatternOffsetXStart(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternOffsetXStart());
}

static cell_t CPaintKit_GetPatternOffsetXEnd(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternOffsetXEnd());
}

static cell_t CPaintKit_GetPatternOffsetYStart(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternOffsetYStart());
}

static cell_t CPaintKit_GetPatternOffsetYEnd(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternOffsetYEnd());
}

static cell_t CPaintKit_GetPatternRotateStart(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternRotateStart());
}

static cell_t CPaintKit_GetPatternRotateEnd(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPatternRotateEnd());
}

static cell_t CPaintKit_GetLogoScale(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetLogoScale());
}

static cell_t CPaintKit_GetLogoOffsetX(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetLogoOffsetX());
}

static cell_t CPaintKit_GetLogoOffsetY(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetLogoOffsetY());
}

static cell_t CPaintKit_GetLogoRotation(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetLogoRotation());
}

static cell_t CPaintKit_GetIgnoreWeaponSizeScale(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetIgnoreWeaponSizeScale();
}

static cell_t CPaintKit_GetViewModelExponentOverrideSize(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetViewModelExponentOverrideSize();
}

static cell_t CPaintKit_GetOnlyFirstMaterial(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetOnlyFirstMaterial();
}

static cell_t CPaintKit_GetUseNormal(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return pPaintKit->GetUseNormal();
}

static cell_t CPaintKit_GetPearlescent(IPluginContext* pContext, const cell_t* params)
{
    CPaintKit* pPaintKit = reinterpret_cast<CPaintKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pPaintKit);

    return sp_ftoc(pPaintKit->GetPearlescent());
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

static cell_t CStickerKit_GetRotateStart(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetRotateStart());
}

static cell_t CStickerKit_GetRotateEnd(IPluginContext* pContext, const cell_t* params)
{
    CStickerKit* pStickerKit = reinterpret_cast<CStickerKit*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pStickerKit);

    return sp_ftoc(pStickerKit->GetRotateEnd());
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

static cell_t CEconItemListEntry_GetLootList(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    item_list_entry_t* pItemListEntry = reinterpret_cast<item_list_entry_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemListEntry);
    
    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetLootListDefinition(pItemListEntry->m_nItemDef));
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

    return pItemListEntry->m_nPaintKitSeed;
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

// CEconItemSetDefinitionAttribute //
static cell_t CEconItemSetDefinitionAttribute_GetAttribute(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition::itemset_attrib_t* pItemSetDefinitionAttribute = reinterpret_cast<CEconItemSetDefinition::itemset_attrib_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinitionAttribute);

    return pItemSetDefinitionAttribute->m_iAttribDefIndex;
}

static cell_t CEconItemSetDefinitionAttribute_GetValue(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition::itemset_attrib_t* pItemSetDefinitionAttribute = reinterpret_cast<CEconItemSetDefinition::itemset_attrib_t*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinitionAttribute);

    return pItemSetDefinitionAttribute->m_valValue;
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

static cell_t CEconItemSetDefinition_GetCraftReward(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetItemDefinition(pItemSetDefinition->GetCraftReward()));
}

static cell_t CEconItemSetDefinition_GetAttributeCount(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return pItemSetDefinition->GetAttributeCount();
}

static cell_t CEconItemSetDefinition_GetAttribute(IPluginContext* pContext, const cell_t* params)
{
    CEconItemSetDefinition* pItemSetDefinition = reinterpret_cast<CEconItemSetDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemSetDefinition);

    return reinterpret_cast<cell_t>(pItemSetDefinition->GetAttribute(params[2]));
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

    return pLootListDefinition->GetAdditionalDropCount();
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

// CEconItemAttributeDefinition
static cell_t CEconItemAttributeDefinition_Get(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetAttributeDefinition(params[1]));
}

static cell_t CEconItemAttributeDefinition_Count(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);
    
    auto pAttributeDefinitionContainer = g_pCEconItemSchema->GetAttributeDefinitionContainer();

    SM_NATIVE_ERROR_IF_NULL(pAttributeDefinitionContainer);

    return pAttributeDefinitionContainer->Count();
}

static cell_t CEconItemAttributeDefinition_FindByDefinitionName(IPluginContext* pContext, const cell_t* params)
{
    SM_NATIVE_ERROR_IF_NULL(g_pCEconItemSchema);

    char* strSource; pContext->LocalToString(params[1], &strSource);

    return reinterpret_cast<cell_t>(g_pCEconItemSchema->GetAttributeDefinitionByDefName(strSource));
}

static cell_t CEconItemAttributeDefinition_GetDefinitionIndex(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);
    
    return pItemAttributeDefinition->GetDefinitionIndex();
}

static cell_t CEconItemAttributeDefinition_GetDefinitionName(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemAttributeDefinition->GetDefinitionName();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemAttributeDefinition_IsHidden(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->IsHidden();
}

static cell_t CEconItemAttributeDefinition_IsWebSchemaOutputForced(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->IsWebSchemaOutputForced();
}

static cell_t CEconItemAttributeDefinition_IsStoredAsInteger(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->IsStoredAsInteger();
}

static cell_t CEconItemAttributeDefinition_IsInstanceData(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->IsInstanceData();
}

static cell_t CEconItemAttributeDefinition_GetAssetClassAttrExportRule(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->GetAssetClassAttrExportRule();
}

static cell_t CEconItemAttributeDefinition_GetAssetClassBucket(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->GetAssetClassBucket();
}

static cell_t CEconItemAttributeDefinition_GetEffectType(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->GetEffectType();
}

static cell_t CEconItemAttributeDefinition_GetDescriptionFormat(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->GetDescriptionFormat();
}

static cell_t CEconItemAttributeDefinition_GetDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemAttributeDefinition->GetDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemAttributeDefinition_GetDescriptionTag(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemAttributeDefinition->GetDescriptionTag();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemAttributeDefinition_GetArmoryDescription(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemAttributeDefinition->GetArmoryDescription();

    if (sBuf)
    {
        pContext->StringToLocalUTF8(params[2], params[3], sBuf, &numBytes);
    }

    return numBytes;
}

static cell_t CEconItemAttributeDefinition_GetScore(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    return pItemAttributeDefinition->GetScore();
}

static cell_t CEconItemAttributeDefinition_GetAttributeClass(IPluginContext* pContext, const cell_t* params)
{
    CEconItemAttributeDefinition* pItemAttributeDefinition = reinterpret_cast<CEconItemAttributeDefinition*>(params[1]);

    SM_NATIVE_ERROR_IF_NULL(pItemAttributeDefinition);

    size_t numBytes = 0;
    const char* sBuf = pItemAttributeDefinition->GetAttributeClass();

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
    { "CEconItemDefinition.IsEnabled.get",                  CEconItemDefinition_IsEnabled },
    { "CEconItemDefinition.HasProperName.get",              CEconItemDefinition_HasProperName },
    { "CEconItemDefinition.ShouldLoadOnDemand.get",         CEconItemDefinition_ShouldLoadOnDemand },
    { "CEconItemDefinition.HasBeenLoaded.get",              CEconItemDefinition_HasBeenLoaded },
    { "CEconItemDefinition.HideBodyGroupsDeployedOnly.get", CEconItemDefinition_HideBodyGroupsDeployedOnly },
    { "CEconItemDefinition.ShouldAttachToHands.get",        CEconItemDefinition_ShouldAttachToHands },
    { "CEconItemDefinition.ShouldAttachToHandsVMOnly.get",  CEconItemDefinition_ShouldAttachToHandsVMOnly },
    { "CEconItemDefinition.ShouldFlipViewModel.get",        CEconItemDefinition_ShouldFlipViewModel },
    { "CEconItemDefinition.IsActingAsWearable.get",         CEconItemDefinition_IsActingAsWearable },
    { "CEconItemDefinition.ShoulDisableStyleSelector.get",  CEconItemDefinition_ShoulDisableStyleSelector },
    { "CEconItemDefinition.IsHidden.get",                   CEconItemDefinition_IsHidden },
    { "CEconItemDefinition.ShouldShowInArmory.get",         CEconItemDefinition_ShouldShowInArmory },
    { "CEconItemDefinition.IsBaseItem.get",                 CEconItemDefinition_IsBaseItem },
    { "CEconItemDefinition.IsDefaultSlotItem.get",          CEconItemDefinition_IsDefaultSlotItem },
    { "CEconItemDefinition.IsImported.get",                 CEconItemDefinition_IsImported },
    { "CEconItemDefinition.IsOnePerAccountCDKEY.get",       CEconItemDefinition_IsOnePerAccountCDKEY },
    { "CEconItemDefinition.IsPackBundle.get",               CEconItemDefinition_IsPackBundle },
    { "CEconItemDefinition.IsPackItem.get",                 CEconItemDefinition_IsPackItem },
    { "CEconItemDefinition.IsAllowedInMatch.get",           CEconItemDefinition_IsAllowedInMatch },
    { "CEconItemDefinition.IsPublicItem.get",               CEconItemDefinition_IsPublicItem },
    { "CEconItemDefinition.IgnoreInCollectionView.get",     CEconItemDefinition_IgnoreInCollectionView },

    { "CEconItemDefinition.MinItemLevel.get",               CEconItemDefinition_GetMinItemLevel },
    { "CEconItemDefinition.MaxItemLevel.get",               CEconItemDefinition_GetMaxItemLevel },
    { "CEconItemDefinition.ItemRarity.get",                 CEconItemDefinition_GetItemRarity },
    { "CEconItemDefinition.ItemQuality.get",                CEconItemDefinition_GetItemQuality },
    { "CEconItemDefinition.ForcedItemQuality.get",          CEconItemDefinition_GetForcedItemQuality },
    { "CEconItemDefinition.DefaultDropItemQuality.get",     CEconItemDefinition_GetDefaultDropItemQuality },
    { "CEconItemDefinition.DefaultDropQuantity.get",        CEconItemDefinition_GetDefaultDropQuantity },
    { "CEconItemDefinition.PopularitySeed.get",             CEconItemDefinition_GetPopularitySeed },
    { "CEconItemDefinition.DefinitionIndex.get",            CEconItemDefinition_GetDefinitionIndex },
    { "CEconItemDefinition.ItemTypeID.get",                 CEconItemDefinition_GetItemTypeID },
    { "CEconItemDefinition.NumConcreteItems.get",           CEconItemDefinition_GetNumConcreteItems },
    { "CEconItemDefinition.NumSupportedStickerSlots.get",   CEconItemDefinition_GetNumSupportedStickerSlots },
    { "CEconItemDefinition.SoundMaterialID.get",            CEconItemDefinition_GetSoundMaterialID },
    { "CEconItemDefinition.ArmoryRemap.get",                CEconItemDefinition_GetArmoryRemap },
    { "CEconItemDefinition.StoreRemap.get",                 CEconItemDefinition_GetStoreRemap },
    { "CEconItemDefinition.DropType.get",                   CEconItemDefinition_GetDropType },
    { "CEconItemDefinition.SubType.get",                    CEconItemDefinition_GetSubType },
    { "CEconItemDefinition.ExpirationTime.get",             CEconItemDefinition_GetExpirationTime },
    { "CEconItemDefinition.DefCreationTime.get",            CEconItemDefinition_GetDefCreationTime },
    { "CEconItemDefinition.EconItemType.get",               CEconItemDefinition_GetEconItemType },
    { "CEconItemDefinition.Capabilities.get",               CEconItemDefinition_GetCapabilities },
    { "CEconItemDefinition.EquipRegionMask.get",            CEconItemDefinition_GetEquipRegionMask },
    { "CEconItemDefinition.EquipRegionConflictMask.get",    CEconItemDefinition_GetEquipRegionConflictMask },

    { "CEconItemDefinition.GetBaseName",                    CEconItemDefinition_GetBaseName },
    { "CEconItemDefinition.GetTypeName",                    CEconItemDefinition_GetTypeName },
    { "CEconItemDefinition.GetDescription",                 CEconItemDefinition_GetDescription },
    { "CEconItemDefinition.GetInventoryImage",              CEconItemDefinition_GetInventoryImage },
    { "CEconItemDefinition.GetIconDefaultImage",            CEconItemDefinition_GetIconDefaultImage },
    { "CEconItemDefinition.GetBrassModelOverride",          CEconItemDefinition_GetBrassModelOverride },
    { "CEconItemDefinition.GetZoomInSound",                 CEconItemDefinition_GetZoomInSound },
    { "CEconItemDefinition.GetZoomOutSound",                CEconItemDefinition_GetZoomOutSound },
    { "CEconItemDefinition.GetIconURLSmall",                CEconItemDefinition_GetIconURLSmall },
    { "CEconItemDefinition.GetIconURLLarge",                CEconItemDefinition_GetIconURLLarge },
    { "CEconItemDefinition.GetUnknown1",                    CEconItemDefinition_GetUnknown1 },
    { "CEconItemDefinition.GetUnknown2",                    CEconItemDefinition_GetUnknown2 },
    { "CEconItemDefinition.GetParticleFile",                CEconItemDefinition_GetParticleFile },
    { "CEconItemDefinition.GetParticleSnapshotFile",        CEconItemDefinition_GetParticleSnapshotFile },
    { "CEconItemDefinition.GetLootListName",                CEconItemDefinition_GetLootListName },
    { "CEconItemDefinition.GetItemClassname",               CEconItemDefinition_GetItemClassname },
    { "CEconItemDefinition.GetItemLogClassname",            CEconItemDefinition_GetItemLogClassname },
    { "CEconItemDefinition.GetItemIconClassname",           CEconItemDefinition_GetItemIconClassname },
    { "CEconItemDefinition.GetDefinitionName",              CEconItemDefinition_GetDefinitionName },
    { "CEconItemDefinition.GetArmoryDescription",           CEconItemDefinition_GetArmoryDescription },
    { "CEconItemDefinition.GetClassToken",                  CEconItemDefinition_GetClassToken },
    { "CEconItemDefinition.GetSlotToken",                   CEconItemDefinition_GetSlotToken },
    { "CEconItemDefinition.GetHolidayRestriction",          CEconItemDefinition_GetHolidayRestriction },

    { "CEconItemDefinition.UsedByTeam.get",                 CEconItemDefinition_GetUsedByTeam },
    { "CEconItemDefinition.GetLoadoutSlot",                 CEconItemDefinition_GetLoadoutSlot },
    { "CEconItemDefinition.GetModel",                       CEconItemDefinition_GetModel },

    { "CEconItemDefinition.WorkshopContributorsCount.get",  CEconItemSetDefinition_GetWorkshopContributorsCount },
    { "CEconItemDefinition.GetWorkshopContributor",         CEconItemSetDefinition_GetWorkshopContributor },

    // CPaintKit
    { "CPaintKit.Get",                                      CPaintKit_Get },
    { "CPaintKit.Count",                                    CPaintKit_Count },
    { "CPaintKit.FindByID",                                 CPaintKit_FindByID },
    { "CPaintKit.FindByName",                               CPaintKit_FindByName },
    { "CPaintKit.ID.get",                                   CPaintKit_GetID },
    { "CPaintKit.GetName",                                  CPaintKit_GetName },
    { "CPaintKit.GetDescription",                           CPaintKit_GetDescription },
    { "CPaintKit.GetDescriptionTag",                        CPaintKit_GetDescriptionTag },
    { "CPaintKit.GetSameNameFamilyAggregate",               CPaintKit_GetSameNameFamilyAggregate },
    { "CPaintKit.GetPattern",                               CPaintKit_GetPattern },
    { "CPaintKit.GetNormal",                                CPaintKit_GetNormal },
    { "CPaintKit.GetLogoMaterial",                          CPaintKit_GetLogoMaterial },
    { "CPaintKit.Rarity.get",                               CPaintKit_GetRarity },
    { "CPaintKit.Style.get",                                CPaintKit_GetStyle },
    { "CPaintKit.GetRGBAColor",                             CPaintKit_GetRGBAColor },
    { "CPaintKit.GetRGBALogoColor",                         CPaintKit_GetRGBALogoColor },
    { "CPaintKit.DefaultWear.get",                          CPaintKit_GetDefaultWear },
    { "CPaintKit.MinWear.get",                              CPaintKit_GetMinWear },
    { "CPaintKit.MaxWear.get",                              CPaintKit_GetMaxWear },
    { "CPaintKit.FixedSeed.get",                            CPaintKit_GetFixedSeed },
    { "CPaintKit.PhongExponent.get",                        CPaintKit_GetPhongExponent },
    { "CPaintKit.PhongAlbedoBoost.get",                     CPaintKit_GetPhongAlbedoBoost },
    { "CPaintKit.PhongIntensity.get",                       CPaintKit_GetPhongIntensity },
    { "CPaintKit.PatternScale.get",                         CPaintKit_GetPatternScale },
    { "CPaintKit.PatternOffsetXStart.get",                  CPaintKit_GetPatternOffsetXStart },
    { "CPaintKit.PatternOffsetXEnd.get",                    CPaintKit_GetPatternOffsetXEnd },
    { "CPaintKit.PatternOffsetYStart.get",                  CPaintKit_GetPatternOffsetYStart },
    { "CPaintKit.PatternOffsetYEnd.get",                    CPaintKit_GetPatternOffsetYEnd },
    { "CPaintKit.PatternRotateStart.get",                   CPaintKit_GetPatternRotateStart },
    { "CPaintKit.PatternRotateEnd.get",                     CPaintKit_GetPatternRotateEnd },
    { "CPaintKit.LogoScale.get",                            CPaintKit_GetLogoScale },
    { "CPaintKit.LogoOffsetX.get",                          CPaintKit_GetLogoOffsetX },
    { "CPaintKit.LogoOffsetY.get",                          CPaintKit_GetLogoOffsetY },
    { "CPaintKit.LogoRotation.get",                         CPaintKit_GetLogoRotation },
    { "CPaintKit.IgnoreWeaponSizeScale.get",                CPaintKit_GetIgnoreWeaponSizeScale },
    { "CPaintKit.ViewModelExponentOverrideSize.get",        CPaintKit_GetViewModelExponentOverrideSize },
    { "CPaintKit.OnlyFirstMaterial.get",                    CPaintKit_GetOnlyFirstMaterial },
    { "CPaintKit.UseNormal.get",                            CPaintKit_GetUseNormal },
    { "CPaintKit.Pearlescent.get",                          CPaintKit_GetPearlescent },
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
    { "CStickerKit.RotateStart.get",                        CStickerKit_GetRotateStart },
    { "CStickerKit.RotateEnd.get",                          CStickerKit_GetRotateEnd },
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
    { "CEconItemListEntry.LootList.get",                    CEconItemListEntry_GetLootList },
    { "CEconItemListEntry.PaintKit.get",                    CEconItemListEntry_GetPaintKit },
    { "CEconItemListEntry.PaintKitSeed.get",                CEconItemListEntry_GetPaintKitSeed },
    { "CEconItemListEntry.PaintKitWear.get",                CEconItemListEntry_GetPaintKitWear },
    { "CEconItemListEntry.StickerKit.get",                  CEconItemListEntry_GetStickerKit },
    { "CEconItemListEntry.MusicKit.get",                    CEconItemListEntry_GetMusicKit },

    // CEconItemSetDefinitionAttribute
    { "CEconItemSetDefinitionAttribute.AttributeDefIndex.get",      CEconItemSetDefinitionAttribute_GetAttribute },
    { "CEconItemSetDefinitionAttribute.Value.get",          CEconItemSetDefinitionAttribute_GetValue },

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
    { "CEconItemSetDefinition.CraftReward.get",             CEconItemSetDefinition_GetCraftReward },
    { "CEconItemSetDefinition.AttributeCount.get",          CEconItemSetDefinition_GetAttributeCount },
    { "CEconItemSetDefinition.GetAttribute",                CEconItemSetDefinition_GetAttribute },

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

    // CEconItemAttributeDefinition
    { "CEconItemAttributeDefinition.Get",                           CEconItemAttributeDefinition_Get },
    { "CEconItemAttributeDefinition.Count",                         CEconItemAttributeDefinition_Count },
    { "CEconItemAttributeDefinition.FindByDefinitionName",          CEconItemAttributeDefinition_FindByDefinitionName },
    { "CEconItemAttributeDefinition.DefinitionIndex.get",           CEconItemAttributeDefinition_GetDefinitionIndex },
    { "CEconItemAttributeDefinition.GetDefinitionName",             CEconItemAttributeDefinition_GetDefinitionName },
    { "CEconItemAttributeDefinition.IsHidden.get",                  CEconItemAttributeDefinition_IsHidden },
    { "CEconItemAttributeDefinition.IsWebSchemaOutputForced.get",   CEconItemAttributeDefinition_IsWebSchemaOutputForced },
    { "CEconItemAttributeDefinition.IsStoredAsInteger.get",         CEconItemAttributeDefinition_IsStoredAsInteger },
    { "CEconItemAttributeDefinition.IsInstanceData.get",            CEconItemAttributeDefinition_IsInstanceData },
    { "CEconItemAttributeDefinition.AssetClassAttrExportRule.get",  CEconItemAttributeDefinition_GetAssetClassAttrExportRule },
    { "CEconItemAttributeDefinition.AssetClassBucket.get",          CEconItemAttributeDefinition_GetAssetClassBucket },
    { "CEconItemAttributeDefinition.EffectType.get",                CEconItemAttributeDefinition_GetEffectType },
    { "CEconItemAttributeDefinition.DescriptionFormat.get",         CEconItemAttributeDefinition_GetDescriptionFormat },
    { "CEconItemAttributeDefinition.GetDescription",                CEconItemAttributeDefinition_GetDescription },
    { "CEconItemAttributeDefinition.GetDescriptionTag",             CEconItemAttributeDefinition_GetDescriptionTag },
    { "CEconItemAttributeDefinition.GetArmoryDescription",          CEconItemAttributeDefinition_GetArmoryDescription },
    { "CEconItemAttributeDefinition.Score.get",                     CEconItemAttributeDefinition_GetScore },
    { "CEconItemAttributeDefinition.GetAttributeClass",             CEconItemAttributeDefinition_GetAttributeClass },

    { nullptr,  nullptr }
};