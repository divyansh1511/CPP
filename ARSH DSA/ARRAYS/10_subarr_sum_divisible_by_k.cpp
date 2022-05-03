#include<bits/stdc++.h>
using namespace std;

int subarrsum(int arr[] , int n , int k){
    int count = 0;
    int sum = 0;
    vector<int> v(k);
    v[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += (arr[i]%k + k)%k;
        count += v[sum%k]++;
    }
    return count;
}

int main(){
    int arr[] = {4,5,0,-2,-3,1};
    cout<<subarrsum(arr , 6 , 5)<<endl;
}