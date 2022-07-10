#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> board , int row , int col){
    for (int i = row; i >= 0; i--)         // checking the column
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col; i >= 0 && j >= 0; i-- , j--)    // checking left diagonal
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col; i >= 0 && j < board.size(); i-- , j++)   // checking right diagonal
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void DFS(vector<string> &board , int row , vector<vector<string>> &res){
    if (row == board.size())
    {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (isSafe(board , row , i))
        {
            board[row][i] = 'Q';
            DFS(board , row+1 , res);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> Nqueens(int n){
    if (n <= 0)
    {
        return {{}};
    }
    vector<vector<string>> res;
    vector<string> board(n , string(n,'.'));
    DFS(board , 0 , res);
    return res;
}

int main(){

}