#include "graphics.h"
static const size_t XDISPLAY = 21; //Show a 20x20 area at a time
static const size_t YDISPLAY = 17; //Show a 20x20 area at a time

void print_title(string title) {
	system("clear");
	system("figlet -f slant 'Welcome to hell' | lolcat");
	sleep(1);
}
void print_ending(int ending) {
	system("clear");
	if (ending == -1) {
		std::cout << "ERROR. TERMINATING GAME" << std::endl;
	}
	else if (ending == 0) {
		system("figlet -f slant 'Dead' | lolcat");
	}
	else if (ending == 1) {
		system("figlet -f slant 'You win' | lolcat");
	}
	else {
		system("figlet -f slant 'NO ENDING HERE' | lolcat");
	}
	exit(1);
}
//Draws the inventory of a given player at a given point.
void draw_cube() {
	setbgcolor(1, 11, 17);
	setcolor(51, 51, 51);
	cout << "  "; 
	cout << RESET << endl;
}
void draw_bar() {
	setbgcolor(1, 11, 17);
	setcolor(51, 51, 51);
	for (int i = 0; i <= XDISPLAY; i++) { cout << "🟫"; }
	cout << RESET << endl;
}
void draw_inventory(shared_ptr<Actor> h, const int XDISPLAY) {
	draw_bar();
	cout << "Position X: " << h->p->x << "\tY: " << h->p->y << endl; 
	if (static_pointer_cast<Hero>(h)->get_health() > 0)  {
		static_pointer_cast<Hero>(h)->print_health();
	}
	if (static_pointer_cast<Hero>(h)->get_health() > 0) {
		static_pointer_cast<Hero>(h)->print_shield();
	}
	if (static_pointer_cast<Hero>(h)->num_keys > 0) { 
		static_pointer_cast<Hero>(h)->print_keys(); 
	}
	if (static_pointer_cast<Hero>(h)->num_potions > 0) { 
		static_pointer_cast<Hero>(h)->print_potions(); 
	}
	if (static_pointer_cast<Hero>(h)->num_cheese > 0) { 
		static_pointer_cast<Hero>(h)->print_cheese(); 
	}
	draw_bar();
}

