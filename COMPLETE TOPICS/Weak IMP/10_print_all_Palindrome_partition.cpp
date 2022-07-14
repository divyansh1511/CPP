#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str){
    int len = str.length();
    len--;
    for (int i = 0; i <= len/2; i++)
    {
        if (str[i] != str[len-1])
        {
            return false;
        }
    }
    return true;
}

void addstring(string s , vector<vector<string>> &ans , vector<string> &temp ,int index){
    int len = s.length();
    string str;
    vector<string> curr = temp;
    if (index == 0)
    {
        temp.clear();
    }
    for (int i = index; i < len; i++)
    {
        str += s[i];
        if (checkPalindrome(str))
        {
            temp.push_back(str);
            if (i+1 < len)
            {
                addstring(s , ans , temp , index+1);
            }
            else
            {
                ans.push_back(temp);
            }
            temp = curr;
        }
    }
}

void partition(string s , vector<vector<string>> &ans){
    vector<string> temp;
    addstring(s , ans , temp , 0);
}

int main(){

}