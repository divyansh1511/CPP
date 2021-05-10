#include<iostream>
using namespace std;
#include<stack>

int* stockspan(int prices[], int size){
    int* output = new int[size];
    stack<int> s;
    s.push(0);
    output[0] = 1;

    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && prices[i] >= prices[s.top()])
        {
            s.pop();
        }
        output[i] = s.empty()?(i+1):(i-s.top());
        s.push(i);
    }
    return output;
}

int main(){
    int arr[] = {100,120,60,70,75,85,130};
    int* output = stockspan(arr , 7);
    for (int i = 0; i < 7; i++)
    {
        cout<<output[i]<<" ";
    }
    
}