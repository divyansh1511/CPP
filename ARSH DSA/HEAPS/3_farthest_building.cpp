#include<bits/stdc++.h>
using namespace std;

int farthest_building(vector<int> v , int brick , int ladders){
    priority_queue<int> pq;
    for (int i = 0; i < v.size()-1; i++)
    {
        int d = v[i+1] - v[i];
        if (d > 0)
        {
            pq.push(-d);
        }
        if (pq.size() > ladders)
        {
            brick += pq.top();
            pq.pop();
        }
        if (brick < 0)
        {
            return i;
        }
    }
    return v.size() - 1;
}

int main(){

}