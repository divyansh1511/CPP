#include<iostream>
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
            tail->next =  newnode;
            tail = newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head){
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node* oddEvenList(node* head) {

		//if list contains atmost one node

		if(head == NULL || head->next == NULL)
		{
			return head;
		}

		node* odd = head;
		node* even = head->next;
		node* evenHead = even;

		while(odd->next != NULL && even->next != NULL)
		{
			odd->next = odd->next->next;      // odd joins with 2nd next node
			even->next = even->next->next;    // even joins with 2nd next node

			odd = odd->next;
			even = even->next;
		}

		odd->next = evenHead;     // join head of even list with odd list        

		return head;

	}

int main(){
    node* head = takeinput();
    node* result = oddEvenList(head);
    print(result);
}