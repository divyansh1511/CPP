#include<iostream>
using namespace std;

void maxarrsum(int arr[] , int n){
    int currentsum = 0;
    int maxsum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        if (currentsum < 0)
        {
            currentsum = 0;
        }
        maxsum = max(maxsum , currentsum);
    }
    cout<<maxsum<<endl;
}

int main(){
    int arr[] = {-3,5,4,-6,3,6,1};
    maxarrsum(arr , 7);
}