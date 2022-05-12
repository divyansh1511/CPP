#include<bits/stdc++.h>
using namespace std;

int subarrsum(int arr[] , int n , int k){
    int sum = 0 , count = 0;
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

}