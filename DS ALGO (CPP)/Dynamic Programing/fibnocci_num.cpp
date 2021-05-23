#include<iostream>
using namespace std;

/* --------------------------------- USING RECURSION(TIME COMLEXITY : O(2^n)) ------------------------------------*/
long fibnoccirec(int n){
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return fibnoccirec(n-1)+fibnoccirec(n-2);
}

/* --------------------------------------------------------------------------------------*/

/* ------------------------------ USING MEMOMIZATION (TIME COMLEXITY : O(n))-------------------------------------*/

long fibnocciMemhelper(int n , long* arr){
    if (n == 1 || n == 2)
    {
        return 1;
    }
    
    if (arr[n-1] != -1)
    {
        return arr[n-1];
    }
    

    int a = fibnocciMemhelper(n - 1 , arr);
    int b = fibnocciMemhelper(n - 2 , arr);
    arr[n-1] = a+b;
    return a+b;
}

long fibnoccimem(int n){
    long* arr = new long[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    return fibnocciMemhelper(n , arr);
}
/*-----------------------------------------------------------------------------------------*/

/*-----------------------------------------USING TABULATION--------------------------------*/

long fibnoccitab(int n){
    long* arr = new long[n];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}

/*------------------------------------------------------------------------------------------*/
int main(){
    cout<<fibnoccitab(45)<<endl;
    cout<<fibnoccimem(45)<<endl;
    cout<<fibnoccirec(45)<<endl;
}