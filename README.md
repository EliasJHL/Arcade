# Arcade

## About The Project

This project is a dynamic and modular game engine developed as part of the Epitech curriculum. The Arcade executable can load various games and graphical rendering libraries at runtime from shared library files (`.so`). This design allows for seamless switching between games and visual styles without recompiling or restarting the main application.

The core of the application orchestrates the interaction between a loaded game and a loaded graphical library, both of which adhere to a common interface.

## Features

*   **Dynamic Module Loading:** Games and graphical libraries are loaded as plugins from `.so` files at runtime.
*   **Real-time Switching:**
    *   Instantly switch between different graphical libraries.
    *   Swap between different game modules or return to the main menu at any time.
*   **Modular Architecture:** A central `Core` engine manages interactions between game and display modules through a set of defined interfaces (`IGame`, `IDisplay`).
*   **Included Games:**
    *   **Menu:** A startup menu to browse and select available games and graphical libraries.
    *   **Snake:** The classic arcade game where you grow by eating apples.
    *   **Nibbler:** A challenging, maze-based variant of Snake.
*   **Supported Graphical Libraries:**
    *   **SFML**
    *   **SDL2**
    *   **Ncurses** (Terminal-based)
    *   **Xlib**

## Getting Started

### Prerequisites

You will need a C++ compiler (`g++`) and `make`. Additionally, the development libraries for all supported graphical modules are required.

On a Debian-based system (like Ubuntu), you can install them with the following command:

```bash
sudo apt-get update
sudo apt-get install build-essential make libsfml-dev libsdl2-dev libsdl2-ttf-dev libncurses-dev libx11-dev
```

### Building

To compile the core executable and all the game/graphical libraries, simply run the `make` command from the root of the repository:

```bash
make
```

This will create the `arcade` executable in the root directory and place all the compiled `.so` library files into the `./lib/` directory.

### Running

Launch the application by providing the path to an initial graphical library as a command-line argument.

```bash
# Example using SFML
./arcade ./lib/arcade_sfml.so

# Example using Ncurses
./arcade ./lib/arcade_ncurses.so
```

Once running, you will be greeted by the main menu, where you can select a game to play.

## Usage and Controls

The application features a set of core controls that work across all modules, as well as game-specific controls.

### Core Controls

These controls are handled by the core engine and allow you to manage the application's state.

| Key       | Action                                 |
|-----------|----------------------------------------|
| `T`       | Switch to the next graphical library.  |
| `Y`       | Switch to the next game.               |
| `F1`      | Return to the main menu.               |
| `Escape`  | Quit the application.                  |

### In-Game Controls

| Key           | Action                |
|---------------|-----------------------|
| `Arrow Keys`  | Player movement.      |
| `Enter`       | Select (in menu).     |

## Project Architecture

The architecture is designed to be highly decoupled, relying on a set of interfaces and dynamic loading.

*   **`Core` Engine:** The central component that loads libraries, manages the main loop, and routes events from the display module to the game module.
*   **`IDisplay` Interface:** Defines the contract that all graphical libraries must follow. This includes methods for creating a window, drawing primitives (`Rect`, `Text`), and polling for user input events.
*   **`IGame` Interface:** Defines the contract for all games. This includes methods to initialize the game state, handle events, update game logic, and provide the `Core` with a list of objects to render.
*   **`DLLoader`:** A template class that encapsulates the logic for loading shared libraries (`dlopen`, `dlsym`) and creating instances of the game or display classes within them.

This setup ensures that the `Core` does not need to know any implementation details of a specific game or graphical library. It only interacts with them through the abstract `IGame` and `IDisplay` interfaces.

## Code Structure

```
.
├── assets/             # Font files for graphical libraries
├── include/            # Core engine headers and interfaces
│   ├── interfaces/     # ICore, IDisplay, and IGame interfaces
│   ├── ADisplayModule.hpp # Abstract base class for display modules
│   ├── AGameModule.hpp # Abstract base class for game modules
│   ├── Core.hpp        # Main engine header
│   └── DLLoader.hpp    # Dynamic library loader template
├── lib/                # Compiled .so libraries and their source code
│   ├── games/          # Game modules (Snake, Nibbler, Menu)
│   └── graphical/      # Graphical modules (SFML, SDL2, Ncurses, Xlib)
├── src/                # Source code for the main executable
│   ├── main.cpp        # Entry point of the application
│   └── DLLoader.cpp    # Implementation of the DLLoader
├── Makefile            # Main build script
└── README.md
