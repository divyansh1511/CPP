#include<iostream>
using namespace std;

int minjumps(int arr[] , int n){
    int currreach = 0 , currmax = 0;
    int jumps = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (i + arr[i] > currmax)
        {
            currmax = i+arr[i];
        }
        if (i == currreach)
        {
            jumps++;
            currreach = currmax;
        }
        if (arr[i] == 0 && i == currmax)
        {
            return -1;
        }
    }
    return jumps;
}

int main(){
    int arr[] = {2,3,1,1,4};
    cout<<minjumps(arr , 5)<<endl;
}