#include<bits/stdc++.h>
using namespace std;

vector<int>* getpathDFShelper(int** edges , int n , int v1 ,int v2 , bool* visited){
    if (v1 == v2)
    {
        vector<int>* output = new vector<int>();
        output->push_back(v2);
        return output;
    }
    visited[v1] = true;
    
    for (int i = 0; i < n; i++)
    {
        if (edges[v1][i] == 1 && !visited[i])
        {
            vector<int>* smalloutput = getpathDFShelper(edges , n , i , v2 , visited);
            if (smalloutput != NULL)
            {
                smalloutput->push_back(v1);
                return smalloutput;
            }
        }
    }
    return NULL;
}

vector<int>* getpathDFS(int** edges , int n , int v1 ,int v2){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    vector<int>* output = getpathDFShelper(edges , n , v1 ,v2 , visited);
    return output;
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
        int first,second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    vector<int>* output = getpathDFS(edges , n ,1,4);

    for (int i = 0; i < output->size(); i++)
    {
        cout<<output->at(i)<<" ";
    }
    
}

