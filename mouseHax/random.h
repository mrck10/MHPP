#pragma once
#include <random>
#include <time.h>

class random
{
public:
	random();
	~random();

	static int range(int max_number) {
		srand((int)time(0));
		return rand() % max_number + 1;
	}
};

