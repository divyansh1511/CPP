#include<iostream>
using namespace std;

int solve(int arr[] , int n){
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 1)
        {
            maxsum = max(maxsum , sum);
        }
        else
        {
            sum++;
        }
    }
    return maxsum;
}

int main(){

}