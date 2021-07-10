#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int height(vector<int> heights){
    int count = 0;

    vector<int> v1;
    for (int i = 0; i < heights.size(); i++)
    {
        v1.push_back(heights[i]);
    }
    
    sort(v1.begin() , v1.end());

    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != v1[i])
        {
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> heights;
    int n,a;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>a;
        heights.push_back(a);
    }
    
    cout<<height(heights)<<endl;
}