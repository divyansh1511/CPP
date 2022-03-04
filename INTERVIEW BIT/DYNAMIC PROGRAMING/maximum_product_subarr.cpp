#include<bits/stdc++.h>
using namespace std;

int maxproduct(int arr[] , int n){
    int pro = 1;
    int currmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
        currmax = max(currmax , pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = n-1; i >= 0; i--)
    {
        pro *= arr[i];
        currmax = max(currmax , pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return currmax;
}

int main(){
    int arr[] = {2,3,-2,4};
    cout<<maxproduct(arr , 4)<<endl;
}