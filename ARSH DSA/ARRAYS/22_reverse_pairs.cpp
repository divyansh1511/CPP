#include<bits/stdc++.h>
using namespace std;

void mergehelper(vector<int> arr , int start , int mid , int end , int &count){
    int l = start , r = mid+1;
    while (l <= mid && r <= end)
    {
        if (arr[l] > 2*arr[r])
        {
            count += (mid - l + 1);
            r++;
        }
        else
        {
            l++;
        }
    }
    sort(arr.begin()+start , arr.begin()+end+1);
}

void merge(vector<int> arr , int start , int end , int &count){
    if (start > end)
    {
        return;
    }
    int mid = (start+end)/2;
    merge(arr , start , mid , count);
    merge(arr , mid+1 , end , count);
    mergehelper(arr , start , mid , end , count);
}

int reversepairs(vector<int> arr){
    if (!arr.size())
    {
        return 0;
    }
    int count = 0;
    int n = arr.size();
    merge(arr , 0 , n-1 , count);
    return count;
}

int main(){

}