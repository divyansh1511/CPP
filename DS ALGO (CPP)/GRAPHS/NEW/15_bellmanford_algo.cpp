#include<bits/stdc++.h>
using namespace std;

int bellmonford(int n , int v , int src , int des , vector<vector<int>> destiny){
    vector<int> dis(n+1 , INT_MAX);
    dis[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int a = destiny[j][0];
            int b = destiny[j][1];
            int wt = destiny[j][2];

            if (dis[a] != INT_MAX && ((dis[a]+wt) < dis[b]))
            {
                dis[b] = dis[a]+wt;
            }
        }
    }
    return dis[des];
}

int main(){

}