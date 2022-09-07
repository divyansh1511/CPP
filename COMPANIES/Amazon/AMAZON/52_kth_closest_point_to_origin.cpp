#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kthclosestorigin(vector<vector<int>> &v , int k){
    priority_queue<pair<int , pair<int , int>>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push({v[i][0]*v[i][0] + v[i][1]*v[i][1] , {v[i][0] , v[i][1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while (!pq.empty())
    {
        vector<int> a;
        a.push_back(pq.top().second.first);
        a.push_back(pq.top().second.second);
        pq.pop();
        ans.push_back(a);
    }
    return ans;
}

int main(){

}