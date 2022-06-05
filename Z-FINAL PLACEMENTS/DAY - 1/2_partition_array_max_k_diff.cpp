#include<bits/stdc++.h>
using namespace std;

int noofpartition(vector<int> arr , int k){
    sort(arr.begin() , arr.end());
    int first = arr[0];
    int count = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - first > k)
        {
            count++;
            first = arr[i];
        }
    }
    return count;
}

int main(){

}