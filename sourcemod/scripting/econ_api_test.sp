#include <sourcemod>
#include <EconAPI>

#pragma newdecls required
#pragma semicolon 1

#define LOGGER_FILE_PATH "logs/econ_api.log"
#define LOGGER_MAX_MESSAGE_LENGTH 8192

public Plugin myinfo = 
{
	name = "[EconAPI] Test",
	author = "Natanel 'LuqS'",
	description = "",
	version = "1.0.0",
	url = "https://steamcommunity.com/id/luqsgood || Discord: LuqS#6505"
};

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max)
{
    if (GetEngineVersion() != Engine_CSGO)
    {
        strcopy(error, err_max, "This plugin was made for use with CS:GO only.");
        return APLRes_Failure;
    }
    
    return APLRes_Success;
}

public void OnPluginStart()
{
	RegServerCmd("sm_dump_econ", Command_DumpEcon);
}

void Logger_Message(char[] format, any ...)
{
    static File log_file;
    if (!log_file)
    {
        // Create file path.
        char log_file_path[PLATFORM_MAX_PATH];
        BuildPath(Path_SM, log_file_path, sizeof(log_file_path), LOGGER_FILE_PATH);

        // Open the file.
        if (!(log_file = OpenFile(log_file_path, "a")))
        {
            LogError("Logger failed to initialize, please contact plugin author.");
            return;
        }
    }

    // Create buffer for formatted message.
    char message_buffer[LOGGER_MAX_MESSAGE_LENGTH];

    // Format message into buffer.
    VFormat(message_buffer, sizeof(message_buffer), format, 2);

    // Log message.
    log_file.WriteLine(message_buffer);
    log_file.Flush();
}

Action Command_DumpEcon(int argc)
{
	DumpEcon();
	return Plugin_Handled;
}

void DumpEcon()
{
	Logger_Message("CEconItemDefinition.Count(): %d", CEconItemDefinition.Count());
	char base_name[64],
		 type_name[64],
		 desc[64],
		 view_model[PLATFORM_MAX_PATH],
		 world_model[PLATFORM_MAX_PATH],
		 dropped_model[PLATFORM_MAX_PATH],
		 holster_model[PLATFORM_MAX_PATH],
		 extra_wearable_model[PLATFORM_MAX_PATH],
		 inv_model[PLATFORM_MAX_PATH],
		 icon_default_image[PLATFORM_MAX_PATH],
		 brass_model[PLATFORM_MAX_PATH],
		 zoom_in_sound[PLATFORM_MAX_PATH],
		 zoom_out_sound[PLATFORM_MAX_PATH],
		 icon_small[64],
		 icon_large[64],
		 unknown1[64],
		 unknown2[64],
		 particle_file[PLATFORM_MAX_PATH],
		 particle_snapshot_file[PLATFORM_MAX_PATH],
		 loot_list_name[64],
		 classname[64],
		 log_classname[64],
		 icon_classname[PLATFORM_MAX_PATH],
		 def_name[64],
		 armory_desc[64],
		 class_token[64],
		 slot_token[64],
		 holiday_restrection[64],
		 inv_image[PLATFORM_MAX_PATH],
		 rarity[64], quality[64], forced_quality[64], default_drop_quality[64];
	
	CEconItemDefinition item_def;
	for (int i = CEconItemDefinition.Count() - 1; i >= 0; i--)
	{
		item_def = CEconItemDefinition.Get(i);
		
		if (!item_def)
		{
			Logger_Message("item_def == NULL");
			continue;
		}
		
		if (item_def != CEconItemDefinition.FindByDefIndex(item_def.DefinitionIndex))
		{
			Logger_Message("item_def != FindByIndex() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		if (item_def.GetDefinitionName(def_name, sizeof(def_name)) && item_def != CEconItemDefinition.FindByName(def_name))
		{
			Logger_Message("item_def != GetDefinitionName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		if (item_def.ItemRarity) item_def.ItemRarity.GetName(rarity, sizeof(rarity));
		if (item_def.ItemQuality) item_def.ItemQuality.GetName(quality, sizeof(quality));
		if (item_def.ForcedItemQuality) item_def.ForcedItemQuality.GetName(forced_quality, sizeof(forced_quality));
		if (item_def.DefaultDropItemQuality) item_def.DefaultDropItemQuality.GetName(default_drop_quality, sizeof(default_drop_quality));
		
		item_def.GetBaseName(base_name, sizeof(base_name));
		item_def.GetTypeName(type_name, sizeof(type_name));
		item_def.GetDescription(desc, sizeof(desc));
		item_def.GetModel(ViewModel, view_model, sizeof(view_model));
		item_def.GetModel(WorldModel, world_model, sizeof(world_model));
		item_def.GetModel(DroppedModel, dropped_model, sizeof(dropped_model));
		item_def.GetModel(HolsteredModel, holster_model, sizeof(holster_model));
		item_def.GetModel(WorldExtraWearableModel, extra_wearable_model, sizeof(extra_wearable_model));
		item_def.GetModel(InventoryModel, inv_model, sizeof(inv_model));
		item_def.GetIconDefaultImage(icon_default_image, sizeof(icon_default_image));
		item_def.GetBrassModelOverride(brass_model, sizeof(brass_model));
		item_def.GetZoomInSound(zoom_in_sound, sizeof(zoom_in_sound));
		item_def.GetZoomOutSound(zoom_out_sound, sizeof(zoom_out_sound));
		item_def.GetIconURLSmall(icon_small, sizeof(icon_small));
		item_def.GetIconURLLarge(icon_large, sizeof(icon_large));
		item_def.GetUnknown1(unknown1, sizeof(unknown1));
		item_def.GetUnknown2(unknown2, sizeof(unknown2));
		item_def.GetParticleFile(particle_file, sizeof(particle_file));
		item_def.GetParticleSnapshotFile(particle_snapshot_file, sizeof(particle_snapshot_file));
		item_def.GetLootListName(loot_list_name, sizeof(loot_list_name));
		item_def.GetItemClassname(classname, sizeof(classname));
		item_def.GetItemLogClassname(log_classname, sizeof(log_classname));
		item_def.GetItemIconClassname(icon_classname, sizeof(icon_classname));
		item_def.GetArmoryDescription(armory_desc, sizeof(armory_desc));
		item_def.GetClassToken(class_token, sizeof(class_token));
		item_def.GetSlotToken(slot_token, sizeof(slot_token));
		item_def.GetHolidayRestriction(holiday_restrection, sizeof(holiday_restrection));
		item_def.GetInventoryImage(inv_image, sizeof(inv_image));
		Logger_Message(
			"[%d] IsEnabled: %d \
			 | HasProperName: %d \
			 | ShouldLoadOnDemand: %d \
			 | HasBeenLoaded: %d \
			 | HideBodyGroupsDeployedOnly: %d \
			 | ShouldAttachToHands: %d \
			 | ShouldAttachToHandsVMOnly: %d \
			 | ShouldFlipViewModel: %d \
			 | IsActingAsWearable: %d \
			 | ShoulDisableStyleSelector: %d \
			 | IsHidden: %d \
			 | ShouldShowInArmory: %d \
			 | IsBaseItem: %d \
			 | IsDefaultSlotItem: %d \
			 | IsImported: %d \
			 | IsOnePerAccountCDKEY: %d \
			 | IsPackBundle: %d \
			 | IsPackItem: %d \
			 | IsAllowedInMatch: %d \
			 | IsPublicItem: %d \
			 | IgnoreInCollectionView: %d \
			 | MinItemLevel: %d \
			 | MaxItemLevel: %d \
			 | ItemRarity: %s\
			 | ItemQuality: %s\
			 | ForcedItemQuality: %s\
			 | DefaultDropItemQuality: %s\
			 | DefaultDropQuantity: %d \
			 | PopularitySeed: %d \
			 | DefinitionIndex: %d \
			 | ItemTypeID: %d \
			 | NumConcreteItems: %d \
			 | NumSupportedStickerSlots: %d \
			 | SoundMaterialID: %d \
			 | ArmoryRemap: %d \
			 | StoreRemap: %d \
			 | DropType: %d \
			 | SubType: %d \
			 | ExpirationTime: %d \
			 | DefCreationTime: %d \
			 | EconItemType: %d \
			 | Capabilities: %d \
			 | EquipRegionMask: %d \
			 | EquipRegionConflictMask: %d \
			 | strings: \
			 | Definition Name: %s\
			 | Base Name: %s \
			 | Type Name: %s \
			 | GetDescription: %s \
			 | Base Player Display Model: %s \
			 | World Display Model: %s \
			 | World Dropped Model: %s \
			 | Holstered Model: %s \
			 | World Extra Wearable Model: %s \
			 | Inventory Model: %s \
			 | Icon Default Image: %s \
			 | Brass Model Override: %s \
			 | Zoom In Sound: %s \
			 | Zoom Out Sound: %s \
			 | Icon URL Small: %s \
			 | Icon URL Large: %s \
			 | Unknown1: %s \
			 | Unknown2: %s \
			 | Particle File: %s \
			 | Particle Snapshot File: %s \
			 | Loot List Name: %s \
			 | Item Classname: %s \
			 | Item Log Classname: %s \
			 | Item Icon Classname: %s \
			 | Armory Description: %s \
			 | Class Token: %s \
			 | Slot Token: %s \
			 | Holiday Restriction: %s \
			 | Econ Image: %s \
			 | Loadout Slot: %d \
			 | Used By Team: %d \
			 ",
			i,
			item_def.IsEnabled,
			item_def.HasProperName,
			item_def.ShouldLoadOnDemand,
			item_def.HasBeenLoaded,
			item_def.HideBodyGroupsDeployedOnly,
			item_def.ShouldAttachToHands,
			item_def.ShouldAttachToHandsVMOnly,
			item_def.ShouldFlipViewModel,
			item_def.IsActingAsWearable,
			item_def.ShoulDisableStyleSelector,
			item_def.IsHidden,
			item_def.ShouldShowInArmory,
			item_def.IsBaseItem,
			item_def.IsDefaultSlotItem,
			item_def.IsImported,
			item_def.IsOnePerAccountCDKEY,
			item_def.IsPackBundle,
			item_def.IsPackItem,
			item_def.IsAllowedInMatch,
			item_def.IsPublicItem,
			item_def.IgnoreInCollectionView,
			item_def.MinItemLevel,
			item_def.MaxItemLevel,
			rarity,
			quality,
			forced_quality,
			default_drop_quality,
			item_def.DefaultDropQuantity,
			item_def.PopularitySeed,
			item_def.DefinitionIndex,
			item_def.ItemTypeID,
			item_def.NumConcreteItems,
			item_def.NumSupportedStickerSlots,
			item_def.SoundMaterialID,
			item_def.ArmoryRemap,
			item_def.StoreRemap,
			item_def.DropType,
			item_def.SubType,
			item_def.ExpirationTime,
			item_def.DefCreationTime,
			item_def.EconItemType,
			item_def.Capabilities,
			item_def.EquipRegionMask,
			item_def.EquipRegionConflictMask,
			def_name,
			base_name,
			type_name,
			desc,
			view_model,
			world_model,
			dropped_model,
			holster_model,
			extra_wearable_model,
			inv_model,
			icon_default_image,
			brass_model,
			zoom_in_sound,
			zoom_out_sound,
			icon_small,
			icon_large,
			unknown1,
			unknown2,
			particle_file,
			particle_snapshot_file,
			loot_list_name,
			classname,
			log_classname,
			icon_classname,
			armory_desc,
			class_token,
			slot_token,
			holiday_restrection,
			inv_image,
			item_def.GetLoadoutSlot(),
			item_def.UsedByTeam
		);
	}
	
	Logger_Message("CPaintKit.Count(): %d", CPaintKit.Count());
	char description[64],
		 description_tag[64],
		 same_name_family_aggregate[64],
		 pattern[64],
		 normal[64],
		 logo_material[PLATFORM_MAX_PATH],
		 vmt_path[PLATFORM_MAX_PATH];
	
	CPaintKit paint_kit;
	for (int i = CPaintKit.Count() - 1; i >= 0; i--)
	{
		paint_kit = CPaintKit.Get(i);
	
		if (!paint_kit)
		{
			Logger_Message("paint_kit == NULL");
			continue;
		}
		
		if (paint_kit != CPaintKit.FindByID(paint_kit.ID))
		{
			Logger_Message("item_def != FindByID() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		char name[64];
		if (paint_kit.GetName(name, sizeof(name)) && paint_kit != CPaintKit.FindByName(name))
		{
			Logger_Message("paint_kit != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		paint_kit.GetDescription(description, sizeof(description));
		paint_kit.GetDescriptionTag(description_tag, sizeof(description_tag));
		paint_kit.GetSameNameFamilyAggregate(same_name_family_aggregate, sizeof(same_name_family_aggregate));
		paint_kit.GetPattern(pattern, sizeof(pattern));
		paint_kit.GetNormal(normal, sizeof(normal));
		paint_kit.GetLogoMaterial(logo_material, sizeof(logo_material));
		paint_kit.GetVmtPath(vmt_path, sizeof(vmt_path));
		
		if (paint_kit.Rarity) paint_kit.Rarity.GetName(rarity, sizeof(rarity));
		
		Logger_Message("[%d] name: %s \
						| ID: %d \
						| Desc: %s \
						| Desc Tag: %s \
						| SameNameFamilyAggregate: %s \
						| Pattern: %s \
						| Normal: %s \
						| LogoMaterial: %s \
						| Rarity: %s \
						| Style: %d \
						| Wear (%f): %f - %f \
						| FixedSeed: %d \
						| PhongExponent: %d \
						| PhongAlbedoBoost: %d \
						| PhongIntensity: %d \
						| PatternScale: %f \
						| PatternOffsetXStart: %f \
						| PatternOffsetXEnd: %f \
						| PatternOffsetYStart: %f \
						| PatternOffsetYEnd: %f \
						| PatternRotateStart: %f \
						| PatternRotateEnd: %f \
						| LogoScale: %f \
						| LogoOffsetX: %f \
						| LogoOffsetY: %f \
						| LogoRotation: %f \
						| IgnoreWeaponSizeScale: %d \
						| ViewModelExponentOverrideSize: %d \
						| OnlyFirstMaterial: %d \
						| UseNormal: %d \
						| Pearlescent: %f \
						| VMT: %s",
			i,
			name,
			paint_kit.ID,
			description,
			description_tag,
			same_name_family_aggregate,
			pattern,
			normal,
			logo_material,
			rarity,
			paint_kit.Style,
			paint_kit.DefaultWear,
			paint_kit.MinWear,
			paint_kit.MaxWear,
			paint_kit.FixedSeed,
			paint_kit.PhongExponent,
			paint_kit.PhongAlbedoBoost,
			paint_kit.PhongIntensity,
			paint_kit.PatternScale,
			paint_kit.PatternOffsetXStart,
			paint_kit.PatternOffsetXEnd,
			paint_kit.PatternOffsetYStart,
			paint_kit.PatternOffsetYEnd,
			paint_kit.PatternRotateStart,
			paint_kit.PatternRotateEnd,
			paint_kit.LogoScale,
			paint_kit.LogoOffsetX,
			paint_kit.LogoOffsetY,
			paint_kit.LogoRotation,
			paint_kit.IgnoreWeaponSizeScale,
			paint_kit.ViewModelExponentOverrideSize,
			paint_kit.OnlyFirstMaterial,
			paint_kit.UseNormal,
			paint_kit.Pearlescent,
			vmt_path
		);
		
		int color[4];
		Logger_Message("CPaintKit Colors");
		for (int j; j < paint_kit.NumColors; j++)
		{
			paint_kit.GetRGBAColor(j, color);
			Logger_Message("\t[%d] %d %d %d %d",
				j,
				color[0],
				color[1],
				color[2],
				color[3]
			);
		}
		
		Logger_Message("CPaintKit Logo Colors");
		for (int j; j < paint_kit.NumColors; j++)
		{
			paint_kit.GetRGBALogoColor(j, color);
			Logger_Message("\t[%d] %d %d %d %d",
				j,
				color[0],
				color[1],
				color[2],
				color[3]
			);
		}
	}
	
	Logger_Message("CStickerKit.Count(): %d", CStickerKit.Count());
	char item_name[64],
		 material_path[PLATFORM_MAX_PATH],
		 material_path_no_drips[PLATFORM_MAX_PATH],
		 inv_img[PLATFORM_MAX_PATH];

	CStickerKit sticker_kit;
	for (int i = CStickerKit.Count() - 1; i >= 0; i--)
	{
		sticker_kit = CStickerKit.Get(i);
	
		if (!sticker_kit)
		{
			Logger_Message("sticker_kit == NULL");
			continue;
		}
		
		if (sticker_kit != CStickerKit.FindByID(sticker_kit.ID))
		{
			Logger_Message("item_def != FindByID() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		char name[64];
		if (sticker_kit.GetName(name, sizeof(name)) && sticker_kit != CStickerKit.FindByName(name))
		{
			Logger_Message("sticker_kit != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		sticker_kit.GetDescriptionString(desc, sizeof(desc));
		sticker_kit.GetsItemName(item_name, sizeof(item_name));
		sticker_kit.GetMaterialPath(material_path, sizeof(material_path));
		sticker_kit.GetMaterialPathNoDrips(material_path_no_drips, sizeof(material_path_no_drips));
		sticker_kit.GetInventoryImage(inv_img, sizeof(inv_img));
		sticker_kit.GetIconURLSmall(icon_small, sizeof(icon_small));
		sticker_kit.GetIconURLLarge(icon_large, sizeof(icon_large));
		
		
		Logger_Message("[%d] name: %s | ID: %d | desc: %s | item_name: %s | material_path: %s | material_path_no_drips: %s | inv_img: %s | EventID: %d | EventTeamID: %d | PlayerID: %d | IsMaterialPathIsAbsolute: %d | RotateStart: %f | RotateEnd: %f | ScaleMin: %f | ScaleMax: %f | icon_small: %s | icon_large: %s",
			i,
			name,
			sticker_kit.ID,
			desc,
			item_name,
			material_path,
			material_path_no_drips,
			inv_img,
			sticker_kit.EventID,
			sticker_kit.EventTeamID,
			sticker_kit.PlayerID,
			sticker_kit.IsMaterialPathIsAbsolute,
			sticker_kit.RotateStart,
			sticker_kit.RotateEnd,
			sticker_kit.ScaleMin,
			sticker_kit.ScaleMax,
			icon_small,
			icon_large
		);
	}
	
	Logger_Message("CEconMusicDefinition.Count(): %d", CEconMusicDefinition.Count());
	char name_loc_token[128],
		 desc_loc_token[128],
		 display_model[PLATFORM_MAX_PATH];

	CEconMusicDefinition music_def;
	for (int i = CEconMusicDefinition.Count() - 1; i >= 0; i--)
	{
		music_def = CEconMusicDefinition.Get(i);
		
		if (!music_def)
		{
			Logger_Message("music_def == NULL");
			continue;
		}
		
		if (music_def != CEconMusicDefinition.FindByID(music_def.ID))
		{
			Logger_Message("music_def != FindByID() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		char name[64];
		if (music_def.GetName(name, sizeof(name)) && music_def != CEconMusicDefinition.FindByName(name))
		{
			Logger_Message("music_def != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		music_def.GetNameLocToken(name_loc_token, sizeof(name_loc_token));
		music_def.GetLocDescription(desc_loc_token, sizeof(desc_loc_token));
		music_def.GetPedestalDisplayModel(display_model, sizeof(display_model));
		music_def.GetInventoryImage(inv_img, sizeof(inv_img));
		
		Logger_Message("[%d] ID: %d | NameLocToken: %s | LocDescription: %s | PedestalDisplayModel: %s | InventoryImage: %s",
			i,
			music_def.ID,
			name_loc_token,
			desc_loc_token,
			display_model,
			inv_img
		);
	}
	
	Logger_Message("CEconItemSetDefinition.Count(): %d", CEconItemSetDefinition.Count());
	char loc_name[128],
		 loc_desc[128],
		 item_def_name[64],
		 paint_kit_name[64];
	
	CEconItemListEntry item_list_entry;
	CEconItemSetDefinitionAttribute item_list_attr;
	CEconItemSetDefinition item_set;
	for (int i = CEconItemSetDefinition.Count() - 1; i >= 0; i--)
	{
		item_set = CEconItemSetDefinition.Get(i);
		
		if (!item_set)
		{
			Logger_Message("item_set == NULL");
			continue;
		}
		
		char name[64];
		if (item_set.GetName(name, sizeof(name)) && item_set != CEconItemSetDefinition.FindByName(name))
		{
			Logger_Message("item_set != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}

		item_set.GetLocalizedName(loc_name, sizeof(loc_name));
		item_set.GetLocalizedDescription(loc_desc, sizeof(loc_desc));
		
		Logger_Message("[%d] name: %s | LocalizedName: %s | LocalizedDescription: %s | BundleItemDef: %d | IsCollection: %d | IsHiddenSet: %d",
			i,
			name,
			loc_name,
			loc_desc,
			item_set.BundleItemDef,
			item_set.IsCollection,
			item_set.IsHiddenSet
		);
		
		for (int j = item_set.ItemCount - 1; j >= 0; j--)
		{
			item_list_entry = item_set.GetItem(j);
			
			item_list_entry.ItemDef.GetDefinitionName(item_def_name, sizeof(item_def_name));
			item_list_entry.PaintKit.GetName(paint_kit_name, sizeof(paint_kit_name));
			
			Logger_Message("\t[%d] ItemDef: %s | PaintKit: %s | PaintKitSeed: %d | PaintKitWear: %f | StickerKit: %X | MusicKit: %X",
				j,
				item_def_name,
				paint_kit_name,
				item_list_entry.PaintKitSeed,
				item_list_entry.PaintKitWear,
				item_list_entry.StickerKit,
				item_list_entry.MusicKit
			);
		}
		
		Logger_Message("\tAttributeCount: %d", item_set.AttributeCount);
		for (int j = item_set.AttributeCount - 1; j >= 0; j--)
		{
			item_list_attr = item_set.GetAttribute(j);
			
			Logger_Message("\t[%d] AttributeDefIndex: %d | Value: %d / %f",
				j,
				item_list_attr.AttributeDefIndex,
				item_list_attr.Value,
				item_list_attr.Value
			);
		}
	}
	
	Logger_Message("CEconItemRarityDefinition.Count(): %d", CEconItemRarityDefinition.Count());
	char loc_key[64],
		 wep_loc_key[64],
		 character_loc_key[64],
		 recycle_loot_list[64],
		 drop_sound[64],
		 next_rarity[64];

	CEconItemRarityDefinition item_rarity;
	for (int i = CEconItemRarityDefinition.Count() - 1; i >= 0; i--)
	{
		item_rarity = CEconItemRarityDefinition.Get(i);
		
		if (!item_rarity)
		{
			Logger_Message("item_rarity == NULL");
			continue;
		}
		
		char name[64];
		if (item_rarity.GetName(name, sizeof(name)) && item_rarity != CEconItemRarityDefinition.FindByName(name))
		{
			Logger_Message("item_rarity != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		item_rarity.GetLocKey(loc_key, sizeof(loc_key));
		item_rarity.GetWepLocKey(wep_loc_key, sizeof(wep_loc_key));
		item_rarity.GetCharacterLocKey(character_loc_key, sizeof(character_loc_key));
		item_rarity.GetLootList(loot_list_name, sizeof(loot_list_name));
		item_rarity.GetRecycleLootList(recycle_loot_list, sizeof(recycle_loot_list));
		item_rarity.GetDropSound(drop_sound, sizeof(drop_sound));
		item_rarity.GetNextRarity(next_rarity, sizeof(next_rarity));
		
		Logger_Message("[%d] db_value: %d | name: %s | loc_key: %s | wep_loc_key: %s | character_loc_key: %s | loot_list : %s | recycle_loot_list : %s | drop_sound : %s | attr_color: %d | next_rarity : %s | white_count: %d | black_count: %d | weight: %f",
			i,
			item_rarity.DBValue,
			name,
			loc_key,
			wep_loc_key,
			character_loc_key,
			loot_list_name,
			recycle_loot_list,
			drop_sound,
			item_rarity.AttribColor,
			next_rarity,
			item_rarity.WhiteCount,
			item_rarity.BlackCount,
			item_rarity.Weight
		);
	}
	
	Logger_Message("CEconItemQualityDefinition.Count(): %d", CEconItemQualityDefinition.Count());
	char name[64],
		 hex_color[8];
	
	CEconItemQualityDefinition item_quality;
	for (int i = CEconItemQualityDefinition.Count() - 1; i >= 0; i--)
	{
		item_quality = CEconItemQualityDefinition.Get(i);
		
		if (!item_quality)
		{
			Logger_Message("item_quality == NULL");
			continue;
		}

		if (item_quality.GetName(name, sizeof(name)) && item_quality != CEconItemQualityDefinition.FindByName(name))
		{
			Logger_Message("item_quality != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		item_quality.GetHexColor(hex_color, sizeof(hex_color));
		
		Logger_Message("[%d] db_value: %d | name: %s | weight: %d | RequiresExplicitMatches: %d | CanSupportSet: %d | hex_color: %s",
			i,
			item_quality.DBValue,
			name,
			item_quality.Weight,
			item_quality.RequiresExplicitMatches,
			item_quality.CanSupportSet,
			hex_color
		);
	}
	
	Logger_Message("CEconLootListDefinition.Count: %d", CEconLootListDefinition.Count());
	
	CEconLootListDefinition loot_list;
	for (int i = CEconLootListDefinition.Count() - 1; i >= 0; i--)
	{
		loot_list = CEconLootListDefinition.Get(i);
	
		if (!loot_list)
		{
			Logger_Message("loot_list == NULL");
			continue;
		}
		
		loot_list.GetName(loot_list_name, sizeof(loot_list_name));
		
		Logger_Message("[%d = %X] name: %s | HeroID: %d | PublicListContents: %d | ContainsAutographedStickers: %d | ContainsOrganizationsStickers: %d | ContainsOrganizationsPatches: %d | WillProduceStattrak: %d | TotalWeight: %f | ServerList: %d",
			i,
			loot_list,
			loot_list_name,
			loot_list.HeroID,
			loot_list.PublicListContents,
			loot_list.ContainsAutographedStickers,
			loot_list.ContainsOrganizationsStickers,
			loot_list.ContainsOrganizationsPatches,
			loot_list.WillProduceStattrak,
			loot_list.TotalWeight,
			loot_list.ServerList
		);
		
		Logger_Message("\tloot_list.AdditionalDropCount: %d", loot_list.AdditionalDropCount);
		CEconAdditionalDrop additional_drop;
		for (int j = loot_list.AdditionalDropCount - 1; j >= 0; j--)
		{
			additional_drop = loot_list.GetAdditionalDrop(j);
			
			if (!additional_drop)
			{
				Logger_Message("\tadditional_drop == NULL");
				continue;
			}
			
			char loot_list_def_name[64];
			additional_drop.LootListDefinition.GetName(loot_list_def_name, sizeof(loot_list_def_name));
			
			Logger_Message("\t[%d] Chance: %f | PremiumOnly: %d | LootListDefinition: %s",
				additional_drop.Chance,
				additional_drop.PremiumOnly,
				loot_list_def_name
			);
		}
		
		Logger_Message("\tloot_list.ItemCount: %d", loot_list.ItemCount);
		for (int j = loot_list.ItemCount - 1; j >= 0; j--)
		{
			item_list_entry = loot_list.GetItem(j);
			
			if (!item_list_entry)
			{
				Logger_Message("\titem_list_entry == NULL");
				continue;
			}
			
			if (item_list_entry.ItemDef)
			{
				item_list_entry.ItemDef.GetDefinitionName(item_def_name, sizeof(item_def_name));
			}
			else
			{
				Logger_Message("\tNO ItemDef");
			}
			
			if (item_list_entry)
			{
				item_list_entry.PaintKit.GetName(paint_kit_name, sizeof(paint_kit_name));
			}
			else
			{
				Logger_Message("\tNO PaintKit");
			}
			
			Logger_Message("\t[%d] ItemDef: %s | PaintKit: %s | PaintKitSeed: %d | PaintKitWear: %f | StickerKit: %X | MusicKit: %X",
				j,
				item_def_name,
				paint_kit_name,
				item_list_entry.PaintKitSeed,
				item_list_entry.PaintKitWear,
				item_list_entry.StickerKit,
				item_list_entry.MusicKit
			);
		}
	}
	
	
	Logger_Message("CEconItemAttributeDefinition.Count: %d", CEconItemAttributeDefinition.Count());
	char item_attr_def_name[64],
		 desc_tag[64],
		 attr_class[64];
	
	CEconItemAttributeDefinition item_attr_def;
	for (int i = CEconItemAttributeDefinition.Count() - 1; i >= 0; i--)
	{
		item_attr_def = CEconItemAttributeDefinition.Get(i);
		
		if (!item_attr_def)
		{
			Logger_Message("item_attr_def == NULL");
			continue;
		}
		
		item_attr_def.GetDefinitionName(item_attr_def_name, sizeof(item_attr_def_name));
		item_attr_def.GetDescription(desc, sizeof(desc));
		item_attr_def.GetDescriptionTag(desc_tag, sizeof(desc_tag));
		item_attr_def.GetArmoryDescription(armory_desc, sizeof(armory_desc));
		item_attr_def.GetAttributeClass(attr_class, sizeof(attr_class));
		
		Logger_Message(
			"[%d = %X] Definition Name: %s \
			 | IsHidden: %d \
			 | IsWebSchemaOutputForced: %d \
			 | IsStoredAsInteger: %d \
			 | IsInstanceData: %d \
			 | AssetClassAttrExportRule: %d \
			 | AssetClassBucket: %d \
			 | EffectType: %d \
			 | DescriptionFormat: %d \
			 | Description: %s \
			 | Description Tag: %s \
			 | Armory Description: %s \
			 | Score: %d \
			 | Attribute Class: %s",
			i,
			item_attr_def,
			item_attr_def_name,
			item_attr_def.IsHidden,
			item_attr_def.IsWebSchemaOutputForced,
			item_attr_def.IsStoredAsInteger,
			item_attr_def.IsInstanceData,
			item_attr_def.AssetClassAttrExportRule,
			item_attr_def.AssetClassBucket,
			item_attr_def.EffectType,
			item_attr_def.DescriptionFormat,
			desc,
			desc_tag,
			armory_desc,
			item_attr_def.Score,
			attr_class
		);
	}
}