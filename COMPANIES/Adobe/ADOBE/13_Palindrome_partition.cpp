#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s , int st , int end){
    while (st < end)
    {
        if (s[st] != s[end])
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

void dfs(vector<vector<string>> &res , vector<string> &path , int st , string s){
    if (st == s.length())
    {
        res.push_back(path);
        return;
    }
    for (int i = st; i < s.length(); i++)
    {
        if (isPalindrome(s , st , i))
        {
            path.push_back(s.substr(st , i-st+1));
            dfs(res , path , i+1 , s);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    if (s.empty())
    {
        return res;
    }
    vector<string> path;
    dfs(res , path , 0 , s);
    return res;
}

int main(){

}