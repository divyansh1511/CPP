#include<bits/stdc++.h>
using namespace std;

int largestrec(vector<int> arr){
    stack<int> st;
    int ans = 0;
    arr.push_back(0);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int top = arr[st.top()];
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