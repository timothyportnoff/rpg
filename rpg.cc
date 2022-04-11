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
//bridges stuff
#include "Bridges.h"
//#include "CircDLelement.h"


using namespace std;
using namespace bridges;

void load_actors(vector<shared_ptr<Actor>>& cast, const string filename) {
	ifstream in(filename);
	if (!in) cerr << "Uh oh no file found" << endl;
	while (in) {
		string class_type;
		in >> class_type;
		if (!in) break;

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

		if (class_type == "hero") cast.push_back(make_shared<Hero> (class_type, name, type, x, y, emoji, health, shield, damage, resistance, level));
		else if (class_type == "monster") cast.push_back(make_shared<Hero> (class_type, name, type, x, y, emoji, health, shield, damage, resistance, level));
	}
}
/*
CircDLelement<Actor> *insertFront(
    CircDLelement<Actor> *tailElement,
    CircDLelement<Actor> *newElement);
*/

void load_game_map() {}

int main() {
	set_raw_mode(true);
	show_cursor(false);
	//set_alternate_window(true);
	srand(time(0));
	vector<shared_ptr<Actor>> cast;

	print_title("RPG - 41");
	cout << endl;
	cout << "New game (1);" << endl;
	cout << "Load game (2);" << endl;
	int choice;
	cin >> choice;
	if (choice == 2) load_actors(cast, "save_actors.txt");
	else load_actors(cast, "actors.txt");

	shared_ptr<Actor> cat = cast.at(0); 
	draw_game_map(cat);
/*
	Bridges *bridges =  new Bridges(10, "Skeletonman59", "1126298313308");//TODO: Tim, you gotta change this on your side
	bridges->setTitle("Attack Turn:");
*/
	sort(cast.begin(), cast.end(), [](const shared_ptr<Actor>& lhs, const shared_ptr<Actor>& rhs) { //feeling skeptical about using Actor&...
			return lhs->get_speed() > rhs->get_speed();
   	});
/*
	int actorCount = 0;
	for (int k =cast.begin(); cast.end(); k++) actorCount++;
	CircDLelement<shared_ptr<Actor>> actorOrder;
	for (const shared_ptr<Actor> &a : cast) {
		////not sorted by hero/monster, it's sorted by speed. However, it still needs to be classified as a hero/monster.
		if (a->get_type() == "hero") new CircDLelement<shared_ptr<Actor>> Hero(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
		if (a->get_type() == "monster") new CircDLelement<shared_ptr<Actor>> Monster(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	}

	CircDLelement<shared_ptr<Actor> *head =  nullptr;
    		for (int i = 0; i < actorCount; i++) {
        	if (i) head = insertFront(head, Actor[i]);
        	else head = Actor[i];
			}
*/
	while (true) {
		for (size_t row = 0; row < game_map.size(); row++) {
			char puzzle1 = '1';
			char puzzle2 = '2';
			char puzzle3 = '3';
			char puzzle4 = '4';
			char puzzle5 = '5';
			char puzzle6 = '6';
			auto found1 = game_map.at(row).find(puzzle1);
			auto found2 = game_map.at(row).find(puzzle2);
			auto found3 = game_map.at(row).find(puzzle3);
			auto found4 = game_map.at(row).find(puzzle4);
			auto found5 = game_map.at(row).find(puzzle5);
			auto found6 = game_map.at(row).find(puzzle6);
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
				draw_game_map(cat);

			}
		}
		if (dir == 115 || dir == DOWN_ARROW || dir == 'j') {
			if (checkTile(cat, DOWN)) {
				cat->p->y++;
				draw_game_map(cat);
			}
		}
		if (dir == 97 || dir == LEFT_ARROW || dir == 'h') {
			if (checkTile(cat, LEFT)) {
				cat->p->x--;
				draw_game_map(cat);
			}
		}
		if (dir == 100 || dir == RIGHT_ARROW || dir == 'l') {
			if (checkTile(cat, RIGHT)) {
				cat->p->x++;
				draw_game_map(cat);
			}
		}
		if (dir == 'f') {
			movecursor(10, 2 * game_map.at(0).size());
			cout << "You have paid respects.";
			movecursor(11, 2 * game_map.at(0).size());
			cout << "Thank you for paying respects.";
		}
		if (dir == 'p') {
			initiate_combat();
		}
		if (dir == ESC) {
			system("clear");
			ofstream file;
			file.open("save_actors.txt");
			//TODO: Do I need this? : static_pointer_cast<Hero>(h)->num_cheese++;
			for (int i = 0; i < cast.size(); i++) {
					file << cast.at(i)->get_class_type() << " ";
					file << cast.at(i)->get_name() << " "; 
					file << cast.at(i)->get_type() << " "; 
					file << cast.at(i)->p->get_x() << " "; 
					file << cast.at(i)->p->get_y() << " "; 
					file << cast.at(i)->get_emoji() << " "; 
					file << cast.at(i)->get_health() << " "; 
					file << cast.at(i)->get_shield() << " "; 
					file << cast.at(i)->get_damage() << " "; 
					file << cast.at(i)->get_resistance() << " ";
					file << cast.at(i)->get_level() << " ";
					file << endl;
				if (cast.at(i)->get_class_type() == "hero") {
				}
			}
			file.close();
			cout << "Exiting..." << endl;
			show_cursor(true);
			exit(1);
		}
	}
}

