// C++ headers
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <memory>
// Kerney headers
#include "/public/colors.h"
#include "/public/read.h"
// RPG headers
#include "tileset.cc"
#include "graphics.cc"
#include "combat.cc"
#include "class.h"
<<<<<<< HEAD
//others
#include "bridges.cc"
#include "CircDLelement.h"

using namespace std;
using namespace bridges;
int x = 62;
int y = 25;
=======
using namespace std; // TODO: Probably a bad idea
>>>>>>> f2479c788d679c7cac0ef6bf79bac7946a9f691d

void load_actors(vector<shared_ptr<Actor>> cast) {
	ifstream in("actors.txt");
	if (!in) cerr << "Uh oh" << endl;
	while (in) {
		string class_type;
		in >> class_type;

<<<<<<< HEAD


void load_actors() {
	ifstream in("actors.txt");	
}


void load_map() {}
//enum direct {UP, DOWN, LEFT, RIGHT};

CircDLelement<Actor> *insertFront(
    CircDLelement<Actor> *tailElement,
    CircDLelement<Actor> *newElement);
=======
		string name;
		in >> name;

		string type;
		in >> type;

		int x;
		in >> x;
		
		int y;
		in >> y;
		
		string emoji;
		in >> emoji;
		
		int health;
		in >> health;
		
		int shield;
		in >> shield;
		
		int damage;
		in >> damage;
		
		int resistance;
		in >> resistance;
		
		int level;
		in >> level;

		//cast.push_back(make_shared<Hero> (name, type, x, y, emoji, health, shield, damage, resistance, level));
	}
}

void load_map() {}
>>>>>>> f2479c788d679c7cac0ef6bf79bac7946a9f691d

int main() {
	//print_title("RPG - 41");
	set_raw_mode(true);
	show_cursor(false);
	//set_alternate_window(true);
	srand(time(0));

	vector<shared_ptr<Actor>> cast;
	load_actors(cast);

	Hero* cat = new Hero(new Point{63, 63});

	drawMap(cat);

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
		int dir = quick_read();
		if (dir == 119 || dir == UP_ARROW || dir == 'k') {
			if (checkTile(cat, UP)) {
				cat->p->y--;
				drawMap(cat);
			}
		}
		if (dir == 115 || dir == DOWN_ARROW || dir == 'j') {
			if (checkTile(cat, DOWN)) {
				cat->p->y++;
				drawMap(cat);
			}
		}
		if (dir == 97 || dir == LEFT_ARROW || dir == 'h') {
			if (checkTile(cat, LEFT)) {
				cat->p->x--;
				drawMap(cat);
			}
		}
		if (dir == 100 || dir == RIGHT_ARROW || dir == 'l') {
			if (checkTile(cat, RIGHT)) {
				cat->p->x++;
				drawMap(cat);
			}
		}
		if (dir == 'f') {
			movecursor(10, 2 * map.at(0).size());
			cout << "You have paid respects.";
			movecursor(11, 2 * map.at(0).size());
			cout << "Thank you for paying respects.";
		}
		if (dir == 'p') {
			initiate_combat();
		}
		if (dir == ESC) {
			system("clear");
			cout << "Exiting..." << endl;
			show_cursor(false);
			exit(1);
		}
	}
}

