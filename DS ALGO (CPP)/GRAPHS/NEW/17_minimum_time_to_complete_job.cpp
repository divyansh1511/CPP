#include<bits/stdc++.h>
using namespace std;

void mintime(vector<vector<int>> edges , int n , int s1 , int s2){
    vector<vector<int>> v(n);
    vector<int> indegree(n);
    for (int i = 0; i < edges.size(); i++)
    {
        v[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    vector<int> job(n);
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            job[i] = 1;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
 
        for (int adj : v[cur]) {
            indegree[adj]--;
            if (indegree[adj] == 0) {
                job[adj] = job[cur] + 1;
                q.push(adj);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << job[i] << " ";
}

int main(){

}