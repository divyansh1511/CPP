#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<int> q;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            q.push(s[i]);
        }
        if (s[i] == ')')
        {
            if (q.empty())
            {
                return false;
            }
            int a = q.top();
            q.pop();
            if (a != '(')
            {
                return false;
            }
        }
        if (s[i] == ']')
        {
            if (q.empty())
            {
                return false;
            }
            int a = q.top();
            q.pop();
            if (a != '[')
            {
                return false;
            }
        }
        if (s[i] == '}')
        {
            if (q.empty())
            {
                return false;
            }
            int a = q.top();
            q.pop();
            if (a != '{')
            {
                return false;
            }
        }
    }
    if (q.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
}