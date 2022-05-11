#include<bits/stdc++.h>
using namespace std;

int besttime(int arr[] , int n){
    int minnum = INT_MAX;
    int maxnum = 0;
    for (int i = 0; i < n; i++)
    {
        minnum = min(minnum , arr[i]);
        maxnum = max(maxnum , arr[i] - minnum);
    }
    return minnum;
}

int main(){

}