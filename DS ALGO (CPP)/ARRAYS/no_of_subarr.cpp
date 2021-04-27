#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];                //THE RED LINE(ERROR LINE) UNDER n IS because it asks us to define a const value to it

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int noofsubarr;           // SUBARRAY is continous part of the array
    noofsubarr = n*(n+1)/2;
    cout<<noofsubarr<<endl;


    int noofsubsequence;      // SUBSEQUENCE is discontinous part of the arr
    noofsubsequence = pow(2,n);
    cout<<noofsubsequence<<endl;
}