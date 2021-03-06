// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void drawBoard();
int gameStatus();
char squareNum[] = { '1','2','3','4','5','6','7','8','9' };

int main()
{
	int choice, currentPlayer = 0, gameOver = 0, moveCount = 0;

	while (gameOver == 0) {
		//assign X for player 1
		if (currentPlayer == 0) {
			drawBoard();
			//request move from player 1
			cout << "Player one, choose a valid square: ";
			cin >> choice;
			while ((choice < 1 || choice > 9) || (squareNum[choice - 1] == 'X' || squareNum[choice - 1] == 'O')) { //ensure square is valid and not already marked
				cout << "Player one, choose a valid square: ";
				cin >> choice;
			}
			squareNum[choice - 1] = 'X'; 						//change value of square
			moveCount++;										//increment move counter
			currentPlayer = 1;									//change current player to second player
			//if 1 has winning board, end game and output winner
			if (gameStatus() == 1) {
				cout << "\n\n";
				drawBoard();
				cout << "\n\nPlayer one wins!\n\n";
				break;
			}
			//draw game
			else if (gameStatus() == 3) {
				cout << "\n\n";
				drawBoard();
				cout << "\n\nIt's a draw!\n\n";
				break;
			}
		}
		//assign O for player 2
		if (currentPlayer == 1) {
			drawBoard();
			//if all 9 possible moves have been made and there is no winner, game ends in a tie (can only be in player 2's turn)
			if (moveCount > 8) {
				cout << "\n\n";
				drawBoard();
				cout << "\n\nTie game!\n\n";
				break;
			}
			//request move from player 2
			cout << "Player two, choose a valid square: ";
			cin >> choice;
			while ((choice < 1 || choice > 9) || (squareNum[choice - 1] == 'X' || squareNum[choice - 1] == 'O')) { //ensure square is valid and not already marked
				cout << "Player two, choose a valid square: ";
				cin >> choice;
			}
			moveCount++;										//increment move counter
			squareNum[choice - 1] = 'O';						//update value of board
			currentPlayer = 0;									//change current player to first player
			//if 2 has winning board, end game and output winner
			if (gameStatus() == 2) {
				cout << "\n\n";
				drawBoard();
				cout << "\n\nPlayer two wins!\n\n";
				break;
			}
			//draw game
			else if (gameStatus() == 3) {
				cout << "\n\n";
				drawBoard();
				cout << "\n\nIt's a draw!\n\n";
				break;
			}
		}
		gameOver = gameStatus();
	}

    return 0;
}

void drawBoard() { //draws board before each turn
	cout << "\n*TicTacToe*\n\n";
	cout << squareNum[0] << " | " << squareNum[1] << " | " << squareNum[2] << endl;
	cout << squareNum[3] << " | " << squareNum[4] << " | " << squareNum[5] << endl;
	cout << squareNum[6] << " | " << squareNum[7] << " | " << squareNum[8] << endl;
}

int gameStatus() {
	//if player 1 wins
	if ((squareNum[0] == 'X' && squareNum[1] == 'X' && squareNum[2] == 'X') || //top row is all X
		(squareNum[0] == 'X' && squareNum[4] == 'X' && squareNum[8] == 'X') || //top-left to bottom-right diagonal is all X
		(squareNum[2] == 'X' && squareNum[4] == 'X' && squareNum[6] == 'X') || //top-right to bottom-left diagonal is all X
		(squareNum[3] == 'X' && squareNum[4] == 'X' && squareNum[5] == 'X') || //middle row is all X
		(squareNum[6] == 'X' && squareNum[7] == 'X' && squareNum[8] == 'X')) //bottom row is all X
		return 1;

	//if player 2 wins
	else if ((squareNum[0] == 'O' && squareNum[1] == 'O' && squareNum[2] == 'O') || //top row is all O
		(squareNum[0] == 'O' && squareNum[4] == 'O' && squareNum[8] == 'O') || //top-left to bottom-right diagonal is all O
		(squareNum[2] == 'O' && squareNum[4] == 'O' && squareNum[6] == 'O') || //top-right to bottom-left diagonal is all O
		(squareNum[3] == 'O' && squareNum[4] == 'O' && squareNum[5] == 'O') || //middle row is all O
		(squareNum[6] == 'O' && squareNum[7] == 'O' && squareNum[8] == 'O')) //bottom row is all O
		return 2;

	//if game is drawn, i.e. all squares have been modified and there is no winning board
	bool drawGame;
	for (int i = 0; i < 9; i++) {
		if (squareNum[i] != 'X' && squareNum[i] != 'O')
			drawGame = false;
		else drawGame = true;
	}
	if (drawGame)
		return 3;

	return 0;
}
