#include<bits/stdc++.h>
using namespace std;

int jumpGame(int arr[] , int n){
    int last = n-1;
    for (int i = n-2; i >= 0; i--)
    {
        if (i+arr[i] >= last)
        {
            last = i;
        }
    }
    return last == 0;
}

int main(){

}