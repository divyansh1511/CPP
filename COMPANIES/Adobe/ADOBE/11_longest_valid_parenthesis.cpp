#include<bits/stdc++.h>
using namespace std;

int longestvalidparenthesis(string s){
    stack<int> st;
    st.push(-1);
    int maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int a = st.top();
        if (a != -1 && s[i] == ')' && s[a] == '(')
        {
            st.pop();
            maxi = max(maxi , i-a);
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