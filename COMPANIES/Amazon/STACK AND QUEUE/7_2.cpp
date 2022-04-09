#include<bits/stdc++.h>
using namespace std;

void helper(string s , vector<string> &v , int a , int b){
    if (a == 0 && b == 0)
    {
        v.push_back(s);
        return;
    }
    if (b > 0)
    {
        helper(s+")" , v , a , b-1);
    }
    if (a > 0)
    {
        helper(s+"(" , v , a-1 , b+1);
    }
}

vector<string> generateparenthesis(int n){
    vector<string> v;
    helper("" , v , n , 0);
    return v;
}

int main(){

}