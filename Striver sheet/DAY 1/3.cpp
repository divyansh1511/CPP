//------------------------NEXT PERMUTATION--------------------------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void nextpremu(vector<int> &v){
    int n = v.size();
    int k,l;
    for ( k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for (l = n-1; l > k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

int main(){
    vector<int> ans = {1,2,3};
    nextpremu(ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}