#include<bits/stdc++.h>
using namespace std;

vector<int> mergekarr(vector<vector<int>> v , int k){
    vector<int> res;
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push({v[i][0] , {i , 0}});
    }
    while (!pq.empty())
    {
        pair<int , pair<int , int>> curr = pq.top();
        pq.pop();
        
        int a = curr.second.first;
        int b = curr.second.second;

        res.push_back(curr.first);

        if (b+1 < v[a].size())
        {
            pq.push({v[a][b+1] , {a , b+1}});
        }
    }
    return res;
}

int main(){

}