/**
 * EconAPI
 * Copyright (C) 2022 Natanel 'LuqS' Shitrit. All rights reserved.
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

EconAPI g_EconAPI;
SMEXT_LINK(&g_EconAPI);

IGameConfig* g_pGameConf[2];

CEconItemSchema* g_pCEconItemSchema = nullptr;

bool EconAPI::SDK_OnLoad(char* error, size_t maxlength, bool late)
{
	char conf_error[255];

	if (!gameconfs->LoadGameConfigFile("EconAPI.games", &g_pGameConf[GameConf_EconAPI], conf_error, sizeof(conf_error)))
	{
		snprintf(error, maxlength, "Could not read EconAPI.games: %s", conf_error);

		return false;
	}

	if (!gameconfs->LoadGameConfigFile("sm-cstrike.games", &g_pGameConf[GameConf_CSST], conf_error, sizeof(conf_error)))
	{
		snprintf(error, maxlength, "Could not read sm-cstrike.games: %s", conf_error);

		return false;
	}

	sharesys->AddNatives(myself, g_ExtensionNatives);
	sharesys->RegisterLibrary(myself, "EconAPI");

	return true;
}

void EconAPI::SDK_OnAllLoaded()
{
	g_pCEconItemSchema = new CEconItemSchema();
}

void EconAPI::SDK_OnUnload()
{
	gameconfs->CloseGameConfigFile(g_pGameConf[GameConf_EconAPI]);
	gameconfs->CloseGameConfigFile(g_pGameConf[GameConf_CSST]);
}