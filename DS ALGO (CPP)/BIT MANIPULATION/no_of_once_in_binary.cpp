#include<iostream>
using namespace std;

int nooftime(int n){
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<nooftime(5)<<endl;
}