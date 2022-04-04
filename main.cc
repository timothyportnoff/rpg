//Sorry about the screen flickering. I couldn't figure out how to rewrite a single line on the map.
//Also, if you move a block into a corner, you're screwed.

#include <iostream>
#include <ostream>
#include <fstream>
#include <cmath>
#include <string>
#include "/public/colors.h"
#include "/public/read.h"
#include "tileset.cc"
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;


void win(int numCheese) {
	system("clear");
	system("figlet -f slant 'A winner is you!!!' | lolcat");
	cout << endl;
	cout << "You collected " << numCheese << " cheese wheels." << endl;
	exit(1);
}

void lose(int numCheese) {
	system("clear");
	system("figlet -f slant 'Sorry... you lost.' | lolcat");
	cout << endl;
	cout << "You collected " << numCheese << " cheese wheels." << endl;
	exit(1);
}
void titleSplash() {
	system("clear");
	system("figlet -f slant 'Welcome' | lolcat");
	sleep(1);
	system("figlet -f slant '\tTo' | lolcat");
	sleep(1);
	system("figlet -f slant '\t\tHell' | lolcat");
	sleep(1);
}

/*
string healthBar(int userHealth) {
	for (int i = 20; i < 200; i+20) {
		if userHealth < i+

*/



string healthBar(int userHealth) {
	if (userHealth < 20) return "🤍";
	else if (userHealth < 30) return "🤍🤍";
	else if (userHealth < 40) return "🤍🤍🤍";
	else if (userHealth < 50) return "🤍🤍🤍🤍";
	else if (userHealth < 60) return "🤍🤍🤍🤍🤍";
	else if (userHealth < 70) return "🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 80) return "🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 90) return "🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 100) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 110) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 120) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 130) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 140) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth < 150) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 150 && userHealth < 160) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 160 && userHealth < 170) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 170 && userHealth < 180) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 180 && userHealth < 190) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth >= 190 && userHealth < 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth == 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍";
	else if (userHealth > 200) return "🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍🤍+";
	return "ERROR";
}
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

void combatGame(int numCheese, int numPots) {
	system("clear");
	int userHealth = 100, bossHealth = 200;
	string moveChoice;
	cout << "Hello! Welcome to the final boss!\n";
	cout << "Choose your attacks wisely, you're facing a final boss who has double your health!\n";
	cout << "I advise you to use whatever potions you have earned, those will help you last with the final boss and defeat him!\n";
	while (userHealth > 0 or bossHealth > 0) {
		if (userHealth <= 0 or bossHealth <= 0) break;
		cout << "Your Health: " << userHealth << " " << healthBar(userHealth) << endl;
		cout << "Boss Health: " << bossHealth << " " << healthBar(bossHealth) << endl;
		if (numPots > 0) {
			cout << "Number of Potions: " << numPots << endl;
		}
		cout << "Number of Cheese: " << numCheese << endl;
		if (numPots > 0) {
			cout << "Choose your move: Sword Attack (1) (Damage 0-20), Potion (2) (+20 health)\n";
		} else {
			cout << "Choose your move: Sword Attack (1) (Damage 0-20)\n";
		}

		cin >> moveChoice;
		if (moveChoice == "1") {
			combatGameAttack(bossHealth);
		} else if (moveChoice == "2" && numPots > 0) {
			combatGamePotion(userHealth, numPots);
		} else {
			youMessedUp(moveChoice);
		}

		if (userHealth <= 0 or bossHealth <= 0) break;
		int bossAttackDamage = rand() % 30;
		userHealth = userHealth - bossAttackDamage;
		cout << "The boss did " << bossAttackDamage << " damage to your health." << endl;
	}
	if (userHealth <= 0) lose(numCheese);
	if (bossHealth <= 0) win(numCheese);
}



int main() {
	titleSplash();
	set_raw_mode(true);
	show_cursor(false);
	//set_alternate_window(true);
	srand(time(0));
	int x = 62;
	int y = 5;

	drawMap(x, y);

	while (true) {
		for (size_t row = 0; row < map.size(); row++) {

			char puzzle1 = '1';
			char puzzle2 = '2';
			char puzzle3 = '3';
			char puzzle4 = '4';
			char puzzle5 = '5';
			char puzzle6 = '6';
			auto found1 = map.at(row).find(puzzle1);
			auto found2 = map.at(row).find(puzzle2);
			auto found3 = map.at(row).find(puzzle3);
			auto found4 = map.at(row).find(puzzle4);
			auto found5 = map.at(row).find(puzzle5);
			auto found6 = map.at(row).find(puzzle6);

			if (found1 != string::npos) {
				solved1 = 1;
			}
			if (found2 != string::npos) {
				solved2 = 1;
			}
			if (found3 != string::npos) {
				solved3 = 1;
			}
			if (found4 != string::npos) {
				solved4 = 1;
			}
			if (found5 != string::npos) {
				solved5 = 1;
			}
			if (found6 != string::npos) {
				solved6 = 1;
			}

		}

		j = 2;
		movecursor(j, 2 * map.at(0).size());
		cout << "X: " << x << "     Y: " << y;
		j += 2;

		if (numKeys > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🔑 - Keys: " << numKeys << endl;
			j++;
		}
		if (numPots > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🧂 - Potions: " << numPots << endl;
			j++;
		}
		if (numCheese > 0) {
			movecursor(j, 2 * map.at(0).size());
			cout << "🧀 - Cheese Wheels: " << numCheese;
			j++;
		}

		j += 2;

		int dir = quick_read();

		if (dir == 119 || dir == UP_ARROW || dir == 'k') {
			if (checkTile(x, y, x, y - 1)) {
				y --;
				drawMap(x, y);
			}
		}
		if (dir == 97 || dir == LEFT_ARROW || dir == 'h') {
			if (checkTile(x, y, x - 1, y)) {
				x --;
				drawMap(x, y);
			}
		}
		if (dir == 115 || dir == DOWN_ARROW || dir == 'j') {
			if (checkTile(x, y, x, y + 1)) {
				y ++;
				drawMap(x, y);
			}
		}
		if (dir == 100 || dir == RIGHT_ARROW || dir == 'l') {
			if (checkTile(x, y, x + 1, y)) {
				x ++;
				drawMap(x, y);
			}
		}
		//if (dir == 112) { //FIXME Initiates WIP combat game
		//	combatGame(numCheese, numPots);
		//}
		if (dir == 'f') {
			movecursor(10, 2 * map.at(0).size());
			cout << "You have paid respects.";
			movecursor(11, 2 * map.at(0).size());
			cout << "Thank you for paying respects.";
		}
		if (dir == ESC) {
			system("clear");
			exit(1);
		}
	}
}

