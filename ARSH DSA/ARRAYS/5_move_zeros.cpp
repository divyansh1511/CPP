#include<bits/stdc++.h>
using namespace std;

void movezeros(vector<int> v){
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            v[j] = v[i];
            j++;
        }
    }
    for (j; j < v.size(); j++)
    {
        v[j] = 0;
    }
}

int main(){
    
}