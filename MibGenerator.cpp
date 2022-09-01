#include "MibGenerator.h"
#include "log.h"

MibGenerator::MibGenerator(const char *input, const char *output)
{
	json_entity = json_object_from_file(input);
	mib_file.open(output);
}

MibGenerator::~MibGenerator()
{
	if (json_entity)
		json_object_put(json_entity);
	mib_file.close();
}

int MibGenerator::check_status(void)
{
	int rc = 0;

	if (!json_entity)
	{
		log("cannot parse JSON-file\n");
		rc = -1;
	}
	if (!mib_file.good())
	{
		log("cannot parse create MIB-file\n");
		rc = -1;
	}

	return rc;
}


void MibGenerator::dump_json_entity(void)
{
	if (json_entity)
	{
		log("%s\n", json_object_to_json_string_ext(json_entity, JSON_C_TO_STRING_PRETTY));
	}
	else
	{
		log("{}");
	}
}

void MibGenerator::run(void)
{
	if (check_status() != 0)
	{
		return;
	}
}
