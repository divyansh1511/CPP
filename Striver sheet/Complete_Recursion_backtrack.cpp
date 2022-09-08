#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int n , int st , int sum , vector<int> &ans){
    if (st == n)
    {
        ans.push_back(sum);
        return;
    }
    helper(v , n , st+1 , sum , ans);
    helper(v , n , st+1 , sum+v[st] , ans);
}

vector<int> SubsetSum(vector<int> v){
    int n = v.size();
    vector<int> ans;
    helper(v , n , 0 , 0 , ans);
    sort(ans.begin() , ans.end());
    return ans;
}

void helper2(vector<int> &v , int ind , vector<int> h , vector<vector<int>> &ans){
    ans.push_back(h);
    for (int i = ind; i < v.size(); i++)
    {
        if (i > ind && v[i] == v[i-1])
        {
            continue;
        }
        h.push_back(v[i]);
        helper2(v , ind+1 , h , ans);
        h.pop_back();
    }
    
}

vector<vector<int>> subsets(vector<int> v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> h;
    helper2(v , 0 , h , ans);
    return ans;
}

void helper3(vector<int> v , int ind , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (ind == v.size())
    {
        if (target == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[ind] < target)
    {
        tmp.push_back(v[ind]);
        helper3(v , ind , target-v[ind] , tmp , ans);
        tmp.pop_back();
    }
    helper3(v , ind , target , tmp , ans);
}

vector<vector<int>> combinationSum(vector<int> v , int target){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper3(v , 0 , target , tmp , ans);
    return ans;
}

void helper4(vector<int> v , int ind , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (target == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = ind; i < v.size(); i++)
    {
        if (i > ind && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        tmp.push_back(v[i]);
        helper4(v , ind+1 , target-v[i] , tmp , ans);
        tmp.pop_back();
    }
    
}

vector<vector<int>> combinationSum2(vector<int> v , int target){
    vector<vector<int>> ans;
    vector<int> temp;
    helper4(v , 0 , target , temp , ans);
    return ans;
}

bool isPalindrome(string s , int i , int j){
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void helper5(string s , int ind , vector<string> tmp , vector<vector<string>> &v){
    if (ind == s.length())
    {
        v.push_back(tmp);
        return;
    }
    for (int i = ind; i < s.length(); i++)
    {
        if (isPalindrome(s , ind , i))
        {
            tmp.push_back(s.substr(ind , i-ind+1));
            helper5(s , ind+1 , tmp , v);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> v;
    if (s.empty())
    {
        return v;
    }
    vector<string> tmp;
    helper5(s , 0 , tmp , v);
    return v;
}

void helper6(vector<int> v , int st , vector<vector<int>> &ans){
    if (st >= v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        swap(v[i] , v[st]);
        helper6(v , i+1 , ans);
        swap(v[i] , v[st]);
    }
}

vector<vector<int>> printallpermutations(vector<int> v){
    vector<vector<int>> ans;
    helper6(v , 0 , ans);
    return ans;
}

bool is_valid(vector<string> &v , int row , int col){
    for(int i=row;i>=0;--i)
        if(v[i][col] == 'Q') return false;
    for(int i=row,j=col;i>=0&&j>=0;--i,--j)
        if(v[i][j] == 'Q') return false;
    for(int i=row,j=col;i>=0&&j<v.size();--i,++j)
        if(v[i][j] == 'Q') return false;
    return true;
}

void dfs(vector<string> &v , int st , vector<vector<string>> &ans){
    if (st == v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (is_valid(v , st , i))
        {
            v[st][i] = 'Q';
            dfs(v , st+1 , ans);
            v[st][i] = '.';
        }
    }
}

vector<vector<string>> solveNqueen(int n){
    if (n <= 0)
    {
        return {{}};
    }
    vector<vector<string>> ans;
    vector<string> v(n , string(n , '.'));
    dfs(v , 0 , ans);
    return ans;
}

bool isSafe(vector<vector<char>> &board , int i , int j , char c){
    int row = i - i%3 , col = j - j%3;
    for(int x=0;x<9;x++){
        if(board[x][j] == c){
            return false;
        }
    }
    for(int y=0;y<9;y++){
        if(board[i][y] == c){
            return false;
        }
    }
    for(int x = 0;x<3;x++){
        for(int y=0;y<3;y++){
            if(board[row + x][col+y] == c){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board , int i , int j){
    if(i == 9){
        return true;
    }
    if(j == 9){
        return solveSudoku(board , i+1 , 0);
    }
    if(board[i][j] != '.'){
        return solveSudoku(board , i , j+1);
    }
        
    for(char c = '1'; c<='9' ; c++){
        if(isSafe(board , i , j , c)){
            board[i][j] = c;
            if(solveSudoku(board , i , j+1)){
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board , 0 , 0);
}

int main(){

}