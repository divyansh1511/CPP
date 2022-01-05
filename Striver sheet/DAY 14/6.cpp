#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minstack{
    private:
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int element){
        s1.push(element);
        if (s2.empty() || element <= getmin())
        {
            s2.push(element);
        }
    }
    void pop(){
        if (s1.top() == getmin())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int getmin(){
        return s2.top();
    }
};

int main(){
    
}