#include<iostream>
#include<stack>
using namespace std;

void sortinsert(stack<int> s , int x){
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    sortinsert(s , temp);
    s.push(temp);
}

void sort(stack<int> s){
    int x = s.top();
    s.pop();
    sort(s);
    sortinsert(s , x);
}

int main(){
    stack<int> s;
}