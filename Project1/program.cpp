#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;






int main() {
	game_of_life the_game;
	
	the_game.copy_1st_gen();
	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		the_game.copy_generacija();
		cout << "Dalje (1/0): ";
		cin >> dalje;
		cout << endl;
	} while (dalje);

	return 0;
}