#include<bits/stdc++.h>
using namespace std;

int findlength(string s){
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            cnt++;
        }
        else
        {
            return cnt;
        }
    }
    return cnt;
}

int main(){

}