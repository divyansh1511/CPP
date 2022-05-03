#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>> v , string s , int i , int j){
    if (!s.size())
    {
        return true;
    }
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] != s[0])
    {
        return false;
    }
    char a = v[i][j];
    v[i][j] = '*';
    string b = s.substr(1);
    bool res = DFS(v , b , i+1 , j) || DFS(v , b , i-1 , j) || DFS(v , b , i , j+1) || DFS(v , b , i , j-1);
    v[i][j] = a;
    return res;
}

bool isword(vector<vector<char>> v , string s){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (DFS(v , s , i , j))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){

}