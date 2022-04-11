#include <string>
#include "/public/colors.h"
#include "graphics.h"
//#include "tileset.cc"
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

void print_moves(shared_ptr<Hero>& h) {
	cout << "[1] - Attack" << endl;
	cout << "[2] - Flee" << endl;
	cout << "[3] - Use Potion" << endl;
	cout << "[4] - Use Cheese" << endl;
}
void make_move(shared_ptr<Hero>& h, shared_ptr<Monster>& m) {
	while (true) {
	cout << "Move: ";
		int move = 0;
		cin >> move;
		if (move == 1) {
			size_t attack = rand() % 3 + 1;
			m->set_health(m->get_health() - attack);
			cout << "You hit " << m->get_name() << ", dealing " << attack << " damage" << endl;
			return;
		}
		else if (move == 2) {
			cout << "You coward." << endl;
		}
		else if (move == 3) {
			if (h->get_potions() > 0) {
				h->add_potions(-1);
				h->add_health(3);
				cout << "You used a potion." << endl;
				return;
			}
			else cout << "No potions!" << endl;
		}
		else if (move == 4) {
			if (h->get_cheese() > 0) {
				h->add_cheese(-1);
				h->add_health(3);
				cout << "You used a cheese." << endl;
				return;
			}
			else cout << "No cheese!" << endl;
		}
	}
}
int initiate_combat(vector <shared_ptr <Actor>>& cast, int direction) { //Returns false if you cannot pass, returns 1 if the block is pass-able. Checks value on other side of block
	system("clear");
	shared_ptr<Hero> h = static_pointer_cast<Hero> (cast.at(0)); 
	shared_ptr<Monster> m = static_pointer_cast<Monster> (cast.at(0)); 
	int x = h->p->x;
	int y = h->p->y;
	if (direction == UP) { y--; }
	if (direction == DOWN) { y++; }
	if (direction == LEFT) { x--; }
	if (direction == RIGHT) { x++; }

	for (shared_ptr<Actor> a : cast) {
		if (a->get_class_type() == "monster") {
			if(a->p->x == x && a->p->y == y) {
				m = static_pointer_cast<Monster> (a); 
			}
		}
	}

	draw_bar();
	m->print_stats();		
	cout << m->get_emoji() << endl << endl;
	cout << h->get_emoji() << endl;		
	h->print_stats();		
	draw_bar();

	cout << "A terrifying " << m->get_type() << " named " << m->get_name() << " blocks your path!" << endl;
	sleep(1);
	while (h->get_health() > 0 and m->get_health() > 0) {
		if (h->get_health() <= 0 or m->get_health() <= 0) break;

		// Moves for PC
		print_moves(h);
		make_move(h, m);
		sleep(2);

		//Boss attack time
		size_t attack = rand() % 3;
		h->set_health(h->get_health() - attack);
		cout << m->get_name() << " hit you, dealing " << attack << " damage" << endl;
		sleep(2);
		if (h->get_health() <= 0 or m->get_health() <= 0) break;

		//Draw screen
		draw_bar();
		m->print_stats();		
		cout << m->get_emoji() << endl;
		cout << endl;
		cout << h->get_emoji() << endl;		
		h->print_stats();		
		draw_bar();

	}
	if (h->get_health() <= 0) {
		cout << "you lost" << endl; 
		sleep(2);
		print_ending(0);
	}
	else if (m->get_health() <= 0) {
		cout << m->get_name() << " defeated!" << endl;
		sleep(2);
		//print_ending(1);
	}
	return 1;
}
