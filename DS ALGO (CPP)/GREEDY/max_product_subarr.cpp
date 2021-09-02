#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int zerocount = 0;
    int negativecount = 0;
    int product = 1;
    int max_negative = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zerocount++;
            continue;
        }
        if (arr[i] < 0)
        {
            negativecount++;
            max_negative = max(max_negative , arr[i]);
        }
        product = product*arr[i];
    }
    if (zerocount == n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if (negativecount == 1 && zerocount+negativecount == n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if (negativecount&1)
    {
        product = product/max_negative;
    }
    cout<<product<<endl;
}

// 5 -1 -1 -2 3 4