//-----------------KADANCES ALGO-----------------//
#include<iostream>
using namespace std;

int kadane(int arr[] , int n){
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxi = max(maxi , sum);
    }
    return maxi;
}

int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadane(arr , 9)<<endl;
}