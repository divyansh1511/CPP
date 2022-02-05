//sieve of eratosthenes algorithm -- time complexity -- O(N log(log N))
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> v(n+1 , true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == true)
        {
            for (int j = i*i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (v[i] == true)
        {
            count++;
        }
    }
    cout<<count<<endl;
}