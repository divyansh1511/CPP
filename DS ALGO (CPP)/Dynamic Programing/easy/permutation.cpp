#include<iostream>
#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;


long gettimemicro(){
    struct timeval start;
    gettimeofday(&start , NULL);
    return start.tv_sec*1000000+start.tv_usec;
}

int permutation(int n , int k){

    if(k == 0){
        return 1;
    }
    
    int arr[k];
    memset(arr , 0 , sizeof(arr));

    arr[0] = n;
    int a = n-1;
    int i = 1;
    while (a != (n-k) && i<k)
    {
        arr[i] = a*arr[i-1];
        a--;
        i++;
    }
    return arr[k-1];
}

int solution(int n , int k){
    int fact[n+1];
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        fact[i] = i*fact[i-1];
    }
    return fact[n]/fact[n-k];
}

int main(){
    long start = gettimemicro();
    cout<<permutation(10 , 5)<<endl;
    long end = gettimemicro();
    cout<<end-start<<endl;

    // long start = gettimemicro();
    // cout<<solution(10 , 5)<<endl;
    // long end = gettimemicro();
    // cout<<end-start<<endl;
}