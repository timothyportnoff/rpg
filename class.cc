#include "monster.h"
using E=Entity;
using H=Hero;
using M=Monster;
using namespace std;

void E::set_health(int health) {
	this->health = health;
}
int E::get_health() {
	return health;
}
void E::set_level(int) {
	this->level - level;
}
int E::get_level() {
	return level;
}
virtual void E::print_stats() {
	cout << "My name is " << name << endl;
	cout << "I have " << health << " health" << endl;
	cout << "My attack is " << attack << endl;
}




M::M() {
	name = "Tim";
	isElite = false;
	monsterType = "Celestial";
}
M::Monster(string name, bool isElite, string monsterType) {
	this->name = name;
	this->elite = true;
	this->monster_type = "celestial";
}
int M::get_level() const { return level; }
string M::get_name const { return name; }

void M::set_name(name_to_set) { name = name_to_set; }
void M::set_level(level_to_set) { 
	if (level_to_set < 1 or newLevel > 99)
		throw invalid_argument( "Error! Inval;id Level Needs to be 1 and 100");
	level = level_to_set; 
}
void M::set_health(health_to_set) { 
	name = name_to_set; }


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



// Print*************************************************
void print_stats() {
	cout << "Health: " << health;
	cout << "Armor: " << armor;
	cout << "Level: " << level;
}




