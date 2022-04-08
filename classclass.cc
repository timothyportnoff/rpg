#pragma once
#include <string>

using namespace std;

class Entity {
    private:
        string type;
        string emoji;
        string name;
    public:
        string get_type() const{
			return type;
		}
        void set_type(string type) {
			this->type = type;
		}
        string get_emoji() const{
			return emoji;
		}
        void set_emoji(string emoji) {
			this->emoji = emoji;
		}
        string get_name() const {
			return name;
		}
        void set_name(string name){
			this->name = name;
		}
        virtual void print_stats() const{
			cout << get_emoji() << endl;
			cout << "Type: " << get_type() << endl;
			cout << "Name: " << get_emoji() << endl;
		}
			
};

class Item : public Entity {
    private:
		int healthIncVal;
		int healthDecVal;
    public:
		int get_heal() const {
			return healthIncVal;
		}
		int get_poison() const {
			return healthDecVal;
		}
		int set_health(int heal) {
			heal = healthIncVal;
		}
		int set_poison(int poison) {
			poison = healthDecVal;
		}
};

class Actor : public Entity {
    private:
        int health = 100;
        int shield = 100;
        int damage = 10;
        int level = 0;
    public:
		Actor() {};
		Actor(string new_emoji, string new_type, string name, int health, int shield, int damage, int level) {
			set_emoji(new_emoji);
			set_type(new_type);
			this->name = get_name();
			this->health = get_health();
			this->shield = get_shield();
			this->level = get_level();
			this->level = get_level();
		}
        int get_health() const {
			return health;
		}
        void set_health(int health) {
			this->health = health;
		}
        int get_shield() const {
			return shield;
		}
        void set_shield(int shield) {
			this->shield = shield;
		}
        int get_damage() const {
			return damage;
		}
        void set_damage(int damage) {
			this->damage = damage;
		}
        int get_level() const {
			return level;
		}
        void set_level(int level) {
			this->level = level;
		}
        //bool set_elite (bool boolean) { if (boolean) is_elite = (1); else is_elite = (0); }
        //friend ostream& operator << (ostream &outs, const Actor &rhs);
};

class Monster : public Actor {
	private:
		int health = 100;
        int shield = 100;
        int damage = 10;
        int level = 0;
		bool isElite = 0;
    public:
		Monster() {};
		Monster(string emoji, string type, string name, int health, int shield, int damage, int level) {
			new_emoji = emoji;
            this->type = type;
            this->name = name;
            this->health = health;
            this->shield = shield;
            this->level = level;
            this->level = level;
		}
		virtual void print_stats() const{
			cout << get_emoji() << endl;
            cout << "Type: " << get_type() << endl;
            cout << "Name: " << get_emoji() << endl;
        }
};
class Hero : public Actor {
    private:
		int num_keys;
        int num_cheese;
        int num_pots;
    public:
		Hero() {}
		Hero(string new_emoji, string type, string name, int health, int shield, int damage, int level) {
			new_emoji = emoji;
            this->type = type;
            this->name = name;
            this->health = health;
            this->shield = shield;
            this->level = level;
            this->level = level;
        }
		get_keys(int keys) const {
			return num_keys;
		}
		get cheese(int cheese) const {
			return num_cheese;
		}
		get_pots(int pots) const {
			return num_pots;
		}

};


