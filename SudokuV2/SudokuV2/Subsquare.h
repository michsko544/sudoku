#pragma once
#include "Suspect.h"

class Subsquare
{
protected:
	std::vector<Suspect> square;
	int certainNumbers{0};
	friend class Board;
public:
	Subsquare()
	{
		square.resize(n);
		for (int j = 0; j < n; ++j)
		{
			Suspect x;
			square.at(j) = x;
		}
	}
};