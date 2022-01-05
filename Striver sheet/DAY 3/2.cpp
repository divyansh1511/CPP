#include<iostream>
using namespace std;

double pow(int x , int n){
    double ans = 1.0;
    while (n)
    {
        if (n%2)
        {
            ans = n>0 ? ans*x : ans/x;
        }
        x = x*x;
        n /= 2;
    }
    return ans;
}

int main(){
    cout<<pow(2 , 10)<<endl;
}