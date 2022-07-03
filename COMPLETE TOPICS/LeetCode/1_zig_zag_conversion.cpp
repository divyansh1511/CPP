#include<bits/stdc++.h>
using namespace std;

string ZigZagConversion(string s , int rows){
    if (rows <= 1)
    {
        return s;
    }
    vector<vector<char>> v(rows);
    int j = 0;
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        v[j].push_back(s[i]);
        if (flag)
        {
            if (j == rows-1)
            {
                flag = false;
                j--;
                continue;
            }
            j++;
        }
        else
        {
            if (j == 0)
            {
                flag = true;
                j++;
                continue;
            }
            j--;
        }
    }
    string ans = "";
    for(auto it : v){
        for(auto x : it){
            ans += x;
        }
    }
    return ans;
}

int main(){

}