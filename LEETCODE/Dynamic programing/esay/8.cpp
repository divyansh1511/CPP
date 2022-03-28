#include<bits/stdc++.h>
using namespace std;

int buystock1(vector<int> arr){
    int minnum = INT_MAX;
    int maxnum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        minnum = min(minnum , arr[i]);
        maxnum = max(maxnum , arr[i] - minnum);
    }
    return maxnum;
}

int main(){

}