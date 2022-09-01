#include <cstdio>
#include <json-c/json.h>

#include "log.h"

static const char* input_file = NULL;
static const char* output_file = NULL;

static void usage()
{
	printf("usage:\n"
	       "mib-generator <input-file> <output-file>\n");
}

int main (int argc, char* argv[])
{
	if (argc != 3)
	{
		usage();
		return -1;
	}

	int rc = 0;
	input_file = argv[1];
	output_file = argv[2];

	json_object *mib_json = json_object_from_file(input_file);
	if (!mib_json)
	{
		log("cannot parse JSON-file(input_file == '%s')\n", input_file);
		rc = -1;
		goto exit;
	}

	printf("The json file:\n\n%s\n", json_object_to_json_string_ext(mib_json, JSON_C_TO_STRING_PRETTY));

exit:
	if (mib_json)
		json_object_put(mib_json);
	return rc;
}