#include<bits/stdc++.h>
using namespace std;

void max_min(int arr[] , int n){
    int mini = INT_MAX , maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(arr[i] , mini);
        maxi = max(arr[i] , maxi);
    }
    cout<<mini<<" "<<maxi<<endl;
}

int main(){
    
}