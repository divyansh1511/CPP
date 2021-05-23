#include<iostream>
#include<climits>
using namespace std;

/*------------------------------------- RECURSION -------------------------------*/
int minstepsrec(int n){
    if (n == 1)
    {
        return 0;
    }
    int option1 = 1+minstepsrec(n-1);
    int option2 = INT_MAX;
    int option3 = INT_MAX;

    if (n%2 == 0)
    {
        option2 = 1+minstepsrec(n/2);
    }
    if (n%3 == 0)
    {
        option3 = 1+minstepsrec(n/3);
    }
    return min(min(option1 , option2) , option3);
}

/*---------------------------------------------------------------------------------*/

/*----------------------------------DP---------------------------------------------*/

int minstepdphelper(int n , int* arr){
    if (n == 1)
    {
        return 0;
    }
    if (arr[n-1] != -1)
    {
        return arr[n-1];
    }
    
    int option1 = 1+minstepdphelper(n-1,arr);
    int option2 = INT_MAX;
    int option3 = INT_MAX;

    if (n%2 == 0)
    {
        option2 = 1+minstepdphelper(n/2,arr);
    }
    if (n%3 == 0)
    {
        option3 = 1+minstepdphelper(n/3,arr);
    }
    int output = min(min(option1 , option2) , option3);
    arr[n-1] = output;
    return output;
}

int minstepdp(int n){
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    return minstepdphelper(n , arr);
}
/*------------------------------------------------------------------------------*/
int main(){
    cout<<minstepdp(722)<<endl;
    cout<<minstepsrec(722)<<endl;
}