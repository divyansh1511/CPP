#include<bits/stdc++.h>
using namespace std;

int trailzeros(int n){
    int ans = 0;
    for (int i = 5; (n/i) > 0 ; i *= 5)
    {
        ans += (n/i);
    }
    return ans;
}

int main(){
    cout<<trailzeros(256)<<endl;
}