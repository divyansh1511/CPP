#include<bits/stdc++.h>
using namespace std;

bool validPalindrome(string s){
    transform(s.begin() , s.end() , s.begin() , ::tolower);
    int n = s.length();
    string ab = "";
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            ab += s[i];
        }
    }
    int n = ab.length();
    int i = 0 , j = n-1;
    while (i<j)
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

int main(){

}