#include "class.h"
#include <iostream>
#include <string>
using E=Entity;
using H=Hero;
using M=Monster;
using A=Actor;
using namespace std;

//ENTITY
string E::get_type() const { return "type"; }
void E::set_type(string type) { this->type = type; }

string E::get_emoji() const { return "emoji"; }
void E::set_emoji(string emoji) { this->emoji = emoji; }

string E::get_name() const { return "name"; }
void E::set_name(string name) { this->name = name; }

void E::print_stats() const {
	cout << "My name is " << name << endl;
}

//ACTOR
A::Actor() {};
A::Actor (Point* p) { this->p = p; }
//A::Actor (string name, Point* p) { this->p = p; }
A::Actor (string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
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
int A::get_shield() const { return shield; }
void A::set_shield(int shield) { this->shield = shield; }
int A::get_damage() const {return damage; }
void A::set_damage(int damage) { this->damage = damage; }
int A::get_resistance() const { return resistance; }
void A::set_resistance(int resistance) { this->resistance = resistance; }
int A::get_level() const { return level; }
void A::set_level(int level) { this->level = level; }
int A::get_speed() const { return speed; }
void A::set_speed(int speed) { this->speed = speed; }

//MONSTER
M::Monster() {};
/*
M::Monster (string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
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
*/
//HERO
H::Hero(Point* p) {
	this->p = p;
};

H::Hero (string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level) {
	set_name(name);
	set_type(type);
	Point* temp = new Point{x, y};
	this->p = temp;
	delete temp;
	set_emoji(emoji);
	this->health = health;
	this->shield = shield;
	this->damage = damage;
	this->resistance = resistance;
	this->level = level;
};

/*
void H::print_stats() const {
	cout << get_emoji() << endl;
	cout << "Type: " << get_type() << endl;
	cout << "Name: " << get_emoji() << endl;
}
*/
/*

//Output Monster
friend ostream& operator << (ostream &output, const Monster &m) {
output << "Name: " << m.name << endl;
output << "Level: " << m.name << endl;
output << "Name: " << m.name << endl;
return output;
}

//Input Monster
friend istream& operator >> (istream &outs, const Monster mm) {
input >> m.name >> m.monsterType;
return input;
}

E::virtual void print_stats() {
cout << "Health: " << health;
cout << "Armor: " << armor;
cout << "Level: " << level;
}
*/
