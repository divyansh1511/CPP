#include<bits/stdc++.h>
using namespace std;

int stockBuyandSell(int arr[] , int n){
    int maxi = 0 , mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini , arr[i]);
        maxi = max(maxi , arr[i]-mini);
    }
    return maxi;
}

int main(){

}