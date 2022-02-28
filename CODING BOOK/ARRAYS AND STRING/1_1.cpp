#include<bits/stdc++.h>
using namespace std;

// 1. O(n2) O(1) -------- using 2 for loops----compare each element
// 2. O(n logn) O(1) --------- using sort and continuous compare

//-----------------------------if string can have any value-----------------------//
bool isUnique(string s){
    int n = s.length();
    if(n > 128){
        return false;
    }
    bool arr[n];
    for (int i = 0; i < n; i++)
    {
        int b = s[i] - 'a';
        if(arr[b]){
            return false;
        }
    }
    return true;
}

//----------------------------if has only lower case ascii values---------------------//

bool isUniqueval(string s){
    int checker = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int val = s[i] - 'a';
        if ((checker & (1 << val)) > 0)
        {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

int main(){

}