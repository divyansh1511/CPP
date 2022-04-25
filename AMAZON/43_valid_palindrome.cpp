#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string A) {
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    int n = A.length();
    string s = "";
    for(int i=0;i<n;i++){
        if((A[i] >= 97 && A[i] <= 122) || (A[i] >= 48 && A[i] <= 57)){
            s += A[i];
        }
    }
    n = s.length();
    int i=0,j=n-1;
    while(i<=j){
        if(s[i] != s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(){

}