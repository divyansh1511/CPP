#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arrival[] , int depature[] , int n){
    multiset<pair<int , char>> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(make_pair(arrival[i] , 'a'));
        st.insert(make_pair(depature[i] , 'd'));
    }
    int result = 0;
    int plat_needed = 0;
    for (auto it : st)
    {
        if (it.second == 'a')
        {
            plat_needed++;
        }
        else
        {
            plat_needed--;
        }
        if (plat_needed > result)
        {
            result = plat_needed;
        }
    }
    return result;
}

int main(){
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<solve(arr , dep , n)<<endl;
}