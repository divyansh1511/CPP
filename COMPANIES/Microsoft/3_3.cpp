#include<bits/stdc++.h>
using namespace std;

int sqrt(int A){
    long long int i = 0 , j = A;
    long long int mid = i+(j-i)/2;
    long long int ans = -1;
    while(i <= j){
        long long int sq = mid*mid;
        if(sq == A){
            return mid;
        }
        if(sq > A){
            j = mid-1;
        }
        else{
            ans = mid;
            i = mid+1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

int main(){
    
}