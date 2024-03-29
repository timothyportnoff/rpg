#include "class.h"
#include <iostream>
#include <string>
using E=Entity;
using H=Hero;
using M=Monster;
using A=Actor;
using T=Tile;
using namespace std;

// Entity class definitions
string E::get_class_type() const { return class_type; }
void E::set_class_type(string class_type) { this->class_type = class_type; }

string E::get_type() const { return type; }
void E::set_type(string type) { this->type = type; }

string E::get_emoji() const { return emoji; }
void E::set_emoji(string emoji) { this->emoji = emoji; }

string E::get_name() const { return name; }
void E::set_name(string name) { this->name = name; }

void E::set_r(int r) { this->r = r; };
int E::get_r() const { return r; };

void E::set_g(int g) { this->g = g; };
int E::get_g() const { return g; };

void E::set_b(int b) { this->b = b; };
int E::get_b() const { return b; };

// Tile class definitions
T::Tile () {};
T::Tile (char character, string type, string emoji, int r, int g, int b) {
	}

// Actor class definitions
A::Actor() {};
A::Actor (Point* p) { this->p = p; }
A::Actor (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
	set_class_type(class_type);
	set_name(name);
	set_type(type);
	this->p->x = x;
	this->p->y = y;
	set_emoji(emoji);
	this->health = health;
	this->shield = shield;
	this->damage = damage;
	this->resistance = resistance;
	this->level = level;
}
int A::get_health() const { return health; }
void A::set_health(int health) { this->health = health; }
void A::add_health(int n) { health += n; }

int A::get_shield() const { return shield; }
void A::set_shield(int shield) { this->shield = shield; }
void A::add_shield(int n) { shield += n; }

int A::get_damage() const {return damage; }
void A::set_damage(int damage) { this->damage = damage; }

int A::get_resistance() const { return resistance; }
void A::set_resistance(int resistance) { this->resistance = resistance; }

int A::get_level() const { return level; }
void A::set_level(int level) { this->level = level; }

int A::get_speed() const { return speed; }
void A::set_speed(int speed) { this->speed = speed; }

void A::print_health_bar() const {
	string health_bar;
	for (int j = 0; j <= health; j++) health_bar += "🖤";
	cout << health_bar << endl;;
}
void A::print_health() const {
	if (get_health() > 0) {
		cout << "H: ";
		setcolor(180, 53, 1); // RED :)
		for (int i = 0; i < get_health(); i++) {
			cout << "💗"; 
		}
		cout << RESET << endl;
	}
};
void A::print_shield() const {
	if (get_shield() > 0) {
		cout << "S: ";
		setcolor(51, 51, 51);
		for (int i = 0; i < get_shield(); i++) {
			cout << "➕"; 
		}
		cout << RESET << endl;
	}
};
// Monster class definitions
M::Monster() {};
M::Monster (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
	set_class_type(class_type);
	set_name(name);
	set_type(type);
	Point* temp = new Point{x, y};
	this->p = temp;
	//delete temp;
	set_emoji(emoji);
	this->health = health;
	this->shield = shield;
	this->damage = damage;
	this->resistance = resistance;
	this->level = level;
};
void M::print_stats() const {
	if (get_health() > 0)  {
		print_health();
	}
	if (get_shield() > 0) {
		print_shield();
	}
}
// Hero class definitions
H::Hero (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
	set_class_type(class_type);
	set_name(name);
	set_type(type);
	Point* temp = new Point{x, y};
	this->p = temp;
	//delete temp;
	set_emoji(emoji);
	this->health = health;
	this->shield = shield;
	this->damage = damage;
	this->resistance = resistance;
	this->level = level;
};
int H::get_cheese() const { return num_cheese; }
void H::add_cheese(int n) { num_cheese += n; }

int H::get_keys() const { return num_keys; }
void H::add_keys(int n) { num_keys += n; }

int H::get_potions() const { return num_potions; }
void H::add_potions(int n) { num_potions += n; }

int H::get_coins() const { return num_cheese; }
void H::add_coins(int n) { num_coins += n; }

void H::print_keys() const {
	if (num_keys > 0) {
		cout << "K: ";
		setcolor(218, 165, 32); //Gold fg
		for (int i = 0; i < num_keys; i++) {
			cout << "🔑"; 
		}
		cout << RESET << endl;
	}
};
void H::print_cheese () const {
	if (num_cheese > 0) {
		cout << "C: ";
		setcolor(255, 140, 0); //Dark orange fg
		for (int i = 0; i < num_cheese; i++) {
			cout << "🧀";
		}
		cout << RESET << endl;
	}
};
void H::print_potions () const {
	if (num_potions > 0) {
		cout << "P: ";
		setcolor(139, 0, 139); //Dark magenta fg
		for (int i = 0; i < num_potions; i++) {
			cout << "🧂"; 
		}
		cout <<  RESET << endl;
	}
};
void H::print_stats() const {
	if (get_health() > 0)  {
		print_health();
	}
	if (get_shield() > 0) {
		print_shield();
	}
	if (num_keys > 0) { 
		print_keys(); 
	}
	if (num_potions > 0) { 
		print_potions(); 
	}
	if (num_cheese > 0) { 
		print_cheese(); 
	}
}
