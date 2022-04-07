#include<bits/stdc++.h>
using namespace std;

bool static cmp(int a , int b){
    string a1 = to_string(a);
    string a2 = to_string(b);
    return a1+a2 > a2+a1;
}

string largestnumber(vector<int> v){
    int n = v.size();
    sort(v.begin() , v.end() , cmp);
    string ans = "";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i];
        if (v[i] == 0)
        {
            c++;
        }
    }
    if (c == v.size())
    {
        return "0";
    }
    return ans;
}

int main(){

}