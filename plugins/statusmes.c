// statusmes by Kubix ( test create plugins :D )
#include "common/hercules.h"
#include "map/map.h"
#include "map/script.h"

#include "common/HPMDataCheck.h"

HPExport struct hplugin_info pinfo = {
	"statusmes",    // Plugin name
	SERVER_TYPE_MAP,// Which server types this plugin works with?
	"1.0",       // Plugin version
	HPM_VERSION, // HPM Version (don't change, macro is automatically updated)
};

BUILDIN(statusmes)
{
	const char *str;
	str = script_getstr( st, 2 );
	ShowStatus( "%s\n", str );
	return true;
}

HPExport void server_preinit(void) {
}

HPExport void plugin_init(void) {
	addScriptCommand("statusmes", "v", statusmes );
}