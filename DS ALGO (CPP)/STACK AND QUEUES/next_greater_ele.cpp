#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextLargerElement(vector<int> arr, int n){
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int minindex = -1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                minindex = arr[j];
                break;
            }
        }
        v.push_back(minindex);
    }
    return v;
}

void nextlargerele(int arr[] , int n){
    stack<int> s;
    int res[n];
    for (int i = n-1; i >= 0; i--)
    {
        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<res[i]<<" ";
    }
}

int main(){
    // vector<int> arr = {6,8,0,1,3};
    // vector<int> res = nextLargerElement(arr , 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<res[i]<<" ";
    // }
    int arr[] = {6,8,0,1,3};
    nextlargerele(arr , 5);
}