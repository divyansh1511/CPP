#include<bits/stdc++.h>
using namespace std;

string simplifypath(string path){
    string temp;
    vector<string> v;
    stringstream ss(path);
    while (getline(ss , temp , '/'))
    {
        if (temp == "." || temp == "")
        {
            continue;
        }
        if (temp == ".." && !v.empty())
        {
            v.pop_back();
        }
        else if (temp != "..")
        {
            v.push_back(temp);
        } 
    }
    string res;
    for(string str : v){
        res += "/"+str;
    }
    return res.empty() ? "/" : res;
}

int main(){

}