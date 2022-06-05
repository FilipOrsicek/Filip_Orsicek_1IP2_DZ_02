#include "game_of_life.h"

game_of_life::game_of_life()
{
	int counter = 0;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			do
			{
				_generacija[i][j] = rand() % 2;
				counter++;
			} while (counter <= REDAKA * STUPACA* 0.25);

		}
	}
}

void game_of_life::copy_1st_gen()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_temp_generacija[i][j] = _generacija[i][j];
		}
	}

}

void game_of_life::copy_generacija()
{


	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_temp_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}


}




int game_of_life::broj_susjeda(bool _generacija[][STUPACA], int r, int s)
{
	int susjed = 0;

	if (_generacija[r - 1][s - 1] == true)
	{
		susjed++;
	}
	if (_generacija[r - 1][s] == true)
	{
		susjed++;
	}
	if (_generacija[r - 1][s + 1] == true)
	{
		susjed++;
	}
	if (_generacija[r][s - 1] == true)
	{
		susjed++;
	}
	if (_generacija[r][s + 1] == true)
	{
		susjed++;
	}
	if (_generacija[r + 1][s - 1] == true)
	{
		susjed++;
	}
	if (_generacija[r + 1][s] == true)
	{
		susjed++;
	}
	if (_generacija[r + 1][s + 1] == true)
	{
		susjed++;
	}

	return susjed;
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (broj_susjeda(_temp_generacija, i, j) == 2 or broj_susjeda(_temp_generacija, i, j) == 3)
			{
				_sljedeca_generacija[i][j] = true;

			}
			if (broj_susjeda(_temp_generacija, i, j) < 2 or broj_susjeda(_temp_generacija, i, j) > 3)
			{
				_sljedeca_generacija[i][j] = false;


			}
			if (broj_susjeda(_temp_generacija, i, j) == 3 and _temp_generacija[i][j] == false)
			{
				_sljedeca_generacija[i][j] = true;


			}
		}
	}



}
void game_of_life::iscrtaj()
{	
	for (int i = 0; i < REDAKA; i++)
	{
		for (size_t j = 0; j < STUPACA; j++)
		{
			if (_temp_generacija[i][j] == true)
			{
				cout << "X";

			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}


}
