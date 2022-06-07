//https://www.geeksforgeeks.org/split-given-array-in-minimum-number-of-subarrays-such-that-rearranging-the-order-of-subarrays-sorts-the-array/
#include<bits/stdc++.h>
using namespace std;

int noofsubarr(int arr[] , int n){
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v[i].first = arr[i];
        v[i].second = i;
    }
    int c = 1;
    sort(v.begin() , v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == v[i-1].second + 1)
        {
            continue;
        }
        else
        {
            c++;
        }
    }
    return c;
}

int main(){

}