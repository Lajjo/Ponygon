#ifndef HELPER_H
#define HELPER_H

#include <cstdlib>

namespace Helper
{
	void randomSeed(int seed)
	{
		srand(seed);
	}

	int random(int min, int max)
	{
		if(max > min)
			return (min + rand()%(1+max-min));
		else
			return (max + rand()%(1+min-max));
	}
}

#endif