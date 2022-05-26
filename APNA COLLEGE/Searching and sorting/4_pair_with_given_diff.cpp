#include<bits/stdc++.h>
using namespace std;

bool pair(int arr[] , int n , int diff){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]+diff) != mp.end())
        {
            cout<<arr[i]<<" "<<mp[arr[i]+diff]<<endl;
            return true;
        }
    }
    return false;
}

int main(){

}