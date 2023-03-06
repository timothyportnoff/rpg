#pragma once
#include <string>
#include <map>
// Rpg Headers
#include "point.cc"
using namespace std;

bool solved1;
bool solved2;
bool solved3;
bool solved4;
bool solved5;
bool solved6;
int numKeys = 0;
int numPots = 0;
int numCheese = 0;
unsigned int i = 0;
unsigned int j = 0;

vector<string> map = {
	"......................................................................",
	"......................................................................",
	".....#######........#########...............##########......#####.....",
	".....#     #...####.#    aab#.............###  G     #....##     ##...",
	".....#   b #####ba###      b#.............#    G    ##....#   A   #...",
	".....# 1     C    ## b   V  #....########.#    G  ###....#  c   c  #..",
	"...### 1 b #####     b#     #....#c    c#.#########......#         #..",
	"...#       #...#  ## b b    #....#    y #...........###### z     Z #..",
	"...# #######...#  ##a  b    ######      #############              #..",
	"...#1#.........#  ## b#      L  L  Y             k    ####  c   c  #..",
	"...# #.#######.#~ ## b      ######      ###############...#   i   #...",
	"...#!#.#    C#.#   P#     bb#....########.................##  K  ##...",
	"...# ###L#C P#.#### b  a bs #......................######.###   ##....",
	"...#  l  #####....###########........########......#KC  #####a a###...",
	"...##### #........................####o     ##.....#  xbb         #...",
	".......#P###...........##########.#   b bb   #.....## a ######### #...",
	".......# a #.....####..#   4  4 #.# ###5  ab #......# ###.......# #...",
	".....###b2 #.....# 3#..# 4  4 b #.# #######5 #......# #...#####.# #...",
	".....# b   #.....# 3#..# b # a###.# #######5 #.....## ##### b #.# #...",
	".....# 2 b2#.....#a #..# b    #...# ### # a5 #.....#   b   ba #.# #...",
	".....#     #....##  #.##H###b #.### #O   5b  #.....####### b  #.# #...",
	".....### ###....# b #.#  #.#  #.#   # ########...........###a #.#X#...",
	".......#2#......#   #.# ##.## ### ###5#....................#  ### #...",
	".......# #.######abb#.# #...#4   &#.# ########.............# b   e#...",
	".......#?#.#  j    3#.#h#...#######.#     %  ##............##bav ##...",
	".....### ### ##### ##.# #...........########  #.............#   a#....",
	".....#  ba   #...# #..# #..................## ##............######....",
	"..#### a a ab#...# #### #..#######..........#  #......................",
	"..#         b#...#3    ^#..#     ####...#####ar############...........",
	"..# ##########...########..#  p     #...#  L       R  C  t#...........",
	"..#J###....................#        #...# ############### #...........",
	"..#   #....................##########...# #.............# #...........",
	"..### ####..............................# #...........c.# #.c.........",
	"...##    #...###########.......########## #.............# #...........",
	"...#q b  #...#         #.......#          #...........c.# #.c.........",
	"...### bq#...# ####### #.......# ##########..#######....# #...........",
	"...#q##b #...# #.....# ######### #...........#aCCaa#..c.#T#.c.........",
	"...# # q ###.# #...###      g    #.......##### b  a#....# #...........",
	"...#b Qbbq #.# #..##b       g K  #.......#CaCC   CC#..c.#C#.c.........",
	"...#   q   #.# #..#a   P   #########.....#C     ####....# #...........",
	"...## ######.# #..#              aa#.....#CCC   #.....c.#C#.c.........",
	"....# #......# #..#               a#.....#C   CC#.......# #...........",
	"....# ######## #..#b               #.....#   CCb####...## ##..........",
	"....#  q    *  #..#   b#GGGG####ggg#.....# C  Cbba##...# E #..........",
	"....############..#  bb#    #..#   #.....#CC   CCC#....#   #..........",
	"..................######  p #..#s C#.....#bCaa CCC#....#cwc#..........",
	".......................######..#####.....##########....#####..........",
	"......................................................................",
};

map<int> entity_map() {}

