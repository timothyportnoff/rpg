//Sorry about the screen flickering. I couldn't figure out how to rewrite a single line on the map.
//Also, if you move a block into a corner, you're screwed.
#include <iostream>
#include <ostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "/public/colors.h"
#include "/public/read.h"
// My headers
#include "tileset.cc"
#include "graphics.cc"
#include "combat.cc"
// TODO: Probably a bad idea
using namespace std;

int main() {
	print_title("RPG - 41");
	set_raw_mode(true);
	show_cursor(false);
	//set_alternate_window(true);
	srand(time(0));
	int x = 62;
	int y = 5;

	drawMap(x, y);

	while (true) {
		for (size_t row = 0; row < map.size(); row++) {

			char puzzle1 = '1';
			char puzzle2 = '2';
			char puzzle3 = '3';
			char puzzle4 = '4';
			char puzzle5 = '5';
			char puzzle6 = '6';
			auto found1 = map.at(row).find(puzzle1);
			auto found2 = map.at(row).find(puzzle2);
			auto found3 = map.at(row).find(puzzle3);
			auto found4 = map.at(row).find(puzzle4);
			auto found5 = map.at(row).find(puzzle5);
			auto found6 = map.at(row).find(puzzle6);

			if (found1 != string::npos) {
				solved1 = 1;
			}
			if (found2 != string::npos) {
				solved2 = 1;
			}
			if (found3 != string::npos) {
				solved3 = 1;
			}
			if (found4 != string::npos) {
				solved4 = 1;
			}
			if (found5 != string::npos) {
				solved5 = 1;
			}
			if (found6 != string::npos) {
				solved6 = 1;
			}

		}

		j = 2;
		movecursor(j, 2 * map.at(0).size());
		cout << "X: " << x << "     Y: " << y;
		j += 2;

		if (numKeys > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🔑 - Keys: " << numKeys << endl;
			j++;
		}
		if (numPots > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🧂 - Potions: " << numPots << endl;
			j++;
		}
		if (numCheese > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🧀 - Cheese Wheels: " << numCheese;
			j++;
		}

		j += 2;

		int dir = quick_read();

		if (dir == 119 || dir == UP_ARROW || dir == 'k') {
			if (checkTile(x, y, x, y - 1)) {
				y --;
				drawMap(x, y);
			}
		}
		if (dir == 97 || dir == LEFT_ARROW || dir == 'h') {
			if (checkTile(x, y, x - 1, y)) {
				x --;
				drawMap(x, y);
			}
		}
		if (dir == 115 || dir == DOWN_ARROW || dir == 'j') {
			if (checkTile(x, y, x, y + 1)) {
				y ++;
				drawMap(x, y);
			}
		}
		if (dir == 100 || dir == RIGHT_ARROW || dir == 'l') {
			if (checkTile(x, y, x + 1, y)) {
				x ++;
				drawMap(x, y);
			}
		}
		//if (dir == 112) { //FIXME Initiates WIP combat game
		//	combatGame(numCheese, numPots);
		//}
		if (dir == 'f') {
			movecursor(10, 2 * map.at(0).size());
			cout << "You have paid respects.";
			movecursor(11, 2 * map.at(0).size());
			cout << "Thank you for paying respects.";
		}
		if (dir == ESC) {
			system("clear");
			exit(1);
		}
	}
}

