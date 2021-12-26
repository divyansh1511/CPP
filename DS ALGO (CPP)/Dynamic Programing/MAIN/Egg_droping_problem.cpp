#include<bits/stdc++.h>
using namespace std;

int eggdroping(int e , int f){
    if (f == 0 || f == 1)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    int mini = INT_MAX;
    for (int i = 1; i <= f; i++)
    {
        int temp = 1 + max(eggdroping(e-1 , i-1) , eggdroping(e , f-i));
        mini = min(temp , mini);
    }
    return mini;
}
vector<vector<int>> memo(100, vector<int> (100, -1));
int eggdropingmem(int n ,int k){
    if(memo[n][k] != -1) { return memo[n][k];}
     
    if (k == 1 || k == 0)
      return k;
 
    if (n == 1)
      return k;
 
    int min = INT_MAX, x, res;
 
    for (x = 1; x <= k; x++) {
      res = max(
        eggdropingmem(n - 1, x - 1),
        eggdropingmem(n, k - x));
      if (res < min)
        min = res;
    }
     
    memo[n][k] = min+1;
    return min + 1;
}

int eggdrop(int n , int k){
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;

    for (i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++) {
                res = 1 + max(
                            eggFloor[i - 1][x - 1],
                            eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    return eggFloor[n][k];
}

int main(){
    cout<<eggdroping(2 ,10)<<endl;
    cout<<eggdropingmem(2 , 10)<<endl;
    cout<<eggdrop(2 ,10)<<endl;
}