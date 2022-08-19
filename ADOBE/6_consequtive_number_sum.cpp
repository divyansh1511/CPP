#include<bits/stdc++.h>
using namespace std;

int consequtivenumsum(int n){
    int c = 1;
    for (int k = 2; k < sqrt(2*n); k++)
    {
        if ((n - k*(k+1)/2) % k == 0)
        {
            c++;
        }
    }
    return c;
}

int main(){

}