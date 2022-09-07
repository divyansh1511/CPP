#include<bits/stdc++.h>
using namespace std;

int countdigitone(int n){
    int ans = 0;
    if(n <= 0){
        return 0;
    }
    if(n <= 9){
        return 1;
    }

    unordered_map<int,int> mp;
    mp[9] = 1;
    for (int i = 9; i < (INT_MAX-9)/10; i = i*10+9)
    {
        mp[i*10+9] = mp[i]*10 + i+1;
    }

    int tmp = n , d = 1;
    while (tmp/10)
    {
        tmp /= 10;
        d *= 10;
    }
    
    ans += (n/d) * mp[d-1];
    ans += (n/d > 1) ? d : 0;
    ans += (n/d == 1) ? n%d + 1 : 0;
    ans += countdigitone(n%d);
    return ans;
}

int main(){

}