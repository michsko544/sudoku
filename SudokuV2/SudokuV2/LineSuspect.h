#pragma once
#include <vector>
#include <utility>
#include "Suspect.h"

int n = 9;
class LineSuspect
{
protected:
	std::vector<std::pair<int,bool>> line;
public:
	LineSuspect() 
	{ 
		line.reserve(n / 3);
		for(int i=0;i<n/3;++i)
			line[i] = std::make_pair<int, bool>(0);
	}
};