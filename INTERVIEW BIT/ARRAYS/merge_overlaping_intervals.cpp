#include<bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool cmp(Interval a,Interval b){
    return a.start<b.start;
}
vector<Interval> merge(vector<Interval> &A) {
    vector<Interval> v;
    sort(A.begin() , A.end() , cmp);
    v.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        int n = v.size();
        if(v[n-1].end >= A[i].start){
            v[n - 1].end = max(v[n - 1].end , A[i].end);
        }
        else{
            v.push_back(A[i]);
        }
    }
    return v;
}

int main(){
    
}