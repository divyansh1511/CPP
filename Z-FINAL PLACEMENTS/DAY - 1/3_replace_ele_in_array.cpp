#include<bits/stdc++.h>
using namespace std;

vector<int> replaceelements(vector<int> v , vector<vector<int>> options){
    int arr[10000001];
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i]] = i;
    }
    for (int i = 0; i < options.size(); i++)
    {
        int a = options[i][0];
        int b = options[i][1];
        int ind = arr[a];
        v[ind] = b;
        arr[a] = -1;
        arr[b] = ind;
    }
    return v;
}

int main(){

}