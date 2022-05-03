#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(vector<int> &v){
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }
    v.assign(s.begin() , s.end());
}

int main(){

}