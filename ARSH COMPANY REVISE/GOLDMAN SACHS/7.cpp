#include<bits/stdc++.h>
using namespace std;

int lastposition(int n , int m , int k){
    if (m <= n-k+1)
    {
        return m+k-1;
    }
    m = m - (n-k+1);
    return (m%n == 0) ? n : (m%n);
}

int main(){

}