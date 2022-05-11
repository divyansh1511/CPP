#include<bits/stdc++.h>
using namespace std;

int pairsum(int arr[] , int n , int key){
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > arr[i+1])
        {
            break;
        }
    }
    int l = (i+1)%n;
    int r = i;
    while (l != r)
    {
        if (arr[l] + arr[r] == key)
        {
            return true;
        }
        else if (arr[l] + arr[r] < key)
        {
            l = (l+1)%n;
        }
        else
        {
            r = (r+n-1)%n;
        }
    }
    return false;
}

int main(){

}