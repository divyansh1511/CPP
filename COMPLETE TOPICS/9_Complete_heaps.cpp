#include<bits/stdc++.h>
using namespace std;

//-----------------------------BUILD HEAP--------------------------//

void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i] , arr[largest]);
        heapify(arr , n , largest);
    }
}

void buildHeap(int arr[] , int n){
    int st = n/2;
    for (int i = st; i >= 0; i++)
    {
        heapify(arr , n , i);
    }
}

//-------------------------------Heap Sort--------------------------------//

void heapSort(int arr[] , int n){
    for (int i = n/2; i >= 0; i--)
    {
        heapify(arr , n , i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        swap(arr[0] , arr[i]);
        heapify(arr , i , 0);
    }
}

//-----------------------------kth largest----------------------------//

int kthlargestele(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int kthsmallest(int arr[] , int n , int k){
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

vector<int> mergeksortedarr(vector<vector<int>> v , int n){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); i++)
        {
            pq.push(v[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

void heapinsert(int b , vector<int> &a , int n){
    a.push_back(b);
    while (a[n] > a[(n-1)/2])
    {
        swap(a[n] , a[(n-1)/2]);
        n = (n-1)/2;
    }
}

vector<int> merge2maxheap(vector<int> a , vector<int> b , int n , int m){
    for (int i = 0; i < m; i++)
    {
        heapinsert(b[i] , a , n);
    }
    return a;
}

int kthlargestsum_subarr(int arr[] , int n , int k){
    int sum[n+1];
    sum[0] = 0;
    sum[1] = arr[0];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i-1] + arr[i-1];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int x = sum[j] - sum[i-1];
            if (pq.size() < k)
            {
                pq.push(x);
            }
            else
            {
                if (pq.top() < k)
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }
    return pq.top();
}

class medianinstram{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap; //creating a maxHeap
    priority_queue<int, vector<int>, greater<int>> minHeap; //creating a min Heap
    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0 || maxHeap.top() >= x)
            maxHeap.push(x);
        else
            minHeap.push(x);
            
        balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }        
    }
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size())
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
            
        return (double)maxHeap.top();
    }
};

void convertmintomaxheap(int arr[] , int n){
    for (int i = (n-2)/2; i >= 0; i--)
    {
        heapify(arr , n , i);
    }
}

int main(){

}