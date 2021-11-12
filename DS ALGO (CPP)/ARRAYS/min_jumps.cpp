#include<iostream>
using namespace std;

int minjumps(int arr[] , int n){
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int maxreach = arr[0];
    int step = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , i + arr[i]);
        step--;
        if (step == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            step = maxreach - i;
        }
    }
    return -1;
}

int main(){

}