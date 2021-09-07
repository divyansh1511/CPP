#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minpro(int arr[] , int n){
    if (n == 1)
    {
        return arr[0];
    }
    int max_neg = INT_MIN;
    int min_pos = INT16_MAX;
    int pro = 1;
    int count_neg = 0;
    int count_zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_zero++;
            continue;
        }
        if (arr[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg , arr[i]);
        }
        if (arr[i] > 0)
        {
            min_pos = min(min_pos , arr[i]);
        }
        pro = pro*arr[i];
    }
    if (count_zero == n || (count_neg == 0 && count_zero > 0))
    {
        return 0;
    }
    if (count_neg == 0)
    {
        return min_pos;
    }
    if ((count_neg % 2 == 0) && count_neg != 0)
    {
        pro = pro/max_neg;
    }
    return pro;
}

int main(){
    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << minpro(a, n)<<endl;
}