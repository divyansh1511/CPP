#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(unordered_map<int , list<pair<int,int>>> mp , int n , int st){
    vector<int> dis(n , INT_MAX);
    set<pair<int,int>> s;
    dis[st] = 0;
    s.insert({0 , st});
    while (!s.empty())
    {
        auto a = *(s.begin());
        int nodedis = a.first;
        int node = a.second;
        s.erase(s.begin());
        for(auto x : mp[node]){
            if (nodedis + x.second < dis[x.first])
            {
                auto a = s.find({dis[x.first] , x.first});
                if (a != s.end())
                {
                    s.erase(a);
                }
                dis[x.first] = nodedis+x.second;
                s.insert({dis[x.first] , x.first});
            }
        }
    }
    return dis;
}

int main(){

}