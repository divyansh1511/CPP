#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return maxheap.empty() ? 0 : (maxheap.top()+minheap.top())/2.0;
        }
        return (maxheap.size() > minheap.size()) ? maxheap.top() : minheap.top();
    }
};

int main(){

}