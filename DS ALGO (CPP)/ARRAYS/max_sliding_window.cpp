#include<bits/stdc++.h>
using namespace std;

vector<int> maxwindow(int arr[] , int n , int k){
    deque<int> dq;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            v.push_back(arr[dq.front()]);
        }
    }
    return v;
}

int main(){

}