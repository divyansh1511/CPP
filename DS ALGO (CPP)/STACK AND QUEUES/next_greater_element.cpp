// NOT CORRECT YET .....................
#include<iostream>
#include<stack>
using namespace std;

void nge(int arr[] , int n){
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++) 
    {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        if (s.top() > arr[i])
        {
            cout << s.top() << " --> " << -1 << endl;
            s.pop();
        }
        
        while (s.empty() == false && s.top() < arr[i]) 
        {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main(){
    int arr[] = {1,3,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    nge(arr, n);
    return 0;
}