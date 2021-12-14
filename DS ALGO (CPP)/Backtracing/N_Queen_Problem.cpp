//-----------NOT completed-------------

#include<iostream>
using namespace std;

bool isSafe(int** board , int row , int col , int n){
    int i, j;

    for (i = 0; i < col; i++){
        if (board[row][i]){
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j]){
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--){
        if (board[i][j]){
            return false;
        }
    }
    return true;
}

bool nqueen(int** board , int row , int n){
    if (row == n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board , row , i , n))
        {
            board[row][i] = 1;
            if (nqueen(board , row+1 , n))
            {
                return true;
            }
            board[row][i] = 0;
        }
    }
    return false;
}

int main(){
    int** board = new int*[4];
    for (int i = 0; i < 4; i++)
    {
        board[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            cin>>board[i][j];
        }
    }
    
    if (nqueen(board, 0 , 4) == false) {
        printf("Solution does not exist");
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return true;
}