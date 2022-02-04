#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int n , int target){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = target - arr[i];
        if (mp.find(a) != mp.end())
        {
            cout<<mp[a]<<" "<<i<<endl;
            return;
        }
        mp[arr[i]] = i; 
    }
    // cout<<-1<<endl;
}

int main(){
    int arr[] = {2,7,11,13};
    solve(arr , 4 , 9);
}