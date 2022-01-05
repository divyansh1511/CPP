#include<iostream>
using namespace std;

int strstr(string s , string a){
    int x = s.length();
    int y = a.length();
    if (a == "")
    {
        return 0;
    }
    if (y > x)
    {
        return -1;
    }
    for (int i = 0; i < x-y+1; i++)
    {
        if (s.substr(i , y) == a)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    cout<<strstr("hello" , "ll")<<endl;
}