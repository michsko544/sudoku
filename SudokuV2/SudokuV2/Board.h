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
	bool subsquareRefresh()
	{
		bool changes=false;
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
							const bool checkchange = board[s].square[i].susp[(tmp - 1) / (n / 3)].line[(tmp - 1) % (n / 3)].second;
							board[s].square[i].susp[(tmp-1)/(n/3)].line[(tmp-1) % (n / 3)].second = false;
							if (checkchange == true)
								changes |= true;
						}
					}
				}
			}
		}
		return changes;
	}

	bool horizontalRefresh()
	{
		bool changes = false;
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				if (board[(y / (n / 3))*n / 3 + x / (n / 3)].square[(y % (n / 3))*(n / 3) + x % (n / 3)].value != -1)
				{
					int tmp = board[(y / (n / 3))*n / 3 + x / (n / 3)].square[(y%(n/3))*(n/3)+x % (n / 3)].value;
					for (int elem = 0; elem < n; ++elem)
					{
						if (tmp != board[(y / (n / 3))*n / 3 + elem / (n / 3)].square[(y % (n / 3))*(n / 3) + elem % (n / 3)].value)
						{
							const bool checkchange = board[(y / (n / 3))*(n / 3) + elem / (n / 3)].square[(y % (n / 3))*(n / 3) + elem % (n / 3)].susp[(tmp - 1) / (n / 3)].line[(tmp - 1) % (n / 3)].second;
							board[(y / (n / 3))*(n / 3) + elem / (n / 3)].square[(y % (n / 3))*(n / 3) + elem % (n / 3)].susp[(tmp - 1) / (n / 3)].line[(tmp - 1) % (n / 3)].second = false;
							if(checkchange==true)
								changes |= true;
						}
					}
				}
			}
		}
		return changes;
	}

	bool verticalRefresh()
	{
		bool changes = false;
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < n; ++y)
			{
				if (board[(y / (n / 3))*n / 3 + x / (n / 3)].square[(y % (n / 3))*(n / 3) + x % (n / 3)].value != -1)
				{
					int tmp = board[(y / (n / 3))*n / 3 + x / (n / 3)].square[(y % (n / 3))*(n / 3) + x % (n / 3)].value;
					for (int elem = 0; elem < n; ++elem)
					{
						if (tmp != board[(elem / (n / 3))*n / 3 + x / (n / 3)].square[(elem % (n / 3))*(n / 3) + x % (n / 3)].value)
						{
							const bool checkchange = board[(elem / (n / 3))*(n / 3) + x / (n / 3)].square[(elem % (n / 3))*(n / 3) + x % (n / 3)].susp[(tmp - 1) / (n / 3)].line[(tmp - 1) % (n / 3)].second;
							board[(elem / (n / 3))*(n / 3) + x / (n / 3)].square[(elem % (n / 3))*(n / 3) + x % (n / 3)].susp[(tmp - 1) / (n / 3)].line[(tmp - 1) % (n / 3)].second = false;
							if (checkchange == true)
								changes |= true;
						}
					}
				}
			}
		}
		return changes;
	}

	bool setValues()
	{
		bool changes = false;
		for (int s = 0; s < n; ++s)
		{
			for(int i=0;i<n;++i)
			{
				if (board[s].square[i].value == -1)
				{
					int counter = 0;
					int whatSet = -1;
					for (int j = 0; j < n; ++j)
					{
						bool tmp=board[s].square[i].susp[j / (n / 3)].line[j % (n / 3)].second;
						if (tmp == true)
						{
							whatSet = board[s].square[i].susp[j / (n / 3)].line[j % (n / 3)].first;
							++counter;
						}

					}
					if (counter == 1)
					{
						board[s].square[i].setValue(whatSet);
						changes |= true;
					}
				}
			}
		}
		return changes;
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