#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n-1; i >= 0; i++)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
    digits[0] = 1;
    digits.push_back(0);
}

int main(){
    vector<int> digits = {1,2,3,4};
    plusOne(digits);
    for (int i = 0; i < digits.size(); i++)
    {
        cout<<digits[i]<<" ";
    }
    
}