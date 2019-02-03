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
					for (int i=0;i<n;++i)
					{
						if (tmp != board[s].square[i].value)
						{
							if (tmp-1< 3 && tmp-1 >= 0)
							{
								board[s].square[i].susp[0].line[(tmp-1) % (n / 3)].second = false;
							}
							else if (tmp-1 < 6 && tmp-1 >= 3)
							{
								board[s].square[i].susp[1].line[(tmp-1) % (n / 3)].second = false;
							}
							else if (tmp-1 < 9 && tmp-1 >= 6)
							{
								board[s].square[i].susp[2].line[(tmp-1) % (n / 3)].second = false;
							}
						}
					}
				}
			}
		}
	}


	void verticalRefresh() 
	{
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (y >= 0 && y < 3)
				{
					if (x >= 0 && x < 3)
					{
						board[0].square[x % (n / 3)].susp[].line[] = false;
					}
					else if (x >= 3 && x < 6)
					{

					}
					else if (x >= 6 && x < 9)
					{

					}
				}
				else if (x >= 3 && x < 6)
				{
					if (x >= 0 && x < 3)
					{

					}
					else if (x >= 3 && x < 6)
					{

					}
					else if (x >= 6 && x < 9)
					{

					}
				}
				else if (x >= 6 && x < 9)
				{
					if (x >= 0 && x < 3)
					{

					}
					else if (x >= 3 && x < 6)
					{

					}
					else if (x >= 6 && x < 9)
					{

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
						if(k!=(n/3)-1)
							std::cout << "|";
					}
					std::cout << "\n";
				}
			}
			if (w != (n / 3)-1)
			{
				for (int i = 0; i < n*n / 3 * 2 + n / 3 - 1; ++i)
					std::cout << "-";
				std::cout << "\n";
			}
		}
	}
};