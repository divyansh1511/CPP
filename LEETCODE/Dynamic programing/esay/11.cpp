#include<bits/stdc++.h>
using namespace std;

bool issubsequence(string s , string t){
    if (s.length() > t.length())
    {
        return false;
    }
    int j = 0 , i = 0;
    while (j < s.length() && i < t.length())
    {
        if (s[j] == t[i])
        {
            j++;
        }
        i++;
    }
    if (j < s.length())
    {
        return false;
    }
    return true;
}

int main(){

}