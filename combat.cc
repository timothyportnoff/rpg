#include <string>
#include "/public/colors.h"
#include "graphics.h"
//#include "tileset.cc"
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

//vector<shared_ptr<Actor>> cast;

void combatGameAttack(int &bossHealth) {
	int attackDamage = rand() % 20 + 20;
	bossHealth = bossHealth - attackDamage;
	cout << "Wow! You did " << attackDamage << " damage to the boss!" << endl;
}
void combatGamePotion(int &userHealth, int &numPotions) {
	userHealth = userHealth + 20;
	numPotions--;
	cout << "Your health is now " << userHealth << "." << endl;
}
void youMessedUp(string moveChoice) {
	if (moveChoice != "1" and moveChoice != "2") {
		cout << "You lost your turn and did no damage!" << endl;
	} else {
		cout << "ERROR" << endl;
	}
}
extern vector<shared_ptr<Actor>> cast;
int initiate_combat(shared_ptr<Actor>& h, int direction) { //Returns false if you cannot pass, returns 1 if the block is pass-able. Checks value on other side of block
	system("clear");
	int userHealth = 100, bossHealth = 200;
	string moveChoice;
	cout << "Hello! Welcome to the final boss!\n";
	cout << "Searching for boss...\n";
	//file << cast.at(i)->get_class_type() << " ";
	//static_pointer_cast<Hero>(h)->print_keys(); 
	//shared_ptr<Monster> m = static_pointer_cast<Monster>(cast.at(3));
	shared_ptr<Monster> m = static_pointer_cast<Monster> (cast.at(0)); 
	//cout << cast.at(2)->get_name() << endl;
	cout << "Success!\n";
	while (userHealth > 0 or bossHealth > 0) {
		if (userHealth <= 0 or bossHealth <= 0) break;
		//cout << "Your Health: " << userHealth << " " << healthBar(userHealth) << endl;
		//cout << "Boss Health: " << bossHealth << " " << healthBar(bossHealth) << endl;
		cin >> moveChoice;
		if (moveChoice == "1") { combatGameAttack(bossHealth); } 
		else { youMessedUp(moveChoice); }
		if (userHealth <= 0 or bossHealth <= 0) break;
		int bossAttackDamage = rand() % 30;
		userHealth = userHealth - bossAttackDamage;
		cout << "The boss did " << bossAttackDamage << " damage to your health." << endl;
	}
	if (userHealth <= 0) print_ending(0);
	if (bossHealth <= 0) print_ending(1);
	return 0;
}
