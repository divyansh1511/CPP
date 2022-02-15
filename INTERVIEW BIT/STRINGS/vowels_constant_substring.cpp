#include<bits/stdc++.h>
using namespace std;

int substrings(string s){
    int n = s.length();
    if (n == 1)
    {
        return 0;
    }
    int count = 0;
    int cons = 0 , vowel = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowel++;
        }
        else
        {
            cons++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            count += cons;
            vowel--;
        }
        else
        {
            count += vowel;
            cons--;
        }
    }
    return count;
}

int main(){

}