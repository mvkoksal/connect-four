# Connect Four - Terminal Version

This is a simple terminal-based rendition of the classic **Connect Four** game.

## Game Overview
- The game is played on a grid stored in an array.  
- Two players take turns: **Red** and **Blue**.  
- On each turn, a player drops their letter into one of the columns.  
- The letter falls to the lowest available spot in that column.  
- The first player to get **four letters in a row** (horizontally, vertically, or diagonally) wins!

## How to Play
1. Run the game in your terminal.  
2. Players choose a column by entering a number.  
3. The game updates the board after each move.  
4. Play continues until one player connects four or the board is full (a draw).

## Features
- Simple array-based board storage  
- Two-player gameplay  
- Win detection in all directions  
- Clear terminal display for easy gameplay

## Requirements
- C compiler (clang to use the Makefile)
- Terminal or command-line interface

## How to Run
```bash
make
./connect-four
