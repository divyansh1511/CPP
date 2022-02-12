#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n){
    int i = 0 , j = n-1;
    long long int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        long long int sq = mid*mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq > n)
        {
            j = mid-1;
        }
        else
        {
            ans = mid;
            i = mid+1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

int main(){
    cout<<squareRoot(1000000)<<endl;
}