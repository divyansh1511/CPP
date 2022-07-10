#include<bits/stdc++.h>
using namespace std;

class Solution {
    int BASE = 1000000;
public:
    int helper(string a , string b){
        if(a == "" || b == ""){
            return -1;
        }
        int n = a.size();
        int m = b.size();
        int power = 1;
        for(int i=0;i<m;i++){
            power = (power*31)%BASE;
        }
        int bcode = 0;
        for(int i=0;i<m;i++){
            bcode = (bcode*31 + b[i])%BASE;
        }
        int hashcode = 0;
        for(int i=0;i<n;i++){
            hashcode = (hashcode*31 + a[i])%BASE;
            if(i < m-1){
                continue;
            }
            if(i >= m){
                hashcode = (hashcode - a[i-m]*power)%BASE;
            }
            if(hashcode < 0){
                hashcode += BASE;
            }
            if(hashcode == bcode){
                if(a.substr(i-m+1,m) == b){
                    return i-m+1;
                }
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b){
            return 1;
        }
        int count = 1;
        string src = a;
        while(src.size() < b.size()){
            count++;
            src += a;
        }
        if(src == b){
            return count;
        }
        if(helper(src , b) != -1){
            return count;
        }
        if(helper(src+a , b) != -1){
            return count+1;
        }
        return -1;
    }
};

int main(){

}