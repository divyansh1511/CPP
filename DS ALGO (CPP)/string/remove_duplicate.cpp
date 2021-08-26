#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removestr(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (s.empty())
        {
            s.push(str[i]);
        }
        else
        {
            char a = s.top();
            if (a != str[i])
            {
                s.push(str[i]);
            }
            else
            {
                continue;
            }
        }
    }
    string a = "";
    while (!s.empty())
    {
        a += s.top();
        s.pop();
    }
    reverse(a.begin(), a.end());
    
    return a;
}

int main(){
    string a = removestr("aabaa");
    cout<<a<<endl;
}