#include<bits/stdc++.h>
using namespace std;

int implementstr(string a , string b){
    int n = a.length() , m = b.length();
    if (b == "")
    {
        return 0;
    }
    if (m > n)
    {
        return -1;
    }
    for (int i = 0; i < n-m+1; i++)
    {
        if (a.substr(i , m) == b)
        {
            return i;
        }
    }
    return -1;
}

int main(){

}