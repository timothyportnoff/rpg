void print_title(string title) {
	system("clear");
	system("figlet -f slant 'Welcome' | lolcat");
	sleep(1);
	system("figlet -f slant '\tTo' | lolcat");
	sleep(1);
	system("figlet -f slant '\t\tHell' | lolcat");
	sleep(1);
}
void print_ending(int ending) {
	system("clear");
	if (ending == -1) {
		std::cout << "ERROR. TERMINATING GAME" << std::endl;
	}
	else if (ending == 0) {
		system("figlet -f slant 'Dead' | lolcat");// << std::cout << endl;
	}
	else if (ending == 1) {
		system("figlet -f slant 'You win' | lolcat");// << std::cout << endl;
	}
	else {
		system("figlet -f slant 'NO ENDING HERE' | lolcat");// << std::cout << endl;
	}
	exit(1);
}

