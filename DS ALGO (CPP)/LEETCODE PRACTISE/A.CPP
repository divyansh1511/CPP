#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> arr , int k){
    priority_queue<int> maxheap;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxheap.push(arr[i][j]);
            if (maxheap.size() > k)
            {
                maxheap.pop();
            }
        }
    }
    return maxheap.top();
}

int main(){
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout<<solve(matrix , 8)<<endl;
}