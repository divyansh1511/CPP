#include<bits/stdc++.h>
using namespace std;

string integertoroman(int num){
    string str[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
    string res = "";
    for (int i = 0; num != 0; i++)
    {
        while (num >= val[i])
        {
            res += str[i];
            num -= val[i];
        }
    }
    return res;
}

int main(){

}