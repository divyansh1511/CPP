#include<bits/stdc++.h>
using namespace std;

string numberKeyPad(string s){
    string arr[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans += "0";
        }
        else
        {
            int pos =s[i] - 'A';
            ans += arr[pos];
        }
    }
    return ans;
}

int main(){

}