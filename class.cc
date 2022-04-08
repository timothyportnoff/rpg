#include "class.h"
#include <iostream>
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
	//cout << "My name is " << name << endl;
}

//ACTOR
A::Actor (Point* p) { this->p = p; }
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

//HERO
//MONSTER
/*M::M() {
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
  throw invalid_argument( "Error! Invalid Level Needs to be 1 and 99");
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

E::virtual void print_stats() {
cout << "Health: " << health;
cout << "Armor: " << armor;
cout << "Level: " << level;
}
*/
