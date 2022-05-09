#include<bits/stdc++.h>
using namespace std;

string encode(string str){
    string a = "";
    for (int i = 0; i < str.length();)
    {
        char b = str[i];
        int c = 1;
        i++;
        while (i < str.length() && str[i] == b)
        {
            i++;
            c++;
        }
        a += b;
        a += to_string(c);
    }
    return a;
}

int main(){

}