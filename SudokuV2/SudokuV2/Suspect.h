#pragma once
#include <vector>
#include <utility>
#include "LineSuspect.h"

class Suspect:public LineSuspect
{
	int value{ -1 };
	std::vector<LineSuspect> susp;
public:
	Suspect()
	{
		susp.reserve(n / 3);
		for (int i = 0; i < n/3; ++i)
		{
			LineSuspect x;
			x.line[i] = (i + 1);
			susp.at(i)=
		}
	}
};
