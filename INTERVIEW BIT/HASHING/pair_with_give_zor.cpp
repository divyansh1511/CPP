#include<bits/stdc++.h>
using namespace std;

int totalpairs(vector<int> arr , int B){
    int count = 0;
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(B^arr[i]) != s.end())
        {
            count++;
        }
        s.insert(arr[i]);
    }
    return count;
}

int main(){

}