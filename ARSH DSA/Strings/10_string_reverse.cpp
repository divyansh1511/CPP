#include<bits/stdc++.h>
using namespace std;

string reverseword(string s){
    if (s.length() == 0)
    {
        return s;
    }
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string a = "";
        while (s[i] != ' ' && i < s.length())
        {
            a += s[i];
            i++;
        }
        if (a.length() != 0)
        {
            st.push(a);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top()+" ";
        st.pop();
    }
    while (ans[0] == ' ' || ans[ans.length() - 1] == ' ')
    {
        if (ans[0] == ' ')
        {
            ans = ans.substr(1 , ans.length());
        }
        else
        {
            ans = ans.substr(0 , ans.length()-1);
        }
    }
    return ans;
}

int main(){

}