#pragma once
#include <vector>
#include <utility>
#include "LineSuspect.h"

class Suspect : public LineSuspect
{
protected:
	int value{ -1 };
	std::vector<LineSuspect> susp;
	friend class Board;
public:
	void setValue(int x) { value = x; }
	Suspect()
	{
		for (int j = 0; j < n / 3; ++j)
		{
			LineSuspect x;
			susp.resize(n / 3);
			for (int i = 0; i < n / 3; ++i)
			{
				x.getLine()[i].first = (j*n / 3 + i+1);
			}
			susp.at(j) = x;
		}
	}
	void ShowLine(int i)
	{
		if (value != -1)
			if (i == 1)
				std::cout << "  " << value << "   ";
			else
				std::cout << "      ";
		else
		{
			for (int j = 0; j < n / 3; ++j)
			{
				if (susp.at(i).getLine()[j].second)
					std::cout << susp.at(i).getLine()[j].first << " ";
				else
					std::cout << "  ";
			}
		}
	}
};
