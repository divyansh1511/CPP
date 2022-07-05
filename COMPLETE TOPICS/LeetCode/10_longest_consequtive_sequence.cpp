#include<bits/stdc++.h>
using namespace std;

int longest_consequtive(int arr[] , int n){
    if (n == 0)
    {
        return 0;
    }
    sort(arr , arr+n);
    int ans = 0;
    int sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            continue;
        }
        if (arr[i] != arr[i-1]+1)
        {
            ans = max(ans , sum);
            sum = 1;
        }
        else
        {
            sum++;
        }
    }
    return max(ans , sum);
}

int main(){

}