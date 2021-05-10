#include<iostream>
using namespace std;
#include<stack>

void insert(stack<int> &s , int k){
    if (s.empty() || k>=s.top())
    {
        s.push(k);
    }
    else
    {
        int a = s.top();
        s.pop();
        insert(s , k);
        s.push(a);
    }
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    insert(s , 25);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}