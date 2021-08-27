#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string printsequence(string str[] , string s){
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        // if (s[i] == " ")
        // {
        //     ans = ans + '0';
        // }
        int pos = s[i] - 'A';
        ans = ans + str[pos];
    }
    return ans;
}

int main(){
    string str[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    std::string input; 
    std::getline( std::cin, input);
    cout << printsequence(str, input);
}