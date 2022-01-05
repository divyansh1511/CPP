#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class queue{
    public:
    stack<int> input , output;
    int push(int element){
        input.push(element);
    }
    void pop(){
        peek();
        output.pop();
    }
    int peek(){
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
};

int main(){

}