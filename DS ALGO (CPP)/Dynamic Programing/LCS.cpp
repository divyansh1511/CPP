// substring code
#include<iostream>
using namespace std;

string LCSrecursion(string s1 , string s2){
    if (s1.length() == 0 || s2.length() == 0)
    {
        return "";
    }
    
    if (s1[0] == s2[0])
    {
        return s1[0]+LCSrecursion(s1.substr(1),s2.substr(1));
    }
    else
    {
        string option1 = LCSrecursion(s1 , s2.substr(1));
        string option2 = LCSrecursion(s1.substr(1) , s2);
        if (option1.length() > option2.length())
        {
            return option1;
        }
        else
        {
            return option2;
        }
    }
}

string LCSdp(string s1 ,string s2){
    int m = s1.length();
    int n = s2.length();
    string arr[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
        arr[i][0] = "";
    }
    for (int i = 0; i < n+1; i++)
    {
        arr[0][i] = "";
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s1[m-i] == s2[n-j])
            {
                arr[i][j] = s1[m-i]+arr[i-1][j-1];
            }
            else
            {
                string option1 = arr[i-1][j];
                string option2 = arr[i][j-1];
                arr[i][j] = (option1.length() > option2.length())?option1:option2;
            }
        }
    }
    return arr[m][n];
}

int main(){
    cout<<LCSrecursion("abcdefghi","bghicfhi")<<endl;
    cout<<LCSdp("abcdefghi","bghicfhi")<<endl;
}