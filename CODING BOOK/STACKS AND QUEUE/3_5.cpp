#include<bits/stdc++.h>
using namespace std;

void insertsortedly(stack<int> &st , int a){
    if (st.empty() || st.top() >= a)
    {
        st.push(a);
        // return;
    }
    else
    {
        int t = st.top();
        st.pop();
        insertsortedly(st , a);
        st.push(t);
    }
}

void sortstack(stack<int> &st){
    if (st.size() <= 1)
    {
        return;
    }
    int a = st.top();
    st.pop();
    sortstack(st);
    insertsortedly(st , a);
}

int main(){
    stack<int> st;
    st.push(50);
    st.push(10);
    st.push(30);
    st.push(20);
    sortstack(st);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}