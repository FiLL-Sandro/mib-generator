#pragma once

#define log(_fmt, ...) \
	printf("<%s:%d> " _fmt , __func__, __LINE__, ##__VA_ARGS__)