void draw_game_map(shared_ptr<Actor>& h) {
	system("clear"); 
	//cls();
	draw_bar();

	int start_x = h->p->x - XDISPLAY/2;
	int end_x = h->p->x + XDISPLAY/2;
	int start_y = h->p->y - YDISPLAY/2;
	int end_y = h->p->y + YDISPLAY/2;


	//Bounds check to handle the edges
	if (start_x < 0) {
		start_x = 0;
		end_x = start_x + XDISPLAY;
	}
	if (end_x > game_map.at(0).size()) {
		start_x = start_x - (end_x - (game_map.size()));
		end_x = game_map.size();
	}
	if (start_y < 0) {
		end_y = end_y - start_y;
		start_y = 0;
	}
	if (end_y > game_map.size()) {
		start_y = start_y - (end_y - (game_map.at(0).size()));
		end_y = game_map.at(0).size();
	}

	for (size_t row = start_y; row <= end_y; row++) {
		for (size_t col = start_x; col < end_x; col++) {
			setbgcolor(1, 11, 17);
			//If it's the border
			if (col == start_x) { 
				setcolor(51, 51, 51); //Our Default backround color value
				setbgcolor(1, 11, 17);
				cout << "🟫" << RESET;
			}

			//Places player over value at game_map
			if (row == h->p->y && col == h->p->x) {
				setcolor(205,133,63);
				cout << "🧔" << RESET;
			}

			//UNINTERACTABLES
			else if (game_map.at(row).at(col) == '#') {
				//setbgcolor(1, 11, 17);
				setbgcolor(16, 128, 114);
				setcolor(51, 51, 51);
				//setcolor(72, 191, 146);
				cout << "🟥" << RESET;
			} else if (game_map.at(row).at(col) == 'a') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "🏮";
			} else if (game_map.at(row).at(col) == '.') {
				setbgcolor(1, 11, 17);
				setcolor(238, 130, 238); //Violet fg
				cout << "  ";
			} else if (game_map.at(row).at(col) == ' ') {
				setcolor(20, 23, 24);
				cout <<  "🟥" << RESET;
				//cout << "  ";
			}

			//Interactables
			else if (game_map.at(row).at(col) == 'p') {
				setcolor(238, 130, 238); //Violet fg
				cout << "🙋";
			} else if (game_map.at(row).at(col) == 'w') {
				setcolor(218, 165, 32); //Gold fg
				cout << "🏆";
			} else if (game_map.at(row).at(col) == 'K') {
				setcolor(218, 165, 32); //Gold fg
				cout << "🔑";
			} else if (game_map.at(row).at(col) == 'P') {
				setcolor(139, 0, 139); //Dark magenta fg
				cout << "🧂";
			} else if (game_map.at(row).at(col) == 'C') {
				setcolor(255, 140, 0); //Dark orange fg
				cout << "🧀";
			} else if (game_map.at(row).at(col) == 'f') {
				setcolor(180, 53, 1); 
				cout << "🔥"; // FIRE
			} else if (game_map.at(row).at(col) == 'L') {
				setcolor(218, 165, 32); //Gold fg
				cout << "🔒";
			} else if (game_map.at(row).at(col) == 'E') { // ENEMY
				setcolor(180, 53, 1); 
				cout << "👹";
			}

			//Puzzles (pressure plates, boxes, switches and gates)

			//Switch
			else if (game_map.at(row).at(col) == 's') {
				setcolor(255, 0, 255); //Magenta
				cout << "📍";
			} else if (game_map.at(row).at(col) == 'S') {
				setcolor(30, 144, 255); //Dodger blue
				cout << "📍";
			}

			//Gate
			else if (game_map.at(row).at(col) == 'G') { //Open gate
				setcolor(105, 105, 105);
				cout << "❌";
			} else if (game_map.at(row).at(col) == 'g') { //Open Gate
				setcolor(105, 105, 105);
				cout << "  ";
			}

			//Box puzzles
			else if (game_map.at(row).at(col) == 'b') {
				setcolor(160, 82, 45);
				//setcolor(255, 140, 0); //Dark orange fg
				cout << "📦";
			}

			//UP Pressure plates 1-5
			else if (game_map.at(row).at(col) == '1') {
				solved1 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			} else if (game_map.at(row).at(col) == '2') {
				solved2 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			} else if (game_map.at(row).at(col) == '3') {
				solved3 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			} else if (game_map.at(row).at(col) == '4') {
				solved4 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			} else if (game_map.at(row).at(col) == '5') {
				solved5 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			} else if (game_map.at(row).at(col) == 'q') {
				//solved5 = 0;
				setcolor(0, 128, 0); //Green fg
				cout << "💢";
			}

			//DOWN Pressure plates 1-5 (6-0)
			else if (game_map.at(row).at(col) == '6') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (game_map.at(row).at(col) == '7') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (game_map.at(row).at(col) == '8') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (game_map.at(row).at(col) == '9') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (game_map.at(row).at(col) == '0') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (game_map.at(row).at(col) == 'Q') {
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			}

			//Puzzle Gates FIXME: Should these be else?
			else if (game_map.at(row).at(col) == '!') {
				if (solved1 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥";
				}
				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒";
				}
			}

			else if (game_map.at(row).at(col) == '?') {
				if (solved2 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			else if (game_map.at(row).at(col) == '^') {
				if (solved3 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			else if (game_map.at(row).at(col) == '&') {
				if (solved4 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			} if (game_map.at(row).at(col) == '%') {
				if (solved5 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			} else if (game_map.at(row).at(col) == '$') {
				setcolor(107, 142, 35); //Olive drab
				cout << "🔒" << RESET;
			} 

			else if (game_map.at(row).at(col) == '*') {
				if (solved6 == 1) {
					game_map.at(row).at(col) = ' ';
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			// Books
			else if (game_map.at(row).at(col) == 'Z' || game_map.at(row).at(col) == 'z' || game_map.at(row).at(col) == 'Y' || game_map.at(row).at(col) == 'y'
					|| game_map.at(row).at(col) == 'X' || game_map.at(row).at(col) == 'x' || game_map.at(row).at(col) == 'A' || game_map.at(row).at(col) == 'k'
					|| game_map.at(row).at(col) == 'V' || game_map.at(row).at(col) == '~' || game_map.at(row).at(col) == 'e' || game_map.at(row).at(col) == 'k'
					|| game_map.at(row).at(col) == 'J' || game_map.at(row).at(col) == 'h' || game_map.at(row).at(col) == 'H'
					|| game_map.at(row).at(col) == 'o' || game_map.at(row).at(col) == 'O' || game_map.at(row).at(col) == 'r' || game_map.at(row).at(col) == 'R'
					|| game_map.at(row).at(col) == 't' || game_map.at(row).at(col) == 'T' || game_map.at(row).at(col) == 'i' || game_map.at(row).at(col) == 'I'
					|| game_map.at(row).at(col) == 'l' || game_map.at(row).at(col) == 'j' || game_map.at(row).at(col) == 'F' 
					|| game_map.at(row).at(col) == 'y') {
				setcolor(0, 128, 0); //Green fg
				cout << "📖" << RESET;
			}
			if (col == end_x - 1) { 
				setcolor(51, 51, 51);
				cout << "🟫"; 
			}
		}
		cout << endl;

	}
	draw_inventory(h, XDISPLAY);
}
void cls() {
	cout << "\033[2J\033[1;1H";
}

