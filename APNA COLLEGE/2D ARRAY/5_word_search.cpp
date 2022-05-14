#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>> v , string s , int i , int j){
    if (s.length() == 0)
    {
        return true;
    }
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] != s[0])
    {
        return false;
    }
    char c = v[i][j];
    v[i][j] = '*';
    s = s.substr(1);
    bool res = DFS(v , s , i-1 , j) || DFS(v , s , i+1 , j) || DFS(v , s , i , j-1) || DFS(v , s , i , j+1);
    v[i][j] = c;
    return res;
}

bool wordsearch(vector<vector<char>> v , string s){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
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