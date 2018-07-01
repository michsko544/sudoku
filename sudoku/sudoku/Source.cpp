#include <iostream>

using namespace std;


struct suspect
{	
	int one=1;
	int two=2;
	int three=3;
	int four=4;
	int five=5;
	int six=6;
	int seven=7;
	int eight=8;
	int nine=9;
};

struct kratka
{
	int liczba;
	suspect* podejrzani;
	int ile_susp=9;
};

void refresh(kratka** tab, int &i, int &j)
{
	if (tab[i][j].ile_susp = 1)
	{
		if (tab[i][j].podejrzani->one = 1)
			tab[i][j].liczba = 1;
		else if (tab[i][j].podejrzani->two = 2)
			tab[i][j].liczba = 2;
		else if (tab[i][j].podejrzani->three = 3)
			tab[i][j].liczba = 3;
		else if (tab[i][j].podejrzani->four = 4)
			tab[i][j].liczba = 4;
		else if (tab[i][j].podejrzani->five = 5)
			tab[i][j].liczba = 5;
		else if (tab[i][j].podejrzani->six = 6)
			tab[i][j].liczba = 6;
		else if (tab[i][j].podejrzani->seven = 7)
			tab[i][j].liczba = 7;
		else if (tab[i][j].podejrzani->eight = 8)
			tab[i][j].liczba = 8;
		else if (tab[i][j].podejrzani->nine = 9)
			tab[i][j].liczba = 9;
		else
			cout << "Blad licznika podejrzanych\n";
	}

}

bool poziom(kratka** tab, int &n, int &i, int &j)
{
	int z = 0;
	for (int p = 0; p < n; p++)
	{
		if (i != p && !tab[i][j].liczba)
		{
			switch (tab[p][j].liczba)
			{
			case 1:

				tab[i][j].podejrzani->one = NULL;
				tab[i][j].ile_susp--;
				break;

			case 2:

				tab[i][j].podejrzani->two = NULL;
				tab[i][j].ile_susp--;
				break;

			case 3:

				tab[i][j].podejrzani->three = NULL;
				tab[i][j].ile_susp--;
				break;

			case 4:

				tab[i][j].podejrzani->four = NULL;
				tab[i][j].ile_susp--;
				break;

			case 5:

				tab[i][j].podejrzani->five = NULL;
				tab[i][j].ile_susp--;
				break;
			case 6:

				tab[i][j].podejrzani->six = NULL;
				tab[i][j].ile_susp--;
				break;

			case 7:

				tab[i][j].podejrzani->seven = NULL;
				tab[i][j].ile_susp--;
				break;

			case 8:

				tab[i][j].podejrzani->eight = NULL;
				tab[i][j].ile_susp--;
				break;

			case 9:

				tab[i][j].podejrzani->nine = NULL;
				tab[i][j].ile_susp--;
				break;

			default:
				z++;
				break;
			}
		}
			
	}
	if (z == n-1)
		return 0;
	else
		return 1;
}

bool pion(kratka** tab, int &n, int &i, int &j)
{
	int z = 0;
	for (int p = 0; p < n; p++)
	{
		if (j != p && !tab[i][j].liczba)
		{
			switch (tab[i][p].liczba)
			{
			case 1:

				tab[i][j].podejrzani->one = NULL;
				tab[i][j].ile_susp--;
				break;

			case 2:

				tab[i][j].podejrzani->two = NULL;
				tab[i][j].ile_susp--;
				break;

			case 3:

				tab[i][j].podejrzani->three = NULL;
				tab[i][j].ile_susp--;
				break;

			case 4:

				tab[i][j].podejrzani->four = NULL;
				tab[i][j].ile_susp--;
				break;

			case 5:

				tab[i][j].podejrzani->five = NULL;
				tab[i][j].ile_susp--;
				break;
			case 6:

				tab[i][j].podejrzani->six = NULL;
				tab[i][j].ile_susp--;
				break;

			case 7:

				tab[i][j].podejrzani->seven = NULL;
				tab[i][j].ile_susp--;
				break;

			case 8:

				tab[i][j].podejrzani->eight = NULL;
				tab[i][j].ile_susp--;
				break;

			case 9:

				tab[i][j].podejrzani->nine = NULL;
				tab[i][j].ile_susp--;
				break;

			default:
				z++;
				break;
			}
		}
	}
	if (z == n-1)
		return 0;
	else
		return 1;
}

bool kwadrat(kratka** tab, int &n, int &i, int &j)
{
	int z = 0;
	int k = (i / 3)*3;
	int l = (j / 3)*3;
	
	for (int m = l; m < l + 3; m++)
	{
		for (int o = k; o < k + 3; o++)
		{
			if (i != o && j != m && !tab[i][j].liczba)
			{
				switch (tab[o][m].liczba)
				{
				case 1:

					tab[i][j].podejrzani->one = NULL;
					tab[i][j].ile_susp--;
					break;

				case 2:

					tab[i][j].podejrzani->two = NULL;
					tab[i][j].ile_susp--;
					break;

				case 3:

					tab[i][j].podejrzani->three = NULL;
					tab[i][j].ile_susp--;
					break;

				case 4:

					tab[i][j].podejrzani->four = NULL;
					tab[i][j].ile_susp--;
					break;

				case 5:

					tab[i][j].podejrzani->five = NULL;
					tab[i][j].ile_susp--;
					break;
				case 6:

					tab[i][j].podejrzani->six = NULL;
					tab[i][j].ile_susp--;
					break;

				case 7:

					tab[i][j].podejrzani->seven = NULL;
					tab[i][j].ile_susp--;
					break;

				case 8:

					tab[i][j].podejrzani->eight = NULL;
					tab[i][j].ile_susp--;
					break;

				case 9:

					tab[i][j].podejrzani->nine = NULL;
					tab[i][j].ile_susp--;
					break;

				default:
					z++;
					break;
				}
			}
		}
	}

	if (z == n - 1)
		return 0;
	else
		return 1;
}

int sprawdz(kratka** &tab, int &n)
{
	int zmiany = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j].liczba)
			{	
				if(poziom(tab, n, i, j));
					zmiany++;
				if(pion(tab, n, i, j));
					zmiany++;
				if(kwadrat(tab, n, i, j));
					zmiany++;
				if (zmiany != 0)
					refresh(tab,i,j);
			}
		}
	}
	return zmiany;
}

int main()
{
	//alokowanie
	int n = 9;
	kratka** tab = new kratka*[n];
	for (int i = 0; i<n; i++)
		tab[i] = new kratka[n];

	int zmiany = 0;
	do
	{

	zmiany = sprawdz(tab,n);

	} while (zmiany != 0);


	//usuwanie
	for (int i = 0; i<n; i++)
		delete[] tab[i];
	delete[] tab;

	return 111;
}