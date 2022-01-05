#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a , pair<int , int> b){
    return a.second < b.second;
}

int solve(int start[] , int end[] , int n){
    vector<pair<int , int>> v;
    for(int i=0;i<n;i++){
        v.push_back({start[i] , end[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int last_time = v[0].second;
    int count = 1;
    for(int i=1;i<n;i++){
        if(v[i].first > last_time){
            count++;
            last_time = v[i].second;
        }
    }
    return count;
}

int main(){
    int s[] = {10,12,20}; 
    
    // Finish time 
    int f[] = {20 , 25 , 30}; 
    
    // Number of meetings. 
    int n = sizeof(s) / sizeof(s[0]); 

    // Function call 
    cout<<solve(s, f, n); 
}