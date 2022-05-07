#include<bits/stdc++.h>
using namespace std;

int maxpro(vector<int> v){
    int pro = 1;
    int currmax = 1;
    for (int i = 0; i < v.size(); i++)
    {
        pro *= v[i];
        currmax = max(currmax , pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = v.size()-1; i >= 0; i--)
    {
        pro *= v[i];
        currmax = max(currmax , pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return currmax;
}

int main(){

}