#include<bits/stdc++.h>
using namespace std;

int Atoi(string s){
    long long int res = 0;
    int indi = 1;
    int n = s.size();
    if(n==0){
        return 0;
    }
    int i=0;
    while((s[i] == ' ') && (i<n)){
        i++;
    }
    if(i == n){
        return 0;
    }
    if((s[i] == '-' || s[i] == '+') && i<n){
        indi = (s[i++] == '-') ? -1 : 1;
    }
    while(s[i] >= '0' && s[i] <= '9' && i<n){
        res = res*10 + (s[i++] - '0');
        if(res*indi >= INT_MAX){
            return INT_MAX;
        }
        if(res*indi <= INT_MIN){
            return INT_MIN;
        }
    }
    return res*indi;
    
}

int main(){

}