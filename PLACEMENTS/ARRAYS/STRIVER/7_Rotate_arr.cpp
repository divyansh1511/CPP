#include<bits/stdc++.h>
using namespace std;

void rotatearr(vector<vector<int>> &v){
    int n = v.size();
    int a = 0 , b = n-1;
    while (a < b)
    {
        for (int i = 0; i < (b-a); i++)
        {
            swap(v[a][a+i] , v[a+i][b]);
            swap(v[a][a+i] , v[b][b-i]);
            swap(v[a][a+i] , v[b-i][a]);
        }
        a++;
        b--;
    }
}

int main(){

}