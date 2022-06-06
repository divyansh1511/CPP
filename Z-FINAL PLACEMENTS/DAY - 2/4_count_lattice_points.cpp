#include <bits/stdc++.h>
using namespace std;

int countLatticePoints(vector<vector<int>> &circles)
{
    int n = circles.size();
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int a = circles[i][0], b = circles[i][1], c = circles[i][2];
        for (int j = -c; j <= c; j++)
        {
            for (int k = -c; k <= c; k++)
            {
                if (j * j + k * k <= c * c)
                {
                    s.insert({j + a, k + b});
                }
            }
        }
    }
    return s.size();
}

int main()
{
}