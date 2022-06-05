#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool _temp_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost()
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
		} while (counter < REDAKA * STUPACA * 0.25);

			}

		}

	};
	

public:
	game_of_life();
	void copy_1st_gen();
	void copy_generacija();
	void sljedeca_generacija();
	int broj_susjeda(bool _generacija[][STUPACA], int r, int s);
	void iscrtaj();
};

#endif
