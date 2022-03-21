#include<bits/stdc++.h>
using namespace std;

int maxpro(int arr[] , int n){
    int p1 = arr[0] , p2 = arr[0] , ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i] , p1*arr[i] , p2*arr[i]});
        p2 = min({arr[i] , p1*arr[i] , p2*arr[i]});
        p1 = temp;

        ans = max(ans , p1);
    }
    return ans;
}

int main(){
    
}