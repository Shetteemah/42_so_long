# 42 so_long

![Screenshot of so_long gameplay.](https://github.com/Shetteemah/42_so_long/blob/main/texture/Screen%20Shot%202023-04-07%20at%202.41.23%20AM.png?raw=true)

## Table of Contents
+ [Overview](#overview)
+ [Getting Started](#getting-started)
+ [Prerequisites](#prerequisites)
+ [Installation](#installation)
+ [Usage](#usage)
+ [Game Rules](#game-rules)

## Overview
so_long is a 2D game project for the 42 curriculum. The game is based on the classic "Sokoban" puzzle game, where the player moves a character around a map, pushing boxes to their designated spots, with the goal of completing each level.

In this project, the player is a character (shark) moving around a maze-like map (pool), with the goal of collecting all the collectable items and reaching the exit in as few moves as possible.

The game is built using the MinilibX library, which provides a simple and efficient way to draw graphics and handle input events on Linux.

## Getting Started
### Prerequisites
- Linux/macOS (tested on Ubuntu 20.04 and Mac 10.15.7)
- GCC (tested with version 9.3.0)
- MinilibX (tested with version 1.0)

### Installation
1. Clone the repository:
```
git clone https://github.com/Shetteemah/so-long.git
```
```
cd so-long
```
2. Compile the game:
```
make
```
## Usage
To start the game, run the `./so_long` executable:
```
./so_long maps/map.ber
```
The game will load the map file specified as the first argument, and display the game window.

Use `A`, `S`, `D`, and `W` keys to move the player character around the map. Collect all the required items and reach the exit to complete the level.

Press `ESC` or close the game window to exit the game.

## Game Rules
- The player character can only move in cardinal directions (up, down, left, right) one square at a time.
- The player character can collect items by moving onto them. Collected items are removed from the map.
- The player character can only exit the level if all required items have been collected.
- Enemies move randomly around the map, and will collide with the player character or obstacles if they move onto the same square.
- Obstacles block movement and cannot be moved by the player character.
- The game will not load if the path to a collectable or the exit is block.
- The game will not load if the shape of the map is not a rectangle and/or all the sorrounding borders are not covered with walls.
- The map can only be loaded if it contains all 5 elements `P` player, `C` collectable, `E` exit, `0`floor, and `1` wall. Any character outside of these within the map leads to an error.
