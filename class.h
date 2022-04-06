#pragma once
#include <string>

using namespace std;//NOTE: THIS IS A REALLY BAD IDEA //FIXME

class Entity {
	private:
		string name;
	public:
		void set_name(string name);
		string get_name();
};

class Actor : public Entity {
	private:
		int health = 100;
		int defense = 10;
		int damage = 10;
		int resistance = 10;
		int level = 0;
	public:
		void set_health(int);
		int get_health();
		void set_level(int);
		int get_level();
		virtual void print_stats();
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
