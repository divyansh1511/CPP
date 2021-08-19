#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int goldmine(int arr[][4] , int n , int m){
    int goldtable[n][m];
    memset(goldtable , 0 , sizeof(goldtable));

    for (int col = m-1; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            int right = (col == m-1) ? 0 : goldtable[row][col+1];

            int right_up = (row == 0 || col == m-1) ? 0 : goldtable[row-1][col+1];

            int right_down = (row == m-1 || col == m-1) ? 0 : goldtable[row+1][col+1];

            goldtable[row][col] = arr[row][col] + max({right , right_down , right_up});
        }
    }
    
    int res = goldtable[0][0];
    for (int i = 0; i < n; i++)
    {
        res = max(res , goldtable[i][0]);
    }
    return res;
}

int main(){
    int gold[4][4]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << goldmine(gold, m, n);
}