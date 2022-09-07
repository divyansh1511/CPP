#include<bits/stdc++.h>
using namespace std;

string simplfyPath(string s){
    string tmp;
    vector<string> v;
    stringstream ss(s);
    while (getline(ss , tmp , '/'))
    {
        if (tmp == "." || tmp == "")
        {
            continue;
        }
        if (tmp == ".." && !v.empty())
        {
            v.pop_back();
        }
        else if (tmp != "..")
        {
            v.push_back(tmp);
        }
    }
    string res = "";
    for (string str : v)
    {
        res += "/" + str;
    }
    return res.empty() ? "/" : res;
}

int main(){

}