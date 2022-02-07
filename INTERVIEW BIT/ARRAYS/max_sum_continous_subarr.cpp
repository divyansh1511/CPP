#include<bits/stdc++.h>
using namespace std;

int maxsubarrsum(int arr[] , int n){
    int currsum = arr[0];
    int maxsum = arr[0];
    for (int i = 0; i < n; i++)
    {
        currsum = max(arr[i] , currsum+arr[i]);
        maxsum = max(maxsum , currsum);
    }
    return maxsum;
}

int main(){

}