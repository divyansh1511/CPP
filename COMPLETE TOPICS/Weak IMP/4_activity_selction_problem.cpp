#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &v1 , vector<int> &v2){
    if (v1[1] == v2[1])
    {
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}

int minNumberrooms(int start[] , int end[] , int n){
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i] , end[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int j = 0;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[j][1] < v[i][0])
        {
            c++;
            j = i;
        }
    }
    return c;
}

int main(){

}