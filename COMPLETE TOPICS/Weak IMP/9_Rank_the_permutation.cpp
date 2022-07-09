#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long fact[16];
    long long mod = 1000003;

    void find_factorial()
    {
       fact[0] = 1;
       fact[1] = 1;
       for(int i = 2; i <= 15; i++)
       {
           fact[i] = i * fact[i - 1];
       }
    }

    int rank(string S){
        // code here
        int n = S.length();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[S[i]]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                return 0;
            }
        }
        find_factorial();
        
        int x = n-1;
        long long ans = 0;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=i+1;j<n;j++){
                if(S[j] < S[i]){
                    count++;
                }
            }
            long long factorial = fact[x];
            x--;
            
            ans = (ans%mod + (count%mod * factorial%mod))%mod;
        }
        return ans+1;
    }
};

int main(){

}