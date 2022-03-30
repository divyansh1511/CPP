#include<bits/stdc++.h>
using namespace std;

vector<int> plusone(vector<int> &A){
    if(A.size() == 1 && A[0] < 9){
        A[0] = A[0]+1;
        return A;
    }
    int k = 0;
    while(A[k] == 0){
        if(A[k] != 0) break;
        auto it = A.begin()+k;
        A.erase(it);
    }
    int n = A.size();
    reverse(A.begin() , A.end());
    int a = A[0] + 1;
    if(a < 10){
        A[0] = a;
        reverse(A.begin() , A.end());
        return A;
    }
    else{
        int carry = a/10;
        A[0] = a%10;
        int i = 1;
        while(carry != 0 && i<n){
            int b = A[i]+carry;
            A[i] = b%10;
            carry = b/10;
            i++;
        }
        if(carry != 0){
            A.push_back(carry);
        }
        reverse(A.begin() , A.end());
        return A;
    }
}

int main(){

}