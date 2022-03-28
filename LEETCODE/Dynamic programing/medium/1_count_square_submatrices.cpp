#include<bits/stdc++.h>
using namespace std;

int count_submatrices(vector<vector<int>> arr){
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] && i && j)
            {
                arr[i][j] += min({arr[i-1][j-1] , arr[i-1][j] , arr[i][j-1]});
            }
            res += arr[i][j];
        }
    }
    return res;
}

int main(){

}