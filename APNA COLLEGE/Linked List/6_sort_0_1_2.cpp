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

void sort012(node* head){
    int count[] = {0 , 0 , 0};
    node* pt = head;
    while (pt != NULL)
    {
        count[pt->data]++;
        pt = pt->next;
    }
    int i = 0;
    pt = head;
    while (pt != NULL)
    {
        if (count[i] == 0)
        {
            i++;
        }
        else
        {
            pt->data = count[i];
            count[i]--;
            pt = pt->next;
        }
    }
}

int main(){

}