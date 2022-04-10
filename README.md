# 15 Puzzle Game
The 15 puzzle is a sliding puzzle having 15 square tiles numbered 1–15 in a frame that is 4 tiles high and 4 tiles wide, leaving one unoccupied tile position. Tiles in the same row or column of the open position can be moved by sliding them horizontally or vertically, respectively. The goal of the puzzle is to place the tiles in numerical order.


# How it is implemented
Every time it is launched it creates a new random puzzle and checks that this admits a solution, otherwise it creates another one until a solvable one comes out. 
The player is allowed to move the tiles by typing one of the 4 near tiles the blank space (vertically and horizontally). The game ends when all the tiles are in ascending order.

For the sake of convenience zero is considered as the blank space. 
