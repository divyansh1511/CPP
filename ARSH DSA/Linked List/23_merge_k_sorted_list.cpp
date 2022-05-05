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

node* merge(node* l1 , node* l2){
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next , l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1 , l2->next);
        return l2;
    }
}

node* mergeksorted(vector<node*> v){
    if (v.size() == 0)
    {
        return NULL;
    }
    while (v.size() > 1)
    {
        v.push_back(merge(v[0] , v[1]));
        v.erase(v.begin());
        v.erase(v.begin());
    }
    return v[0];
}

int main(){

}