#include<bits/stdc++.h>
using namespace std;

int minadd(string s){
    int n = s.length() , i = 0 , j = n-1 , k = n;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            while (s[j] != s[0])
            {
                j--;
            }
            k = j;
            i = 0;
        }
    }
    if (k == n)
    {
        return 0;
    }
    return n-k+1;
}

int main(){

}