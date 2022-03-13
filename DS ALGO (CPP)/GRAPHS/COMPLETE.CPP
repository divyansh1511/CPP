#include<bits/stdc++.h>
using namespace std;

//-------------------------------------BFS-----------------------------------------

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int currindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currindex<<" ";
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
            BFShelper(edges , n , i , visited);
        }
    }
    delete[] visited;
}

//--------------------------------------DFS-------------------------------------------

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
    delete[] visited;
}

//-------------------------HAS PATH BETWEEN TWO NODES ------- DFS----------------------------

bool haspathhelper(int** edges , int n , int v1 , int v2 , bool* &visited){
    visited[v1] = true;
    if (edges[v1][v2] == 1)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == v1)
        {
            continue;
        }
        if (edges[i][v1] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            if (haspathhelper(edges , n , i , v2 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool haspath(int** edges , int n , int v1, int v2){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return haspathhelper(edges , n , v1 , v2 , visited);
}

//-----------------------------------------IS CONNECTED-------------------------------------

void isconnectedhelper(int** edges , int n , int sv , bool* &visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            isconnectedhelper(edges , n , i , visited);
        }
    }
}

bool isconnected(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    isconnectedhelper(edges , n , 0 , visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

//---------------------------------PRINT CONNECTED COMPONENTS OF GRAPH---------------------//

void printconnectedhelper(int** edges , int n , int sv , bool* &visited){
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
            printconnectedhelper(edges , n , i , visited);
        }
    }
}

void printconnected(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printconnectedhelper(edges , n , i , visited);
            cout<<endl;
        }
    }
    delete[] visited;
}

//-----------------------------------IS CYCLIC in NON DIRECTED GRAPH ----------------------------------------

bool iscyclehelper(int** edges , int n , int sv , int parent , bool* visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[i][sv] == 1)
        {
            if (!visited[i])
            {
                if (iscyclehelper(edges , n , i ,  sv, visited))
                {
                    return true;
                }  
            }
            else if(i != parent)
            {
                return true;
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
            if (iscyclehelper(edges , n , i , -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------is CYCLE indirected graph-----------------------------//

bool iscycle1helper(int sv , int** edges , bool* visited , bool* stack , int n){
    stack[sv] = true;
    if (!visited[sv])
    {
        visited[sv] = true;
        for (int i = 0; i < n; i++)
        {
            if (edges[i][sv] == 1)
            {
                if (!visited[i] && iscycle1helper(i , edges , visited , stack , n))
                {
                    return true;
                }
                if (stack[i])
                {
                    return true;
                }
            }
        }
    }
    stack[sv] = false;
    return false;
}

bool icycle1(int** egdes , int n){
    bool cycle = false;
    bool* visited = new bool[n];
    bool* stack = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        stack[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && iscycle1helper(i , egdes , visited , stack , n))
        {
            cycle = true;
        }
    }
    return cycle;
}

//--------------------DIJKSTRA----------------------------

int getminvertex(int* distances , bool* visited , int n){
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 || distances[minvertex] > distances[i]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}

void dijkstra(int** edges , int n){
    int* distances = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false; 
    }
    distances[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int minvertex = getminvertex(distances , visited , n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minvertex][j] != 0 && !visited[j])
            {
                int dis = distances[minvertex] + edges[minvertex][j];
                if (dis < distances[j])
                {
                    distances[j] = dis;
                }
            }   
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<distances[i]<<" ";
    }
    delete[] distances;
}

//----------------------IS BIAPRATE----------------------------------

bool isBiaprate(int** edges , int n){
    int color[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }
    color[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (edges[u][u] == 1)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (edges[u][i] == 1 && color[i] == -1)
            {
                color[i] = 1-color[u];
                q.push(i);
            }
            else if (edges[u][i] == 1 && color[i] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}

//-------------------------no of islands-----------------------------------//

void removeislands(vector<vector<int>> grid , int i , int j){
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == 0)
    {
        return;
    }
    grid[i][j] == 0;
    removeislands(grid , i-1 , j);
    removeislands(grid , i+1 , j);
    removeislands(grid , i , j-1);
    removeislands(grid , i , j+1);
}

int noofislands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
                removeislands(grid , i , j);
            }
        }
    }
    return count;
}

int main(){
    int n,e;
    cin>>n>>e;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
    // BFS(edges , n);
    // cout<<endl;
    // DFS(edges , n);
    // cout<<endl;
    // cout<<haspath(edges , n , 0 , 3)<<endl;
    // cout<<isconnected(edges , n)<<endl;
    // printconnected(edges , n);
    cout<<iscycle(edges , n)<<endl;
    cout<<isBiaprate(edges , n)<<endl;

    // int n,e;
    // cin>>n>>e;
    // int** edges = new int*[n];
    // for (int i = 0; i < n; i++)
    // {
    //     edges[i] = new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         edges[i][j] = 0;
    //     }
    // }
    // for (int i = 0; i < e; i++)
    // {
    //     int first , second , weight;
    //     cin>>first>>second>>weight;
    //     edges[first][second] = weight;
    //     edges[second][first] = weight;
    // }
    // dijkstra(edges , n);
}