#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int calPoints(vector<string>& ops) {
    stack<int> s;
    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == "C")
        {
            s.pop();
        }
        else if (ops[i] == "D")
        {
            int temp = s.top();
            s.push(2* temp);
        }
        else if (ops[i] == "+")
        {
            int temp1 = s.top();
            s.pop();
            int temp2 = s.top();
            s.push(temp1);
            //s.push(temp2);
            s.push(temp1 + temp2);
        }
        else
        {
            s.push(stoi(ops[i]));
        }
    }
    int res = 0;
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    return res;
}

int main(){
    vector<string> ops;
    string arr[] = {"5","2","C","D","+"};
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < arrsize; i++)
    {
        ops.push_back(arr[i]);
    }
    cout<<calPoints(ops)<<endl;
}