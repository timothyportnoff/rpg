#pragma once
#include <string>
//#include "point.cc"

using namespace std;//NOTE: THIS IS A REALLY BAD IDEA //FIXME

class Entity {
	private:
		string type;
		string emoji;
		string name;
	public:
		Point* p;
		string get_type() const;
		void set_type(string type);
		string get_emoji() const;
		void set_emoji(string emoji);
		string get_name() const;
		void set_name(string name);
		void print_stats() const;
};

class Item : public Entity {
	private:
	public:
};

class Actor : public Entity {
	private:
		int health = 100;
		int shield = 100;
		int damage = 10;
		int defense = 10;
		int resistance = 10;
		int level = 0;
		int speed = 0;
		bool is_elite = 0;
	public:
		Actor(Point* p);
		Actor (string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level);
		int get_health() const;
		void set_health(int);
		int get_shield() const;
		void set_shield(int);
		int get_damage() const;
		void set_damage(int);
		int get_resistance() const;
		void set_resistance(int);
		int get_speed() const;
		void set_speed(int);
		int get_level() const;
		void set_level(int);
		//bool set_elite (bool boolean) { if (boolean) is_elite = (1); else is_elite = (0); }
		void print_stats() const;
		//friend ostream& operator << (ostream &outs, const Actor &rhs);
};

class Monster : public Actor {
	private:
	public:
		using Actor::Actor;
};

class Hero : public Actor {
	private:
	public:
		using Actor::Actor;
		int num_keys;
		int num_cheese;
		int num_potions;
		//void print_stats() const {
};
