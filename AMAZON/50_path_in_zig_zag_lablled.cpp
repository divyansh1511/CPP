#include<bits/stdc++.h>
using namespace std;

vector<int> pathzigzag(int n){
    vector<int> res;
    res.push_back(n);
    int height = log2(n);
    while (height != 0)
    {
        int left = pow(2 , height-1);
        int right = pow(2 , height) - 1;
        n = left + (right-n/2);
        res.push_back(n);
        height--;
    }
    reverse(res.begin() , res.end());
    return res;
}

int main(){
    
}