#include<bits/stdc++.h>
using namespace std;

bool validanagrams(string s , string t){
    if (s.length() != t.length())
    {
        return false;
    }
    sort(s.begin() , s.end());
    sort(t.begin() , t.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }
    return true;
}

int main(){

}