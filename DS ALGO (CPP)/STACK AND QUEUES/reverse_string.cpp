// reversing a string using Inbuilt stack
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stack>

void reversestack(char arr[]){
    stack<char> s;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        s.push(arr[i]);
    }
    for (int j = 0; j<s.size()+j; j++)
    {
        arr[j] = s.top();
        s.pop();
    }
    
}

int main(){
    char s[100];
    cin.getline(s,100);
    reversestack(s);
    cout<<s;
}