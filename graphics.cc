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
void draw_inventory(shared_ptr<Actor> h, const int XDISPLAY) {
	setbgcolor(1, 11, 17);
	setcolor(51, 51, 51);
	for (int i = 0; i < XDISPLAY-1; i++) { cout << "🟫"; }
	cout << RESET;

	cout << endl << "X: " << h->p->x << "\tY: " << h->p->y << endl; 
	/*
	if (h->num_keys > 0) {
		cout << "🔑 - Keys: " << h->num_keys << endl;
	}
	if (h->num_potions > 0) {
		cout << "🧂 - Potions: " << h->num_potions << endl;
	}
	if (h->num_cheese > 0) {
		cout << "🧀 - Cheese: " << h->num_cheese << endl;
	}
	*/
	setbgcolor(1, 11, 17);
	setcolor(51, 51, 51);
	for (int i = 0; i < XDISPLAY-1; i++) { cout << "🟫"; }
	cout << RESET << endl;
}
void cls() {
	cout << "\033[2J\033[1;1H";
}

