#pragma once

enum {
	false = 0, true = 1,
};

_Static_assert(sizeof(char) == 1);

typedef unsigned char bool;
