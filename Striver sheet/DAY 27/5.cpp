#include<bits/stdc++.h>
using namespace std;

void helper(string s , string a , vector<string> &ans , int i){
    if (i == s.length())
    {
        ans.push_back(a);
        return;
    }
    a += s[i];
    helper(s,a , ans , i+1);
    a.pop_back();
    helper(s , a , ans , i+1);
}

vector<string> solve(string s){
    vector<string> ans;
    string a = "";
    helper(s , a , ans , 0);
    return ans;
}

int main(){

}