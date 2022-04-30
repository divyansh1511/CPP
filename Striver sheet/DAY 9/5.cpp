#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s , int i , int j){
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

void helper(int index , string s , vector<vector<string>> ans , vector<string> v){
    if (index == s.length())
    {
        ans.push_back(v);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (ispalindrome(s , index , i))
        {
            v.push_back(s.substr(index , i - index+1));
            helper(i+1 , s , ans , v);
            v.pop_back();
        }
    }
}

vector<vector<string>> palindromepartition(string s){
    vector<vector<string>> ans;
    if (s.empty())
    {
        return ans;
    }
    vector<string> tt;
    helper(0 , s , ans , tt);
    return ans;
}

int main(){

}