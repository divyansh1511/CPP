#include<bits/stdc++.h>
using namespace std;

vector<int> nextgreaterele(int arr[] ,int n){
    stack<pair<int,int>> st;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int curr = mp[arr[n-1]];
    st.push({arr[n-1] , curr});
    vector<int> ans(n);
    ans[n-1] = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        curr = mp[arr[i]];
        while (!st.empty() && curr >= st.top().second)
        {
            st.pop();
        }
        ans[i] = (st.size() == 0) ? -1 : st.top().first;
        st.push({arr[i] , mp[arr[i]]});
    }
    return ans;
}

int main(){

}