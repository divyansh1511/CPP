#include<iostream>
#include<vector>
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

node* takeinput(){
    node* head = NULL;
    node* tail = NULL;

    int data;
    cin>>data;
    while (data != -1)
    {
        node* newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

vector<int> nextLargerNodes(node* head) {
    vector<int> v;
    while(head != NULL){
        node* curr = head;
        int tempdata = curr->data;
        bool found = false;
        while(curr != NULL){
            int a = curr->data;
            if(a > tempdata){
                v.push_back(a);
                found = true;
                break;
            }
            curr = curr->next;
        }
        if(found == false){
            v.push_back(0);
        }
        head = head->next;
    }
    return v;
}

int main(){
    node* head = takeinput();
    vector<int> a = nextLargerNodes(head);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<endl;
    }
    
}