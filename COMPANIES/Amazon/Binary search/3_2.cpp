#include<bits/stdc++.h>
using namespace std;

int squareroot(int n){
    int i = 0 , j = n;
    int mid = i+(j-i)/2;
    int ans = -1;
    while (i <= j)
    {
        int sq = mid*mid;
        if (sq == n)
        {
            return mid;
        }
        else if (sq < n)
        {
            i = mid+1;
            ans = mid;
        }
        else
        {
            j = mid-1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

int main(){

}