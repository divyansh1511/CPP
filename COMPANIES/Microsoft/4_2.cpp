#include<bits/stdc++.h>
using namespace std;

string INTtoroman(int A){
    string s[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};

    string ans = "";
    for (int i = 0; A != 0; i++)
    {
        while (A >= val[i])
        {
            A -= val[i];
            ans += s[i];
        }
    }
    return ans;
}

int main(){

}