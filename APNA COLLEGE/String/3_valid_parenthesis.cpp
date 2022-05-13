#include<bits/stdc++.h>
using namespace std;

bool validparenthesis(string s){
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '(')
            {
                return false;
            }
        }
        if (s[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '[')
            {
                return false;
            }
        }
        if (s[i] == '}')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '{')
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main(){

}