#include<bits/stdc++.h>
using namespace std;

int thirdmax(vector<int> v){
    set<int> s(v.begin() , v.end());
    auto it = s.end();
    if (s.size() < 3)
    {
        advance(it , -1);
        return *it;
    }
    else
    {
        advance(it , -3);
        return *it;
    }
}

int main(){
    vector<int> v = {3,2,1};
    cout<<thirdmax(v)<<endl;
}