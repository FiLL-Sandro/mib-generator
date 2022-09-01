#pragma once

#include <json-c/json.h>
#include <fstream>

class MibGenerator
{
private:
	json_object *json_entity;
	std::fstream mib_file;

	int check_status(void);

public:
	MibGenerator():
		json_entity(NULL)
			{}
	MibGenerator(const char *input, const char *output);
	~MibGenerator();

	void dump_json_entity(void);
	void run(void);
};
