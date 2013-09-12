#include "version.h"
static const char __version_string[] = "Copyright (C) Cidana Corpration 2012 DVBTSubtitleDecoder Version:" CI_VERSION_STRING_;
const char* getVersion(void)
{
	return __version_string;
}

