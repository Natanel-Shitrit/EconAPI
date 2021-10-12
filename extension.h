#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

// networkvar.h must be included before smsdk_ext.h !!!
#include "networkvar.h"
#include "smsdk_ext.h"
#include <server_class.h>

#ifdef PLATFORM_WINDOWS
#define VCallingConvention __thiscall
#else
#define VCallingConvention __cdecl
#endif

typedef CBaseEntity CBaseCombatWeapon;

/**
 * @brief Sample implementation of the SDK Extension.
 * Note: Uncomment one of the pre-defined virtual functions in order to use it.
 */
class EconAPI : public SDKExtension
{
public:
	/**
	 * @brief This is called after the initial loading sequence has been processed.
	 *
	 * @param error		Error message buffer.
	 * @param maxlength	Size of error message buffer.
	 * @param late		Whether or not the module was loaded after map load.
	 * @return			True to succeed loading, false to fail.
	 */
	virtual bool SDK_OnLoad(char* error, size_t maxlength, bool late);

	/**
	 * @brief This is called right before the extension is unloaded.
	 */
	virtual void SDK_OnUnload();

	/**
	 * @brief This is called once all known extensions have been loaded.
	 * Note: It is is a good idea to add natives here, if any are provided.
	 */
	virtual void SDK_OnAllLoaded();

public:
#if defined SMEXT_CONF_METAMOD
	/**
	 * @brief Called when Metamod is attached, before the extension version is called.
	 *
	 * @param error			Error buffer.
	 * @param maxlength		Maximum size of error buffer.
	 * @param late			Whether or not Metamod considers this a late load.
	 * @return				True to succeed, false to fail.
	 */
	virtual bool SDK_OnMetamodLoad(ISmmAPI* ismm, char* error, size_t maxlength, bool late);
#endif
};

/* Interfaces from SourceMod */
#define GameConf_EconAPI 0
#define GameConf_CSST 1

extern IGameConfig* g_pGameConf[2];
extern CGlobalVars* gpGlobals;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_