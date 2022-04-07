#include "graphics.h"

void print_title(string title) {
	system("clear");
	system("figlet -f slant 'Welcome' | lolcat");
	sleep(1);
	system("figlet -f slant '\tTo' | lolcat");
	sleep(1);
	system("figlet -f slant '\t\tHell' | lolcat");
	sleep(1);
}
void print_ending(int ending) {
	system("clear");
	if (ending == -1) {
		std::cout << "ERROR. TERMINATING GAME" << std::endl;
	}
	else if (ending == 0) {
		system("figlet -f slant 'Dead' | lolcat");
	}
	else if (ending == 1) {
		system("figlet -f slant 'You win' | lolcat");
	}
	else {
		system("figlet -f slant 'NO ENDING HERE' | lolcat");
	}
	exit(1);
}
//Draws the inventory of a given player at a given point.
void draw_inventory(Hero* h, Point* p) {
	cout << "=========" << endl;
	//movecursor(j, 2 * map.at(0).size());
	//cout << "X: " << p->x << "\tY: " << p->y << endl; 
	//cout << "Health: " << h->get_health() << " / health" << endl; 
	//j += 2;
	/*
	   if (num_keys > 0) {
	//movecursor(j, 2 * map.at(0).size());
	//cout << "🔑 - Keys: " << numKeys << endl;
	j++;
	}
	if (num_pots > 0) {
	//movecursor(j, 2 * map.at(0).size());
	//cout << "🧂 - Potions: " << numPots << endl;
	j++;
	}
	if (num_cheese > 0) {
	//movecursor(j, 2 * map.at(0).size());
	//cout << "🧀 - Cheese: " << numCheese;
	j++;
	}
	*/
	//j += 2;
}
void cls() {
	cout << "\033[2J\033[1;1H";
}