void drawMap(Point* p) {
	system("clear");//Can use clearscreen();
	for (int row = 0; row < map.size(); row++) {
		for (int col = 0; col < map.at(row).size(); col++) {

			//Places player over value at map
			if (row == p->y && col == p->x) {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 0, 205); //Blue fg
				cout << "👤" << RESET;
			}

			//UNINTERACTABLES
			else if (map.at(row).at(col) == '#') {
				setbgcolor(47, 79, 79);
				cout << BLACK << "🟥" << RESET;
			} else if (map.at(row).at(col) == 'a') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "🏮" << RESET;
			} else if (map.at(row).at(col) == '.') {
				cout << "  ";
			} else if (map.at(row).at(col) == ' ') {
				setbgcolor(192, 192, 192); //Light grey bg
				cout << WHITE << "🟥" << RESET;
			}

			//Interactables
			else if (map.at(row).at(col) == 'p') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(238, 130, 238); //Violet fg
				cout << "🙋" << RESET;
			} else if (map.at(row).at(col) == 'w') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(218, 165, 32); //Gold fg
				cout << "🏆" << RESET;
			} else if (map.at(row).at(col) == 'K') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(218, 165, 32); //Gold fg
				cout << "🔑" << RESET;
			} else if (map.at(row).at(col) == 'P') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 0, 139); //Dark magenta fg
				cout << "🧂" << RESET;
			} else if (map.at(row).at(col) == 'C') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(255, 140, 0); //Dark orange fg
				cout << "🧀" << RESET;
			} else if (map.at(row).at(col) == 'c') {
				setbgcolor(192, 192, 192); //Light grey bg
				cout << RED << "🔥" << RESET;
			} else if (map.at(row).at(col) == 'L') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(218, 165, 32); //Gold fg
				cout << "🔒" << RESET;
			} else if (map.at(row).at(col) == 'E') {
				setbgcolor(192, 192, 192); //Light grey bg
				cout << RED << "👹" << RESET;
			}

			//Puzzles (pressure plates, boxes, switches and gates)

			//Switch
			else if (map.at(row).at(col) == 's') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(255, 0, 255); //Magenta fg
				cout << "📍" << RESET;
			} else if (map.at(row).at(col) == 'S') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(30, 144, 255); //Dodger blue fg
				cout << "📍" << RESET;
			}

			//Gate
			else if (map.at(row).at(col) == 'G') { //Open gate
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(105, 105, 105); //GATE fg
				cout << "II" << RESET;
			} else if (map.at(row).at(col) == 'g') { //Open Gate
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(105, 105, 105);  //gate fg
				cout << "__" << RESET;
			}

			//Box puzzles
			else if (map.at(row).at(col) == 'b') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			}

			//UP Pressure plates 1-5
			else if (map.at(row).at(col) == '1') {
				solved1 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			} else if (map.at(row).at(col) == '2') {
				solved2 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			} else if (map.at(row).at(col) == '3') {
				solved3 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			} else if (map.at(row).at(col) == '4') {
				solved4 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			} else if (map.at(row).at(col) == '5') {
				solved5 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			} else if (map.at(row).at(col) == 'q') {
				//solved5 = 0;
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "💢" << RESET;
			}

			//DOWN Pressure plates 1-5 (6-0)
			else if (map.at(row).at(col) == '6') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (map.at(row).at(col) == '7') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (map.at(row).at(col) == '8') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (map.at(row).at(col) == '9') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (map.at(row).at(col) == '0') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			} else if (map.at(row).at(col) == 'Q') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(139, 69, 19); //Saddle brown fg
				cout << "📦" << RESET;
			}

			//Puzzle Gates
			else if (map.at(row).at(col) == '!') {
				if (solved1 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}
				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			if (map.at(row).at(col) == '?') {
				if (solved2 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			if (map.at(row).at(col) == '^') {
				if (solved3 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}

			if (map.at(row).at(col) == '&') {
				if (solved4 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			} if (map.at(row).at(col) == '%') {
				if (solved5 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			} if (map.at(row).at(col) == '$') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(107, 142, 35); //Olive drab
				cout << "🔒" << RESET;
			} 

			if (map.at(row).at(col) == '*') {
				if (solved6 == 1) {
					map.at(row).at(col) = ' ';
					setbgcolor(192, 192, 192); //Light grey bg
					cout << WHITE << "🟥" << RESET;
				}

				else {
					setbgcolor(192, 192, 192); //Light grey bg
					setcolor(107, 142, 35); //Olive drab
					cout << "🔒" << RESET;
				}
			}
	
			// Books
			else if (map.at(row).at(col) == 'Z' || map.at(row).at(col) == 'z' || map.at(row).at(col) == 'Y' || map.at(row).at(col) == 'y'
			         || map.at(row).at(col) == 'X' || map.at(row).at(col) == 'x' || map.at(row).at(col) == 'A' || map.at(row).at(col) == 'k'
			         || map.at(row).at(col) == 'V' || map.at(row).at(col) == '~' || map.at(row).at(col) == 'e' || map.at(row).at(col) == 'k'
			         || map.at(row).at(col) == 'f' || map.at(row).at(col) == 'J' || map.at(row).at(col) == 'h' || map.at(row).at(col) == 'H'
			         || map.at(row).at(col) == 'o' || map.at(row).at(col) == 'O' || map.at(row).at(col) == 'r' || map.at(row).at(col) == 'R'
			         || map.at(row).at(col) == 't' || map.at(row).at(col) == 'T' || map.at(row).at(col) == 'i' || map.at(row).at(col) == 'I'
			         || map.at(row).at(col) == 'l' || map.at(row).at(col) == 'j' || map.at(row).at(col) == 'f' || map.at(row).at(col) == 'F') {
				setbgcolor(192, 192, 192); //Light grey bg
				setcolor(0, 128, 0); //Green fg
				cout << "📖" << RESET;
			}
		}
		cout << endl;
	}
}
bool checkTile(Point* current_position, int nextx, int nexty) { // 
	//Returns 0 if the block is solid
	//Returns 1 if you can walk over the block
	//Checks value on other side of block

	int diffx = current_position->x - nextx;
	int diffy = current_position->y - nexty;
	int x = current_position->x;
	int y = current_position->y;

	if (map.at(nexty).at(nextx) == '#' || map.at(nexty).at(nextx) == 'a' || map.at(nexty).at(nextx) == 'G') return 0;
	else if (map.at(nexty).at(nextx) == '!' || map.at(nexty).at(nextx) == '?' || map.at(nexty).at(nextx) == '^' || map.at(nexty).at(nextx) == '&' || map.at(nexty).at(nextx) == '%') return 0;

	//Check for box
	else if (map.at(nexty).at(nextx) == 'b') {
		//Check for empty space
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			//map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}

		//Check for Pressure plate
		if (map.at(nexty - diffy).at(nextx - diffx) == '1') {
			map.at(nexty - diffy).at(nextx - diffx) = '6';
			map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '2') {
			map.at(nexty - diffy).at(nextx - diffx) = '7';
			map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '3') {
			map.at(nexty - diffy).at(nextx - diffx) = '8';
			map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '4') {
			map.at(nexty - diffy).at(nextx - diffx) = '9';
			map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '5') {
			map.at(nexty - diffy).at(nextx - diffx) = '0';
			map.at(y).at(x) = ' ';
			map.at(nexty).at(nextx) = ' ';
			return 1;
		}
		else return 0;
	}

	//Check for DOWN Pressure plate
	else if (map.at(nexty).at(nextx) == '6') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ' || map.at(nexty - diffy).at(nextx - diffx) == '6') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '1';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '1') {
			map.at(nexty - diffy).at(nextx - diffx) = '6';
			map.at(nexty).at(nextx) = '1';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}

	else if (map.at(nexty).at(nextx) == '7') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '2';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '2') {
			map.at(nexty - diffy).at(nextx - diffx) = '7';
			map.at(nexty).at(nextx) = '2';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}

	else if (map.at(nexty).at(nextx) == '8') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '2';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '3') {
			map.at(nexty - diffy).at(nextx - diffx) = '8';
			map.at(nexty).at(nextx) = '3';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}

	else if (map.at(nexty).at(nextx) == '9') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '4';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '4') {
			map.at(nexty - diffy).at(nextx - diffx) = '9';
			map.at(nexty).at(nextx) = '4';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}

	else if (map.at(nexty).at(nextx) == '0') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '5';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '5') {
			map.at(nexty - diffy).at(nextx - diffx) = '0';
			map.at(nexty).at(nextx) = '5';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}

	else if (map.at(nexty).at(nextx) == '0') {
		if (map.at(nexty - diffy).at(nextx - diffx) == ' ') {
			map.at(nexty - diffy).at(nextx - diffx) = 'b';
			map.at(nexty).at(nextx) = '5';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == '5') {
			map.at(nexty - diffy).at(nextx - diffx) = '0';
			map.at(nexty).at(nextx) = '5';
			return 1;
		}
		if (map.at(nexty - diffy).at(nextx - diffx) == 'b') {
			return 0;
		}
	}
	else if (map.at(nexty).at(nextx) == 'S') {
		map.at(nexty).at(nextx) = 's';
		drawMap(current_position);
		return 0;
	}
	else if (map.at(nexty).at(nextx) == 's') {
		map.at(nexty).at(nextx) = 'S';
		drawMap(current_position);
		return 0;
	}
	else if (map.at(nexty).at(nextx) == 'C') {
		map.at(nexty).at(nextx) = ' ';
		numCheese++;
		return 1;
	}
	else if (map.at(nexty).at(nextx) == 'P') {
		map.at(nexty).at(nextx) = ' ';
		numPots++;
		return 1;
	}
	else if (map.at(nexty).at(nextx) == 'K') {
		map.at(nexty).at(nextx) = ' ';
		numKeys++;
		return 1;
	}
	else if (map.at(nexty).at(nextx) == 'L') {
		if (numKeys > 0) {
			map.at(nexty).at(nextx) = ' ';
			numKeys--;
			return 1;
		} else return 0;
	}
	else if (map.at(nexty).at(nextx) == 'E') {
		//combatGame(numCheese, numPots);
		return 0;
	}

	//DIALOGUE
	else if (map.at(nexty).at(nextx) == 'Z') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "You wake up with a cough and a sore throat." << endl << "You notice your body aches and a new loss of taste or smell";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'z') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "You've never seen this place before. This room is cold and wet.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'Y') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "In front of you is a large, petrified oak door. It has a rusted keyhole.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'y') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "The room is humid, and steamy. Where is the steam coming from?";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'X') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "As you make your way through the cobwebs, the tunnel darkens.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'x') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "Is there... light at the end of this tunnel?";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'e') {
		map.at(nexty).at(nextx) = ' ';
		movecursor(j, 2 * map.at(0).size());
		cout << "You come into a room filled with heavy, unmoveable barrels and boxes.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'A') {
		map.at(nexty).at(nextx) = ' ';
		cout << "The torches are your only source of warmth in this empty dungeon. They warm your cold heart.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'v') {
		map.at(nexty).at(nextx) = ' ';
		cout << "These crates seem light enough. Maybe you can move them out of the way?";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'i') {
		map.at(nexty).at(nextx) = ' ';
		cout << "You see an old rusty key. Could this be used for something?";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'k') {
		map.at(nexty).at(nextx) = ' ';
		cout << "As you walk down the tunnel, you run your hand down the rugged, blue brick walls.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == '~') {
		map.at(nexty).at(nextx) = ' ';
		cout << "You see a vial of mysterious liquid. Should you drink it? Or even touch it? You're so thirsty...";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'l') {
		map.at(nexty).at(nextx) = ' ';
		cout << "You sneeze. The sneeze echoes through the corridor.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'j') {
		map.at(nexty).at(nextx) = ' ';
		cout << "You cough. The cough echoes down the corridor.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'h') {
		map.at(nexty).at(nextx) = ' ';
		cout << "As you walk down the tunnel, your footsteps become quieter.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'o') {
		map.at(nexty).at(nextx) = ' ';
		cout << "Bones litter the floor, and blood is splattered all over the walls.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'O') {
		map.at(nexty).at(nextx) = ' ';
		cout << "You see someone's skeleton. Someone has died here.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'r') {
		map.at(nexty).at(nextx) = ' ';
		cout << "As you walk down the corridor, your sense of smell and taste is returning!";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'R') {
		map.at(nexty).at(nextx) = ' ';
		cout << "The air tastes like salty coins, and a repungent odor of onions and cheese lingers in the air.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 't') {
		map.at(nexty).at(nextx) = ' ';
		cout << "As you turn the corner, you see a giant ogre at the end of the hallway!";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'T') {
		map.at(nexty).at(nextx) = ' ';
		cout << "His name is Carl. Carl burps and farts at the same. He is wielding a large club.";
		return 1;
	}

	else if (map.at(nexty).at(nextx) == 'J') {
		map.at(nexty).at(nextx) = ' ';
		cout << "Due to a lack of time and brain power, anything past this hallway is probably broken.";
		return 1;
	}
	else return 1;
}
