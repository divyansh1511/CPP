#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string duplicate(string s , int k){
    int i = 0 , n = s.length();
    vector<int> count(n);
    for (int j = 0; j < n; j++,i++)
    {
        s[i] = s[j];
        count[i] = i > 0 && s[i-1] == s[j] ? count[i-1]+1:1;
        if (count[i] == k)
        {
            i -= k;
        }
    }
    return s.substr(0 , i);
}

int main(){
    string s = "aabcc";
    cout<<duplicate(s , 2)<<endl;
}