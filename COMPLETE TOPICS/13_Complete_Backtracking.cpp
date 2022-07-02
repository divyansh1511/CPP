#include<bits/stdc++.h>
using namespace std;

//-----------------------------------RAT IN MAZE--------------------------------//

bool isSafe(vector<vector<int>> v , int x , int y , int n , int m){
    if (x >=0 && x < n && y >= 0 && y < n && v[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool helper(vector<vector<int>> v , int x , int y , vector<vector<int>> &ans , int n , int m){
    if (x == n-1 && y == m-1 && v[x][y] == 1)
    {
        ans[x][y] = 1;
        return true;
    }
    if (isSafe(v , x , y , n , m))
    {
        if (ans[x][y] == 1)
        {
            return false;
        }
        ans[x][y] = 1;
        if (helper(v , x+1 , y , ans , n , m))
        {
            return true;
        }
        if (helper(v , x , y+1 , ans , n , m))
        {
            return true;
        }
        ans[x][y] = 0;
        return false;
    }
    return false;
}

vector<vector<int>> RatinMaze(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    vector<vector<int>> ans(n , vector<int>(m , 0));
    helper(v , 0 , 0 , ans , n , m);
    return ans;
}

//---------------------------------------COMBINATION SUM--------------------------//

void helpers(vector<int> v , int sum , vector<int> &res , vector<vector<int>> &ans , int i){
    if (sum == 0)
    {
        ans.push_back(res);
        return;
    }
    while (i < v.size() && sum - v[i] >= 0)
    {
        res.push_back(v[i]);
        helpers(v , sum-v[i] , res , ans , i);
        i++;
        res.pop_back();
    }
    
}

vector<vector<int>> combinationsum(vector<int> v , int sum){
    sort(v.begin() , v.end());
    v.erase(unique(v.begin() , v.end()) , v.end());
    vector<int> res;
    vector<vector<int>> ans;
    helpers(v , sum , res , ans , 0);
    return ans;
}

//--------------------------------------N Queen Problem-----------------------------------//

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

}