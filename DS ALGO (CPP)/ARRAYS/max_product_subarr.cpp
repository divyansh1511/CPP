#include<iostream>
using namespace std;

int maxpro(int arr[] , int n){
    int minval = arr[0];
    int maxval = arr[0];

    int maxproduct = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(minval , maxval);
        }
        maxval = max(arr[i] , maxval*arr[i]);
        minval = min(arr[i] , minval*arr[i]);

        maxproduct = max(maxproduct , maxval);
    }
    return maxproduct;
}

int main(){

}