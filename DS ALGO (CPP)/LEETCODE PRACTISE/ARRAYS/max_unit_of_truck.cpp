#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool static comp(vector<int> &a , vector<int> &b){
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>>& a, int truckSize) {
    sort(a.begin() , a.end() , comp);

    int i=0 , ans = 0;
    while (truckSize > 0 && i < a.size())
    {
        if (a[i][0] > 0)
        {
            ans += a[i][1];
            truckSize--;
            a[i][0]--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1,3},{2,2},{3,1}};
    cout<<maximumUnits(a , 4)<<endl;
}