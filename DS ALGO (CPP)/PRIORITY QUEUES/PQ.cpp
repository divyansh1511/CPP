// NOT WORKING
// NOT COMPETED

#include<iostream>
#include<vector>
using namespace std;

class PQpair{
    public:
    int priority;
    int value;
};

class Priorityqueues{
    vector<PQpair*> tree;

    public:
    Priorityqueues(){
        tree.push_back(NULL);
    }

    bool isempty(){
        return tree.size() == 1;
    }

    int getsize(){
        return tree.size() - 1;
    }

    PQpair* getmin(){
        if (isempty())
        {
            return NULL;
        }
        return tree[1];
    }

    void insert(int priority , int value){
        PQpair* p = new PQpair();
        p->priority = priority;
        p->value = value;
        tree.push_back(p);

        int childindex = tree.size() - 1;
        int parentindex = childindex/2;

        while (childindex != 1)
        {
            if (tree[childindex]->priority >= tree[parentindex]->priority)
            {
                break;
            }
            PQpair* temp = tree[childindex];
            tree[childindex] = tree[parentindex];
            tree[parentindex] = temp;

            childindex = parentindex;
            parentindex = parentindex/2;
        }
    }

    PQpair* removemin(){
        PQpair* tobereturned = tree[1];
        tree[1] = tree[tree.size() - 1];
        tree.pop_back();
        int parentindex;
        while (2*parentindex < tree.size())
        {
            int leftindex = 2*parentindex;
            int rightindex = 2*parentindex+1;

            int childindexforswapping = leftindex;
            if (rightindex < tree.size())
            {
                if (tree[rightindex]->priority < tree[leftindex]->priority)
                {
                    childindexforswapping = rightindex;
                }
            }
            if (tree[parentindex]->priority <= tree[childindexforswapping]->priority)
            {
                break;
            }
            PQpair* temp = tree[childindexforswapping];
            tree[childindexforswapping] = tree[parentindex];
            tree[parentindex] = temp;

            parentindex = childindexforswapping;
        }
        return tobereturned;
    }
};

void heapsort(int* arr , int size){
    Priorityqueues pq;
    for (int i = 0; i < size; i++)
    {
        pq.insert(arr[i] , arr[i]);
    }

    while (!pq.isempty())
    {
        cout<<pq.removemin()->value<<endl;
    }
}

int main(){
    int arr[] = {4,2,6,3,8};
    heapsort(arr , 5);
}