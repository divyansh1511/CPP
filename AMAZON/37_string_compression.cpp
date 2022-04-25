#include<bits/stdc++.h>
using namespace std;

int compression(vector<char> &v){
    int n = v.size();
    string res = "";
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i+1 < n && v[i] == v[i+1])
        {
            i++;
            count++;
        }
        if (count > 1)
        {
            res += v[i];
            res += to_string(count);
        }
        else
        {
            res += v[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = res[i];
    }
    return res.size();
}

int main(){

}