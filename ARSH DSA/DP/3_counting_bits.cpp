#include<bits/stdc++.h>
using namespace std;

vector<int> countingbits(int n){
    vector<int> res(n , 0);
    for (int i = 1; i <= n; i++)
    {
        res[i] = res[i&(i-1)] + 1;
    }
    return res;
}

int main(){

}