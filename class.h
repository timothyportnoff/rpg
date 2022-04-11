#pragma once
#include <string>
//#include "point.cc"

using namespace std;//NOTE: THIS IS A REALLY BAD IDEA //FIXME

class Entity {
	private:
		string class_type;
		string type;
		string emoji;
		string name;
		int r;
		int g;
		int b;
	public:
		Point* p;
		string get_class_type() const;
		void set_class_type(string class_type);

		string get_type() const;
		void set_type(string type);

		string get_emoji() const;
		void set_emoji(string emoji);
		string get_name() const;
		void set_name(string name);

		void set_r(int r);
		int get_r() const;
		void set_g(int g);
		int get_g() const;
		void set_b(int b);
		int get_b() const;

		void print_stats() const;
};

class Tile : public Entity {
	Tile ();
	private:
	public:
	Tile (char character, string type, string emoji, int r, int g, int b); 
};

class Item : public Entity {
	private:
	public:
};

class Actor : public Entity {
	protected:
		int health = 100;
		int shield = 100;
		int damage = 10;
		int defense = 10;
		int resistance = 10;
		int level = 0;
		int speed = 0;
		bool is_elite = 0;
	public:
		Actor ();
		Actor (Point* p);
		Actor (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level);
		int get_health() const;
		void set_health(int);
		void add_health(int);
		
		int get_shield() const;
		void set_shield(int);
		void add_shield(int);
		
		int get_damage() const;
		void set_damage(int);
		
		int get_resistance() const;
		void set_resistance(int);
		
		int get_speed() const;
		void set_speed(int);
		
		int get_level() const;
		void set_level(int);
		
		void print_stats() const;
		void print_health_bar() const;
		void print_health() const;
		void print_shield () const;
};

class Monster : public Actor {
	private:
	public:
		Monster();
		Monster (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level);
		void print_stats() const; 
};

class Hero : public Actor {
	private:
		int num_coins;
	public:
		Hero();
		Hero (Point* p);
		Hero (string class_type, string name, string type, int x, int y, string emoji, int health, int shield, int damage, int resistence, int level);
		int num_keys = 0;
		int num_cheese = 0;
		int num_potions = 0;

		int get_keys() const;
		void set_keys();
		void add_keys(int n);

		int get_cheese() const;
		void set_cheese(int cheese);
		void add_cheese(int n);
		
		int get_potions() const;
		void set_potions(int potions);
		void add_potions(int n);

		int get_coins() const;
		void set_coins(int coins);
		void add_coins(int n);

		void print_keys () const;
		void print_cheese () const;
		void print_potions () const;
		void print_stats() const; 
};
