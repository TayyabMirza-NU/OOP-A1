#include <iostream>
#include<cstdlib>
#include <windows.h>
using namespace std;

int** createDynamicBoard(int board[9][9]) {
    int** dynamicBoard = new int* [9];
    for (int i = 0; i < 9; i++) {
        dynamicBoard[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            dynamicBoard[i][j] = board[i][j];
        }
    }
    return dynamicBoard;
}

void deleteBoard(int** board) {
    for (int i = 0; i < 9; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool isValidTestNum(int** board,int x,int y,int num){

    for (int i = 0; i < 9; i++){
        if(board[y][i]==num){
            return false;
        }
    }
    for (int i = 0; i < 9; i++){
        if(board[i][x]==num){
            // cout << "Failed column check at (" << i << ", " << x << ")\n";
            return false;
        }
    }
    int subGridStartY= (y/3)*3;
    int subGridSEndY= subGridStartY + 3;
    int subGridStartX= (x/3)*3;
    int subGridSEndX= subGridStartX + 3;
    for (int i = subGridStartY; i < subGridSEndY; i++)
    {
        for (int j = subGridStartX; j < subGridSEndX; j++)
        {
             if(board[i][j]==num){
            // cout << "Failed column check at (" << i << ", " << j << ")\n";
            return false;
             }
        }
        
    }
    // cout << "Number " << num << " is valid at (" << y << ", " << x << ")\n";

    return true;
}

bool solveSudoku(int** board, int x = 0, int y = 0,int num=1) {
    if (x == 9) {
        return true;
    }
    if (y == 9) {
        return solveSudoku(board, x+1, 0,1);
    }

    if (board[y][x] != 0) {
        return solveSudoku(board, x , y+1,1);
    }

    
    if (num > 9) {
        return false;
    }

    if (isValidTestNum(board, x, y, num)) {
        board[y][x] = num; 
    //     system("cls");
        
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j <9; j++)
    //     {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    //     Sleep(200);
        if (solveSudoku(board, x , y+1, 1)) {
            return true;
        }

        board[y][x] = 0;

    //      system("cls");
        
    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j <9; j++)
    //     {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    //     Sleep(200);
    }

    return solveSudoku(board, x, y, num + 1);
}
 
int main(){
     int board[9][9] = {
     {5, 3, 0, 0, 7, 0, 0, 0, 0},
     {6, 0, 0, 1, 9, 5, 0, 0, 0},
     {0, 9, 8, 0, 0, 0, 0, 6, 0},
     {8, 0, 0, 0, 6, 0, 0, 0, 3},
     {4, 0, 0, 8, 0, 3, 0, 0, 1},
     {7, 0, 0, 0, 2, 0, 0, 0, 6},
     {0, 6, 0, 0, 0, 0, 2, 8, 0},
     {0, 0, 0, 4, 1, 9, 0, 0, 5},
     {0, 0, 0, 0, 8, 0, 0, 7, 9}
 };

    int** dynamicBoard = createDynamicBoard(board);
    int originalBoard[9][9];
    bool result=solveSudoku(dynamicBoard);
    cout<<endl<<endl<<result<<endl<<endl;
    if(result)
    cout<<endl<<"Solved Sudoku: "<<endl<<endl;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <9; j++)
        {
            cout<<dynamicBoard[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    deleteBoard(dynamicBoard);
    
    return 0;
}