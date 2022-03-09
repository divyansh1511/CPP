#include<bits/stdc++.h>
#include<C:\Users\lenovo\Desktop\CPP\INTERVIEW BIT\DYNAMIC PROGRAMING\longest_common_subsequence.cpp>
using namespace std;

int longestPalindrome(string s , int n){
    string b = s;
    reverse(b.begin() , b.end());
    return LCSdp(s , b , n , n);
}

int main(){
    
}