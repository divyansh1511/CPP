#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkisomorphic(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();

    if (n != m)
    {
        return false;
    }
    int count[256] = {0};
    int dcount[256] = {0};

    for (int i = 0; i < n; i++)
    {
        count[s1[i]]++;
        dcount[s2[i]]++;

        if (count[s1[i]] != dcount[s2[i]])
        {
            return false;
        }
    }
    return true;
}

int main(){
    cout << checkisomorphic("aab", "xxy") << endl;
    cout << checkisomorphic("aab", "xyz") << endl;
}