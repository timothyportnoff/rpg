#pragma once
#include <string>

using namespace std;//NOTE: THIS IS A REALLY BAD IDEA //FIXME

class Entity {
	private:
		string name;
	public:
		string get_name();
		void set_name(string name);
};

class Actor : public Entity {
	private:
		int health = 100;
		int shield = 100;
		int defense = 10;
		int damage = 10;
		int resistance = 10;
		int level = 0;
	public:
		int get_health();
		void set_health(int);
		int get_shield();
		void set_shield(int);
		int get_level();
		void set_level(int);
		virtual void print_stats();
		friend ostream& operator << (ostream &outs, const Actor &rhs);
};

class Monster : public Actor {
	private:
		string monster_type;
		bool isElite;
		int armor = 10;
	public:
		void set_type(string type_to_set);
};


class Hero : public Actor {
	private:
		string hero_type;
		int armor = 10;
	public:
		void set_type(string type_to_set);
};
