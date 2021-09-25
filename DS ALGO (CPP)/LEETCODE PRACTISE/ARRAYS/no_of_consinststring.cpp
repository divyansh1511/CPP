#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countstrings(vector<string> v , string given){
    int ans = v.size();
    set<char> s(given.begin() , given.end());
    for (int i = 0; i < given.size(); i++)
    {
        vector<char> ch(v[i].begin() , v[i].end());
        for (int j = 0; j < ch.size(); j++)
        {
            if (s.count(ch[j]) == 0)
            {
                ans -= 1;
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<string> v = {"ad","bd","aaab","baa","badab"};
    cout<<countstrings(v , "ab")<<endl;
}