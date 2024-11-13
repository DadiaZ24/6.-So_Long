# 🕹️ So Long

A basic 2D game project created in C with minilibx as part of the 42 School curriculum. The objective is to navigate a character through a maze, collect items, and reach an exit.

![](https://github.com/DadiaZ24/6.-So_Long/blob/main/preview.gif?raw=true)

## 📄 Project Overview

The So Long project involves creating a simple 2D game where a player controls a character navigating through a map, collecting items, and finding an exit. The game leverages minilibx for graphics rendering, handling textures, and player movement.
## ✨ Features

* 2D Graphics Rendering: Uses the minilibx library for rendering images and handling window interactions.
* Tile-based Map Layout: Reads and displays a map from a file, using tiles for walls, collectibles, player, and exit.
* Simple Gameplay Mechanics: Collect all items to unlock the exit and complete the game.
* Player Movement: Supports basic keyboard controls for player movement.
* Map Validation: Ensures the map is valid, enclosed by walls, and meets the requirements (one exit, one player, etc.).

## 💎 Special Features
### 1. Image Transparency

This feature enhances the graphical quality by allowing background pixels to show through specific parts of an image. Specifically:

* Pixel-Level Transparency: The game uses a function that replaces all black pixels (rgba(0, 0, 0, 0)) in an image with the background pixels behind it.
* Dynamic Background Integration: As the character or objects with transparent areas move across the screen, the background seamlessly shows through the specified transparent sections, creating a more visually appealing effect.

### 2. Smooth Movement

To improve the fluidity of the game, the character moves smoothly across the screen rather than snapping from tile to tile:

* Pixel-by-Pixel Movement: Movement is broken down into smaller, pixel-by-pixel steps instead of whole-tile jumps. This creates a smooth, continuous motion.
* Enhanced Player Control: Smooth movement allows for more precise positioning and creates a more polished gameplay experience.

These enhancements contribute to a more dynamic and visually engaging game, making the overall player experience smoother and more immersive.

📁 Project Structure

    .
    │   Makefile                             # Compiles the project
    │   README.md                            # Project documentation
    │
    ├───include                              # Folder with all header files (.h files)
    │       so_long.h                        # Main header file for game functions
    │       so_long_bonus.h                  # Bonus functionality header file
    │
    ├───libs                                 # Folder containing all necessary libraries
    │   ├───libft                            # Custom library (libft)
    │   │   └───printf                       # Custom printf implementation
    │   └───minilibx-linux                   # Minilibx library for graphics
    ├───maps                                 # Folder containing map files
    ├───src                                  # Folder containing all source code
    │   ├───main.c                           # Entry point for the game
    │   ├───inits                            # Folder for game initialization
    │   │   ├───init_data.c                  # Initialize game data
    │   │   └───init_data2.c                 # Additional initialization code
    │   ├───map_utils                        # Folder for map utilities
    │   │   ├───colide                       # Folder for collision-related files
    │   │   │   ├───colectible_check.c       # Check for collectible collisions
    │   │   │   ├───colide.c                 # General collision logic
    │   │   │   ├───exit_check.c             # Check for exit collisions
    │   │   │   └───temp_colide_utils.c      # Temporary collision utilities
    │   │   ├───parser                       # Folder for map parsing
    │   │   │   ├───map_parser.c             # Parse the map file
    │   │   │   └───map_parser_utils.c       # Helper functions for parsing
    │   │   └───render                       # Folder for map rendering
    │   │       ├───map_render.c             # Render the map tiles
    │   │       ├───map_utils.c              # Utility functions for map rendering
    │   │       └───tile.c                   # Tile handling functions
    │   ├───movement                         # Folder for player movement logic
    │   │   ├───key_press_utils.c            # Handle key press events
    │   │   ├───key_utils.c                  # Handle key-related functions
    │   │   └───movement.c                   # Main movement handling functions
    │   └───others                           # Folder for other utilities
    │       ├───free_utils.c                 # Freeing memory utility
    │       └───replace_pixel.c              # Pixel replacement functions (e.g., transparency)
    │
    ├───src_bonus                            # Folder for bonus features
    │   ├───main_bonus.c                     # Entry point for bonus version of the game
    │   ├───inits                            # Folder for bonus initialization code
    │   │   ├───init_data2_bonus.c               # Bonus initialization (extra data)
    │   │   └───init_data_bonus.c                # Main bonus initialization
    │   ├───map_utils                            # Folder for bonus map utilities
    │   │   ├───colide                           # Folder for bonus collision checks
    │   │   │   ├───colectible_check_bonus.c     # Bonus collectible check
    │   │   │   ├───colide_bonus.c               # Bonus collision logic
    │   │   │   ├───exit_check_bonus.c           # Check for exit collisions (bonus)
    │   │   │   ├───enemy_colide_bonus.c         # Bonus enemy collision logic
    │   │   │   └───temp_colide_utils_bonus.c    # Temporary collision utilities (bonus)
    │   │   ├───parser                           # Folder for bonus map parsing
    │   │   │   ├───map_parser_bonus.c           # Bonus map parsing
    │   │   │   └───map_parser_utils_bonus.c     # Helper functions for bonus parsing
    │   │   └───render                           # Folder for bonus map rendering
    │   │       ├───map_render_bonus.c           # Render bonus map tiles
    │   │       └───tile_bonus.c                 # Bonus tile handling
    │   ├───movement                             # Folder for bonus player movement
    │   │   ├───key_press_utils_bonus.c          # Bonus key press handling
    │   │   ├───key_utils_bonus.c                # Bonus key utilities
    │   │   ├───movement_bonus.c                 # Bonus movement handling
    │   │   └───put_string_window_bonus.c        # Bonus string rendering to window
    │   └───others                               # Folder for other bonus utilities
    │       ├───free_utils_bonus.c               # Freeing memory for bonus version
    │       └───replace_pixel_bonus.c            # Pixel replacement functions (bonus)
    │
    └───textures                    # Folder for game textures (sprites)
        └───exit_sprite             # Folder for exit sprite frames


## 🚀 Getting Started
### Prerequisites

* GNU Make: Required to compile the project.
* CC: GNU Compiler Collection for compiling C code.
* minilibx: A simple X-Window library for graphics rendering.
* Libft: Custom library of utility functions required by the project.

### Compilation

To compile the project, run:

    make

This command generates an executable called so_long.
### Usage

After compiling, run the game with:

    ./so_long [map_file.ber]

Replace [map_file.ber] with the path to a map file in .ber format. For example:

    ./so_long maps/map.ber

Controls

    UP ARROW: Move up
    LEFT ARROW: Move left
    DOWN ARROW: Move down
    RIGH ARROW: Move right
    ESC: Exit the game

Example Map Format

The map file (.ber format) should consist of characters representing different game elements:

    1: Wall
    0: Empty space
    P: Player start position (must have exactly one P)
    C: Collectible item
    E: Exit (must have exactly one E)

Example map.ber:

    111111
    1P0C01
    100001
    1C0E01
    111111

📝 Implementation Details

* Map Parsing and Validation: The program reads the map from a .ber file and checks if it is valid, enclosed by walls, and contains the necessary elements.
* Game Loop: Uses a game loop to handle player input, update game state, and render each frame.
* Graphics Rendering: The minilibx library handles the rendering of 2D sprites for player, walls, collectibles, and exit tiles.
* Memory Management: The project includes careful memory allocation and freeing routines to prevent leaks.

🏆 Credits

Project by Diogo Ferreira as part of the curriculum at 42 School.
