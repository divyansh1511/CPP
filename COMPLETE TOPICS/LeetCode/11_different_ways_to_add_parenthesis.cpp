#include<bits/stdc++.h>
using namespace std;

vector<int> diffWaystoAdd(string s){
    vector<int> res;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] < '0')
        {
            vector<int> v1 = diffWaystoAdd(s.substr(0 , i));
            vector<int> v2 = diffWaystoAdd(s.substr(i+1));
            for(auto i1 : v1){
                for(auto i2 : v2){
                    switch (s[i])
                    {
                        case '+':
                            res.push_back(i1+i2);
                            break;
                        case '-':
                            res.push_back(i1-i2);
                            break;
                        case '*':
                            res.push_back(i1*i2);
                    }
                }
            }
        }
    }
    if (res.empty())
    {
        res.push_back(stoi(s));
    }
    return res;
}

int main(){

}