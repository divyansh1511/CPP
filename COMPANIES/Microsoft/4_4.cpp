#include<bits/stdc++.h>
using namespace std;

string multiply(string a , string b){
    int n = a.length();
    int m = b.length();
    string res((n+m) , '0');
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int num = (a[i] - '0')*(b[j] - '0') - res[i+j+1] - '0';
            res[i+j+1] = num%10 + '0';
            res[i+j] += num/10;
        }
    }
    for(int i=0;i<res.length();i++){
        if(res[i] != '0'){
            return res.substr(i);
        }
    }
    return "0";
}

int main(){

}