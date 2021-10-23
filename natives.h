#ifndef _INCLUDE_SOURCEMOD_EXTENSION_NATIVES_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_NATIVES_H_

#define STRINGIFY_VAR(var) #var

#define SM_NATIVE_ERROR_IF_NULL(var) \
	if (!var) pContext->ThrowNativeError("%s == nullptr.", STRINGIFY_VAR(var));


enum EconAPI_ModelType
{
	ViewModel = 0,
	WorldModel,
	DroppedModel
};

extern const sp_nativeinfo_t g_ExtensionNatives[];

#endif // _INCLUDE_SOURCEMOD_EXTENSION_NATIVES_H_