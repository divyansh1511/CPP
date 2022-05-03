#include<bits/stdc++.h>
using namespace std;

int majorityele(int arr[] , int n){
    unordered_map<int , int> mp;
    for (int i = 0; i < n; i++)
    {
        if (++mp[arr[i]] > n/2)
        {
            return arr[i];
        }
    }
    return 0;
}

int main(){

}