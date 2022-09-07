#include<bits/stdc++.h>
using namespace std;

int FindHindex(vector<int> v){
    int n = v.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> ans(n+1 , 0);
    for (int i = 0; i <= n; i++)
    {
        if(v[i] >= n){
            ans[n]++;
        }
        else
        {
            ans[v[i]]++;
        }
    }
    int papers = 0;
    int i = n;
    for (i = n; i >= 0; i--)
    {
        papers += ans[i];
        if (papers >= i)
        {
            break;
        }
        
    }
    return i;
}

int main(){

}