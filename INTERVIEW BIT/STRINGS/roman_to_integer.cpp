#include<bits/stdc++.h>
using namespace std;

int romanToInt(string A) {
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int n = A.length();
    int sum = mp[A[n-1]];
    for(int i=n-2;i>=0;i--){
        if(mp[A[i]] < mp[A[i+1]]){
            sum -= mp[A[i]];
        }
        else{
            sum += mp[A[i]];
        }
    }
    return sum;
}

int main(){

}