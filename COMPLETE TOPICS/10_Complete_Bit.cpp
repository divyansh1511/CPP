#include<bits/stdc++.h>
using namespace std;

int noofsetbits(int n){
    int count = 0;
    while (n)
    {
        if (n&1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}

pair<int,int> twononrepeatingele(int arr[] , int n){
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a ^= arr[i];
    }
    int n1 = 0 , n2 = 0;
    int tt = a ^ ~(a-1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & tt)
        {
            n1 ^= arr[i];
        }
        else
        {
            n2 ^= arr[i];
        }
    }
    return {n1 , n2};
}

int noofflips(int a , int b){
    int c = 0;
    while (a || b)
    {
        int n1 = a&1;
        int n2 = b&1;
        if (n1 != n2)
        {
            c++;
        }
        a >>= 1;
        b >>= 1;
    }
    return c;
}

int counttotalsetbits(int n){
    n++;
    int po2 = 2;
    int cnt = (n/2);
    while (po2 <= n)
    {
        int tt = n / po2;
        cnt += (tt/2)*po2;
        cnt += (tt&1)? (n%po2) : 0;
        po2 <<= 1;
    }
    return cnt;
}

bool isPowerof2(int n){
    return n && (!(n&(n-1)));
}

int findPosition(int N) {
    if(N == 0){
        return -1;
    }
    if(!isPowerof2(N)){
        return -1;
    }
    int count = 0;
    while(N){
        int lbit = N&1;
        N >>= 1;
        count++;
        if(lbit == 1){
            break;
        }
    }
    return count;
}

int divide(int a , int b){
    int sign = (a < 0) ^ (b < 0) ? -1 : 1;
    a = abs(a);
    b = abs(b);
    int c = 0;
    while (a >= b)
    {
        a -= b;
        c++;
    }
    return c*sign;
}

int square(int a){
    a = abs(a);
    int power = 0 , res = 0;
    int t = a;
    while (t)
    {
        if (t&1)
        {
            res += (a << power);
        }
        power++;
        t = t >> 1;
    }
    return res;
}

vector<string> AllPossibleStrings(string s){
	int l = s.length();
    int n = pow(2,l);
    vector<string> ans;
    for(int num = 1; num < n; num++){
        string str{};
        for(int i = 0; i < l; i++){
            int bit = (num>>i)&1;
            if(bit == 1) str += s[i];
        }
        ans.push_back(str);
    }
    sort(ans.begin(),ans.end());
    return (ans);
}

int main(){

}