#include<bits/stdc++.h>
using namespace std;

int countsetbits(int n){
    if (n == 0)
    {
        return 0;
    }
    int t = n+1;
    long long count = 0;
    for (int x = 2; x <= 2*(t-1); x*=2)
    {
        count += (t/x)*x/2;
        if ((t%x) > x/2)
        {
            count += (t%x) - x/2;
        }
    }
    return count%100000007;
}

int main(){
    cout<<countsetbits(3)<<endl;
}