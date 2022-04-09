#include <string>
#include "/public/colors.h"
#include "graphics.h"
//#include "tileset.cc"
#include <vector>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

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
void initiate_combat(int x = 0, int y = 0) {
	system("clear");
	int userHealth = 100, bossHealth = 200;
	string moveChoice;
	cout << "Hello! Welcome to the final boss!\n";
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
}
