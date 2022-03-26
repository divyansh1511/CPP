#include<bits/stdc++.h>
using namespace std;

int mod = 1000003;

int fact(int a){
    if (a == 0)
    {
        return 1;
    }
    return (a*fact(a-1))%mod;
}

int sorted_permu_rank(string a){
    int ans = 0;
    for (int i = 0; i < a.length()-1; i++)
    {
        int c = 0;
        for (int j = i+1; j < a.length(); j++)
        {
            if (a[j] < a[i])
            {
                c++;
            }
        }
        ans += (c*fact(a.length()-i-1)) % mod;
    }
    return (ans+1) % mod;
}

int main(){

}