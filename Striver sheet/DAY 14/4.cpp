#include<bits/stdc++.h>
using namespace std;

int getmaxarea(vector<int> arr , int n){
    stack<int> st;
    int i = 0 , ans = 0;
    arr.push_back(0);
    while (i < n)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int t = st.top();
            int h = arr[t];
            st.pop();
            if (st.empty())
            {
                ans = max(ans , h*i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans , h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout<<getmaxarea(arr , 6)<<endl;
}