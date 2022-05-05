#include<bits/stdc++.h>
using namespace std;

bool backSpaceComparing(string s , string t){
    stack<char> a1 , a2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '#')
        {
            a1.push(s[i]);
        }
        else
        {
            if (a1.empty())
            {
                continue;
            }
            else
            {
                a1.pop();
            }
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != '#')
        {
            a2.push(t[i]);
        }
        else
        {
            if (a2.empty())
            {
                continue;
            }
            else
            {
                a2.pop();
            }
        }
    }
    string s1 = "" , s2 = "";
    while (!a1.empty())
    {
        s1 += a1.top();
        a1.pop();
    }
    while (!a2.empty())
    {
        s2 += a2.top();
        a2.pop();
    }
    return s1 == s2;
}

int main(){

}