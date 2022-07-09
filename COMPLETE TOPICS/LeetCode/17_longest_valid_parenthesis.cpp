#include<bits/stdc++.h>
using namespace std;

int longestValidParenthesis(string s){
    int n = s.length();
    stack<int> st;
    st.push(-1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int a = st.top();
        if (a != -1 && s[i] == ')' && s[a] == '(')
        {
            st.pop();
            maxi = max(maxi , i - st.top());
        }
        else
        {
            st.push(i);
        }
    }
    return maxi;
}

int main(){

}