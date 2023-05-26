#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

/* This is the Life game, made by the mathematician John Horton Conway in the 70's. I saw this game on YouTube and thought it was awesome,
so I decided to give it a try */

const int ROWS = 20;
const int COLS = 45;

void initBoard(vector<vector<bool>>& board) { 
    int deadOrAlive;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            deadOrAlive = rand() % 10;
            if (deadOrAlive < 4) {
                board[i][j] = true;
            }
            else {
                board[i][j] = false;
            }
        }
    }

}




bool isAlive(vector<vector<bool>>& board, int x, int y) {
    int alive = 0;
    
    for (int i = -1; i <= 1; i++) { 
        for (int j = -1; j <= 1; j++) { 
            // Doesn't check itself
            if (i == 0 && j == 0) 
                continue; 
            // Checks if the neighbor cell is inside the board
            if (x + i < 0 || x + i >= ROWS || y + j < 0 || y + j >= COLS) 
                continue; 
            // Checks if the neighbor cell is alive
            if (board[x + i][y + j]) 
                alive++; 
        }
    }



    if (board[x][y] == true && alive < 2) {
        return false;
    }
    if (board[x][y] == true && (alive == 2 || alive == 3)) {
        return true;
    }
    if (alive > 3) {
        return false;
    }
    if (board[x][y] == false && alive == 3) {
        return true;
    }
    return false;
}

void checkBoard(vector<vector<bool>>& board) {
    vector<vector<bool>> new_board(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]) {
                if (isAlive(board, i, j)) {
                    new_board[i][j] = true;
                }
            }
            else {
                if(isAlive(board, i, j)){
                    new_board[i][j] = true;
                }
            }
        }
    }

    board = new_board; 

}


void renderBoard(const vector<vector<bool>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]) {
                cout << "# ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}





int main()
{
    vector<vector<bool>> board(ROWS, vector<bool>(COLS, false));
    initBoard(board);

    while (true) {
        system("cls");
        checkBoard(board);
        renderBoard(board);
        Sleep(100);
    }
    return 0;

}


