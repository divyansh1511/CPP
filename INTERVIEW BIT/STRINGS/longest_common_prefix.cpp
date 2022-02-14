//find the longest string S which is the prefix of ALL the strings in the array.

#include<bits/stdc++.h>
using namespace std;

string getcommonprefix(vector<string> v){
    int n = v.size();
    string s = v[0];
    int a = s.length();
    int i = 1;
    while (i<n)
    {
        int b = v[i].length();
        int d = min(a , b);
        for (int j = 0; j < d; j++)
        {
            if (s[j] != v[i][j])
            {
                s.erase(j);
                break;
            }
        }
        i++;
    }
    return s;
}

int main(){

}