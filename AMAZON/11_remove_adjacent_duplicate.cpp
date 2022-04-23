#include<bits/stdc++.h>
using namespace std;

string removeduplicate(string s){
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if (s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){

}