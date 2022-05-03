#include<bits/stdc++.h>
using namespace std;

int jumpgame(int arr[] , int n){
    int dis = 0;
    for (int i=0;i<=dis;i++)
    {
        dis = max(dis , arr[i]);
        if (dis >= n-1)
        {
            return true;
        }
    }
    return false;
}

int main(){

}