#include<bits/stdc++.h>
using namespace std;

static bool cmp(string a , string b){
    return a+b > b+a;
}

string largestnumber(vector<string> v){
    sort(v.begin() , v.end() , cmp);
    string ans = "";
    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i];
    }
    return ans;
}

int main(){

}