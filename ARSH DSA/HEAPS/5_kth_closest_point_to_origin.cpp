#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kthclosest(vector<vector<int>> v , int k){
    priority_queue<pair<int , pair<int , int>>> pq;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        pq.push({v[i][0] * v[i][0] + v[i][1]*v[i][1] , {v[i][0] , v[i][1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while (!pq.empty())
    {
        vector<int> v;
        v.push_back(pq.top().second.first);
        v.push_back(pq.top().second.second);
        ans.push_back(v);
        pq.pop();
    }
    return ans;
}

int main(){
    
}