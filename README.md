# Console-based Dungeon Game

This is a simple console-based dungeon game made for a computer science course. What set this game apart in the course is the fact that it utilizes emojis instead of basic ASCII characters to enhance visual experience. The requirements for this project were to include actors, points, combat, and a world.

## Features

- **Fog of War**: The game displays a world map that only reveals the immediate surrounding area. 

- **Emoji Map**: The world map is represented using emojis, adding a touch of visual appeal. The original version used basic ASCII values, and while the game still uses ASCII to represent the map, each emoji value is mapped to an emoji character.

- **Mini-games**: Inside this dungeon you will find some areas filled with boxes and pressure plates. In order to solve these puzzles, you will need to cover all pressure plates with boxes to continue to the next area. Note that if you push a box into a corner, you are doomed to reset the game. 

- **Collision Detection**: When you navigate through the dungeon, collision detection is in place to prevent you from passing through certain tiles. Whether it's walls, locks, items, doors, or enemies, the game will react to each differently.

- **Inventory System**: The game includes an inventory system that keeps track of important information about your character. It displays your current coordinates on the map, your health status, armor level, and the inventory items you have collected, such as potions, cheese, and keys.

- **Load and Save**: At program start, the game loads heroes and monsters from a file, placing these actors into the map accordingly. Although combat with enemies is trivial, the main point was to include some sort of "combat system". Upon exiting the game, it saves the progress, ensuring you can pick up where you left off.

## Dependencies

This game relies on the following external dependencies:

- [colors.h](https://github.com/ShakaUVM/colors.h): A header file provided by [ShakaUVM](https://github.com/ShakaUVM) offers color manipulation functions for the console. Make sure to download and include this library in your project.

- [read.h](https://github.com/ShakaUVM/read.h): A header file provided by [ShakaUVM](https://github.com/ShakaUVM) makes reading input from the keyboard a breeze. Make sure to download and include this library in your project.

## Getting Started

To get started with the game, follow these steps:

1. Clone the repository: `git clone https://github.com/timothyportnoff/rpg.git`
2. Navigate to the project directory: `cd rpg/`
3. Run the Makefile: `make`
4. Run the binary executable.

## Gameplay Instructions

- Use the arrow keys to navigate through the dungeon.
- Collect potions, cheese, and keys to aid you in your journey.
- Be cautious of pushing boxes into corners or areas that might leave you doomed. 
- Engage in battles with monsters and interact with heroes you encounter along the way.
- Stay alive and see if you can solve all the puzzles!

## License

This project is licensed under the [GNU General Public License (GPL)](https://www.gnu.org/licenses/gpl-3.0.en.html).

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to submit a pull request. Enjoy the game!
