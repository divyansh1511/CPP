#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

int multiply(node* h1 , node* h2){
    int num1 = 0 , num2 = 0;
    while (h1 || h2)
    {
        if (h1)
        {
            num1 = num1*10 + h1->data;
            h1 = h1->next;
        }
        if (h2)
        {
            num2 = num2*10 + h2->data;
            h2 = h2->next;
        }
    }
    return num1*num2;
}

int main(){

}