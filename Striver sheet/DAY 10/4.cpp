#include <bits/stdc++.h>
using namespace std;

bool possiblecol(int color, int node, bool gr[101][101], vector<int> col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && gr[node][i] == 1 && col[i] == color)
            return false;
    }
    return true;
}

bool solve(int node, int n, bool gr[101][101], vector<int> &col, int m)
{
    if (n == node)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (possiblecol(i, node, gr, col, n))
        {
            col[node] = i;
            if (solve(node + 1, n, gr, col, m))
                return true;

            col[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> adj[n];

    int i, j;

    vector<int> color(n);

    return solve(0, n, graph, color, m);
}

int main()
{
}