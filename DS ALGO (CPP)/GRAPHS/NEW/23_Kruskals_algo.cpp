#include <vector>
#include <algorithm>
using namespace std;

bool sortByWeight(const vector<int>& edge1, const vector<int>& edge2)
{
    return edge1[2] < edge2[2];
}

int findSet(vector<int>& parent, int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findSet(parent, parent[node]);
}

void unionSet(vector<int>& parent,vector<int>& rank, int set1, int set2)
{
    set1 = findSet(parent, set1);
    set2 = findSet(parent, set2);

    if (set1 != set2)
    {
        if (rank[set1] < rank[set2])
        {
            swap(set1, set2);
        }

        parent[set2] = set1;

        if (rank[set1] == rank[set2])
        {
            rank[set1]++;
        }
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), sortByWeight);

    int finalWeight = 0;


    vector<int> parent(n);
    vector<int> rank(n);

    for (int i = 0; i < n; i++)
    {
        // makeSet(parent, rank, i);
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int set1 = findSet(parent, edges[i][0]);
        int set2 = findSet(parent, edges[i][1]);

        if(set1 != set2)
        {
            finalWeight += edges[i][2];
            unionSet(parent,rank, set1, set2);
        }
    }
    return finalWeight;
}

int main(){

}