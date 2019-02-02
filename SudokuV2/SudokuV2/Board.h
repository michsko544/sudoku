#pragma once
#include "Subsquare.h"
#include <algorithm>

class Board : public Subsquare
{
	std::vector<Subsquare> board;
public:
	Board()
	{
		board.resize(n);
		for (int j = 0; j < n; ++j)
		{
			Subsquare x;
			board.at(j) = x;
		}
	}

	void setData(int k, int l, int v)
	{
		this->board[k].square[l].setValue(v);
		++(this->board[k].certainNumbers);
		for (auto& it : this->board[k].square[l].susp)
		{
			for(int i=0;i<n/3;++i)
				if(it.line[i].first!=v)
					it.line[i].second = false; 
		}
	}
	void subsquareRefresh()
	{
		for (int s = 0; s < n; ++s)
		{
			for (int pod = 0; pod < n; ++pod)
			{
				if (board[s].square[pod].value != -1)
				{
					int tmp = board[s].square[pod].value;
					for (auto& it : board[s].square)
					{
						if (tmp < 3 && tmp>=0)
						{
							*it.susp[tmp].line[x].second;		//<--- taka skladnia bedzie
						}
						else if (tmp < 6 && tmp >= 3)
						{

						}
						else if (tmp < 9 && tmp >= 6)
						{

						}
					}
				}
			}
		}
	}

	void Show()
	{
		for (int w = 0; w < n / 3; ++w)
		{
			for (int p = 0; p < n / 3; ++p)
			{
				for (int l = 0; l < n / 3; ++l)
				{
					for (int k = 0; k < n / 3; ++k)
					{
						for (int c = 0; c < n / 3; ++c)
						{
							board[w*n / 3 + k].square[p*n / 3 + c].ShowLine(l);
						}
						std::cout << "|";
					}
					std::cout << "\n";
				}
			}
			for (int i = 0; i < n*n / 3 * 2 + n / 3 - 1; ++i)
				std::cout << "-";
			std::cout << "\n";
		}
	}
};