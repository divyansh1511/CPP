#include<bits/stdc++.h>
using namespace std;

void allduplicates(string s){
    unordered_map<char , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

int main(){

}