#include<bits/stdc++.h>
using namespace std;

int largestrec(vector<int> &v){
    stack<int> st;
    int ans = 0;
    v.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] > v[i])
        {
            int top = v[st.top()];
            st.pop();
            int ran = st.empty() ? -1 : st.top();
            ans = max(ans , top*(i-ran-1));
        }
        st.push(i);
    }
    return ans;
}

int main(){

}