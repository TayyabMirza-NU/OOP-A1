#include <iostream>
using namespace std;

int** createDynamicBoard(int N) {
    int** dynamicBoard = new int* [N];
    for (int i = 0; i < N; i++) {
        dynamicBoard[i] = new int[N];
        for (int j = 0; j < N; j++) {
            dynamicBoard[i][j] = 0;
        }
    }
    return dynamicBoard;
}

void deleteBoard(int** board,int N) {
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
}

bool checkAvailability(int **board, int y,int x,int N){
    for (int i = 0; i <= x; i++)
    {
        if(board[y][i]==1)
            return false;
    }
    for (int i = 0; i <= y; i++)
    {
        if(board[i][x]==1)
            return false;
    }
    if(y>=x){
    for (int i = y,j=x; i>=0; i--,j--)
     {
        if (board[i][j]==1)
            return false;
    }
    for (int i = y, j=x; i<N; i++,j--)
    {
        if (board[i][j]==1)
            return false;
    }
    
    }
    else if(y<x){
    for (int i = y,j=x; i >= 0; i--,j--)
    {
        if (board[i][j]==1)
        {
            return false;
        }
    }
    for (int i = y, j=x; i < N; i++,j--)
    {
        if (board[i][j]==1)
            return false;
    }
    }
    return true;
    
}

bool NQueenSolver(int ** board,int N,int x=0, int y=0,int Queens=0){

    if(Queens==N){
        return true;
    }

    if (x >= N) {
        return false;
    }
     if (y >= N) {
        return false;
    }


    if(checkAvailability(board, y, x, N)){
        board[y][x]= 1;
        
        if(NQueenSolver(board, N, x+1,0,Queens+1)){
            return true;
        }
        board[y][x]= 0;
    }

    return NQueenSolver(board, N, x,y+1,Queens);
}
 
int main(){
    

    int N=4;
    int** dynamicBoard = createDynamicBoard(N);
    // checkAvailability(dynamicBoard, 1, 3, N);
    bool result=NQueenSolver(dynamicBoard,N);
    cout<<endl<<result<<endl<<endl;
    if(result)
    cout<<"Solved "<<N<<"-Queen: "<<endl<<endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <N; j++)
        {
            (dynamicBoard[i][j])?cout<<"O ":cout<<"* ";
        }
        cout<<endl;
        
    }
    
    deleteBoard(dynamicBoard,N);
    
    return 0;
}