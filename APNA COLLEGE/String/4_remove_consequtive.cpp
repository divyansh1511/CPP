#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string S)
{
    string a = "";
    for (int i = 0; i < S.length(); i++)
    {
        if (a == "" || S[i] != a[a.length() - 1])
        {
            a += S[i];
        }
    }
    return a;
}

int main()
{
    
}