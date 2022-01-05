//-----------LONGEST SUBSTRING WITHOUT REPEAT------------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxlen(string s){
    unordered_map<char ,int> mp;
    int len = 0;
    int left = 0 , right = 0;
    int n = s.length();
    while (right < n)
    {
        if (mp[s[right]] != -1)
        {
            left = max(mp[s[right]]+1 , left);
        }
        mp[s[right]] = right;
        len = max(len , right - left + 1);
        right++;
    }
    return len;
}

int main(){
    cout<<maxlen("abcabcbb")<<endl;
}