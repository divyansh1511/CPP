#include<bits/stdc++.h>
using namespace std;

long buildPalindrome(int n){
    string s = to_string(n);
    reverse(s.begin() , s.end());
    return stol(to_string(n) + s);
}

int largestPalindrome(int n){
    if(n == 1){
        return 9;
    }
    int upper = pow(10 , n) - 1;
    int lower = pow(10 , n-1);
    for (int i = upper; i >= lower; i--)
    {
        long cand = buildPalindrome(i);
        for (int j = upper; j*j >= cand; j--)
        {
            if (cand%j == 0)
            {
                return cand%1337;
            }
        }
    }
    return -1;
}

int main(){

}