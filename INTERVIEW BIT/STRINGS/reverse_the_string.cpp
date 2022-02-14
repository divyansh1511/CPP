#include<bits/stdc++.h>
using namespace std;

string ReverseStringInWords(string s){
    stack<string> st;
    string a = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (a != "")
            {
                st.push(a);
            }
            a = "";
        }
        else
        {
            a += s[i];
        }
    }
    if (a != "")
    {
        st.push(a);
    }
    if (st.empty())
    {
        return "";
    }
    string ans = "";
    string t = st.top();
    st.pop();
    ans += t;
    t = "";
    while (!st.empty())
    {
        ans += ' ';
        t = st.top();
        st.pop();
        ans += t;
    }
    return ans;
}

int main(){

}