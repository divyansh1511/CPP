#include <bits/stdc++.h>
using namespace std;

class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }
	public:
	vector<int> topoSort(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(vis[i] == 0) {
	            findTopoSort(i, vis, st, adj); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo; 
	    
	}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        
        // cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends