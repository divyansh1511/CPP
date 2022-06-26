#include<bits/stdc++.h>
using namespace std;

//------------------------------------------BFS------------------------------------//

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int currindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currindex<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currindex)
            {
                continue;
            }
            if (edges[i][currindex] == 1 && !visited[i])
            {
                pendingvertex.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFShelper(edges , n , i ,visited);
        }
    }
}

void BFSlisthelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int a = pendingvertex.front();
        pendingvertex.pop();
        cout<<a<<endl;
        for(auto it : v[a]){
            if (!visited[it])
            {
                visited[it] = true;
                pendingvertex.push(it);
            }
        }
    }
}

void BFSlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFSlisthelper(v , n , i , visited);
        }
    }
}

//-----------------------------------DFS----------------------------//

void DFShelper(int** edges , int n , int sv , bool* &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFSlisthelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            DFSlisthelper(v , n , it , visited);
        }
    }
}

void DFSlist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSlisthelper(v , n , i , visited);
        }
    }
}

//------------------------------TO CHECK CYCLE IN UNDIRECTED GRAPH----------------------------//

//--------------BFS-----------//

bool iscyclehelper(int** edges , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        for (int i = 0; i < n; i++)
        {
            if (edges[i][node] == 1)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push({i , node});
                }
                if (i != par)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool iscycle(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscyclehelper(edges , n , i , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool iscyclelisthelper(vector<vector<int>> v , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        for(auto it : v[node]){
            if (!visited[it])
            {
                q.push({it , par});
                visited[it] = true;
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool iscyclelist(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if(iscyclelisthelper(v , n , i , visited)){
                return true;
            }
        }
    }
    return false;
}

//----------------DFS----------------//

bool iscycleDFSllhelper(vector<vector<int>> v , int n , int sv , int parent , bool* &visited){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            visited[it] = true;
            iscycleDFSllhelper(v , n , it , sv , visited);
        }
        else if (parent != it)
        {
            return true;
        }
    }
    return false;
}

bool iscycleDFSll(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscycleDFSllhelper(v , n , i , -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

//------------------------------CYCLE IN DIRECTED GRAPH-----------------------//

bool iscycledirhelper(vector<vector<int>> v , int n , int sv , bool* &visited , bool* &dfsvisited){
    visited[sv] = true;
    dfsvisited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            if (iscycledirhelper(v , n , it , visited, dfsvisited))
            {
                return true;
            }
        }
        else if (dfsvisited[it])
        {
            return true;
        }
    }
    return false;
}

bool iscycledir(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    bool* dfsvisited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dfsvisited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (iscycledirhelper(v , n , i , visited , dfsvisited))
        {
            return true;
        }
    }
    return false;
}

//------------------------------TOPOLOGICAL SORT------------------------------//

void toposorthelper(vector<vector<int>> v , int n , int sv , bool* &visited , stack<int> &st){
    visited[sv] = true;
    for(auto it : v[sv]){
        if (!visited[it])
        {
            toposorthelper(v , n , it , visited , st);
        }
    }
    st.push(sv);
}

vector<int> toposort(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposorthelper(v , n , i , visited , st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

//---------------------------------DIJKSTRA ALGO----------------------------//

vector<int> dijkstra(unordered_map<int , list<pair<int,int>>> v , int n , int st){
    vector<int> dis(n , INT_MAX);
    set<pair<int,int>> s;
    
    dis[st] = 0;
    s.insert({0 , st});
    while (!s.empty())
    {
        auto it = *(s.begin());
        int nodedis = it.first;
        int node = it.second;
        s.erase(s.begin());
        for(auto x : v[node]){
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
    int n,e;
    cin>>n>>e;

    //--------------------adjacency matrix-----------------------------//

    int** edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    //--------------------------adjacency list---------------------------//

    vector<vector<int>> v(n);
    for (int i = 0; i < e; i++)
    {
        int first , second;
        cin>>first>>second;
        v[first].push_back(second);
        v[second].push_back(first);
    }
    
    //------------------------WEIGHTED GRAPH--------------------------//

    unordered_map<int , list<pair<int,int>>> v1;
    for (int i = 0; i < e; i++)
    {
        int first , second , weight;
        cin>>first>>second>>weight;
        v1[first].push_back({second , weight});
        v1[second].push_back({first , weight});
    }

}