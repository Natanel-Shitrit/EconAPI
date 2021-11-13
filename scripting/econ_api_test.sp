#include <sourcemod>
#include <EconAPI>

#pragma newdecls required
#pragma semicolon 1

#define LOGGER_FILE_PATH "logs/econ_api.log"
#define LOGGER_MAX_MESSAGE_LENGTH 512

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
    LogToOpenFileEx(log_file, message_buffer);
}

Action Command_DumpEcon(int argc)
{
	DumpEcon();
	return Plugin_Handled;
}

void DumpEcon()
{
	Logger_Message("CEconItemDefinition.Count(): %d", CEconItemDefinition.Count());
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
		
		char def_name[64];
		if (item_def.GetDefinitionName(def_name, sizeof(def_name)) && item_def != CEconItemDefinition.FindByName(def_name))
		{
			Logger_Message("item_def != GetDefinitionName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		char econ_image[PLATFORM_MAX_PATH], model[PLATFORM_MAX_PATH];
		
		item_def.GetEconImage(econ_image, sizeof(econ_image));
		item_def.GetModel(DroppedModel, model, sizeof(model));
		Logger_Message("[%d] Definition Index: %d | Definition Name: %s | Loadout Slot: %d | Used By Team: %d | Num Supported Sticker Slots: %d | Econ Image: %s | Model: %s",
			i,
			item_def.DefinitionIndex,
			def_name,
			item_def.GetLoadoutSlot(),
			item_def.UsedByTeam,
			item_def.NumSupportedStickerSlots,
			econ_image,
			model
		);
	}
	
	Logger_Message("CPaintKit.Count(): %d", CPaintKit.Count());
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
		
		char description[64], description_tag[64], pattern[64], vmt_path[PLATFORM_MAX_PATH];
		paint_kit.GetDescription(description, sizeof(description));
		paint_kit.GetDescriptionTag(description_tag, sizeof(description_tag));
		paint_kit.GetPattern(pattern, sizeof(pattern));
		paint_kit.GetVmtPath(vmt_path, sizeof(vmt_path));
		Logger_Message("[%d] name: %s | ID: %d | Desc: %s | Desc Tag: %s | Pattern: %s | Rarity: %d | Style: %d | Wear: %f - %f | PatternScale: %f | VMT: %s",
			i,
			name,
			paint_kit.ID,
			description,
			description_tag,
			pattern,
			paint_kit.Rarity,
			paint_kit.Style,
			paint_kit.MinWear,
			paint_kit.MaxWear,
			paint_kit.PatternScale,
			vmt_path
		);
	}
	
	Logger_Message("CStickerKit.Count(): %d", CStickerKit.Count());
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
		
		char desc[64], item_name[64], material_path[PLATFORM_MAX_PATH], material_path_no_drips[PLATFORM_MAX_PATH], inv_img[PLATFORM_MAX_PATH], icon_small[PLATFORM_MAX_PATH], icon_large[PLATFORM_MAX_PATH];
		
		sticker_kit.GetDescriptionString(desc, sizeof(desc));
		sticker_kit.GetsItemName(item_name, sizeof(item_name));
		sticker_kit.GetMaterialPath(material_path, sizeof(material_path));
		sticker_kit.GetMaterialPathNoDrips(material_path_no_drips, sizeof(material_path_no_drips));
		sticker_kit.GetInventoryImage(inv_img, sizeof(inv_img));
		sticker_kit.GetIconURLSmall(icon_small, sizeof(icon_small));
		sticker_kit.GetIconURLLarge(icon_large, sizeof(icon_large));
		
		
		Logger_Message("[%d] name: %s | ID: %d | desc: %s | item_name: %s | material_path: %s | material_path_no_drips: %s | inv_img: %s | EventID: %d | EventTeamID: %d | PlayerID: %d | IsMaterialPathIsAbsolute: %d | ScaleMin: %f | ScaleMax: %f | icon_small: %s | icon_large: %s",
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
			sticker_kit.ScaleMin,
			sticker_kit.ScaleMax,
			icon_small,
			icon_large
		);
	}
	
	Logger_Message("CEconMusicDefinition.Count(): %d", CEconMusicDefinition.Count());
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
		
		char name_loc_token[128], desc_loc_token[128], display_model[PLATFORM_MAX_PATH], inv_img[PLATFORM_MAX_PATH];
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
		
		char loc_name[128], loc_desc[128];
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
		
		CEconItemListEntry item_list_entry;
		char item_def_name[64], paint_kit_name[64];
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
	}
	
	Logger_Message("CEconItemRarityDefinition.Count(): %d", CEconItemRarityDefinition.Count());
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
		
		char loc_key[64], wep_loc_key[64], character_loc_key[64], loot_list[64], recycle_loot_list[64], drop_sound[64], next_rarity[64];
		item_rarity.GetLocKey(loc_key, sizeof(loc_key));
		item_rarity.GetWepLocKey(wep_loc_key, sizeof(wep_loc_key));
		item_rarity.GetCharacterLocKey(character_loc_key, sizeof(character_loc_key));
		item_rarity.GetLootList(loot_list, sizeof(loot_list));
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
			loot_list,
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
	CEconItemQualityDefinition item_quality;
	for (int i = CEconItemQualityDefinition.Count() - 1; i >= 0; i--)
	{
		item_quality = CEconItemQualityDefinition.Get(i);
		
		if (!item_quality)
		{
			Logger_Message("item_quality == NULL");
			continue;
		}
		
		char name[64];
		if (item_quality.GetName(name, sizeof(name)) && item_quality != CEconItemQualityDefinition.FindByName(name))
		{
			Logger_Message("item_quality != GetName() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}
		
		char hex_color[8];
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
}