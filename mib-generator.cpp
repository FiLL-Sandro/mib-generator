#include <cstdio>
#include <json-c/json.h>

#include "log.h"
#include "MibGenerator.h"

static void usage()
{
	printf("usage:\n"
	       "mib-generator <input-file> <output-file>\n");
}

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		usage();
		return -1;
	}

	MibGenerator me(argv[1], argv[2]);
	me.run();

	me.dump_json_entity();

	return 0;
}
