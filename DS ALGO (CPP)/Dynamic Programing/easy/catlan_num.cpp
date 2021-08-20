#include<iostream>
using namespace std;

int nthcatlanno(int n){
    if (n <= 1)
    {
        return 1;
    }    
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        res += nthcatlanno(i)*nthcatlanno(n-i);
    }
    return res;
}

int nthcatlannodp(int n){
    int arr[n+1];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = 0;
        for (int j = 0; j < i; j++)
        {
            arr[i] += arr[j]*arr[i-j-1];
        }
    }
    return arr[n];
}

int main(){
    int n;
    cin>>n;
    cout<<nthcatlannodp(n)<<endl;
}