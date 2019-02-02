#pragma once
#include <vector>
#include <utility>

int n = 9;
class LineSuspect
{
protected:
	std::vector<std::pair<int,bool>> line;
	friend class Board;
public:
	LineSuspect() 
	{ 
		line.resize(n / 3);
		for(int i=0;i<n/3;++i)
			line[i] = std::make_pair<int, bool>(0,true);
	}
	std::vector<std::pair<int, bool>>& getLine() { return line; }

};