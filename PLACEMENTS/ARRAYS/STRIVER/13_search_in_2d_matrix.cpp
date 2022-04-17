#include<bits/stdc++.h>
using namespace std;

bool searchmatrix(vector<vector<int>> v , int target){
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == target)
        {
            return true;
        }
        if (v[i][0] > target)
        {
            if (i == 0)
            {
                return false;
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    if (v[i-1][j] == target)
                    {
                        return true;
                    }
                }
                break;
            }
        }
        else if (i == n-1)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == target)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){

}