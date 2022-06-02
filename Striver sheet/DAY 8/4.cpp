#include<bits/stdc++.h>
using namespace std;

struct Item{
    int val;
    int weight;
};

bool static cmp(Item a , Item b){
    double c1 = (double)a.val/(double) a.weight;
    double c2 = (double)b.val/(double) b.weight;
    return c1 > c2;
}

bool FractionalKnapsack(Item arr[] , int W , int n){
    sort(arr , arr+n , cmp);
    int currweight = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight + currweight <= W)
        {
            currweight += arr[i].weight;
            ans += arr[i].val;
        }
        else
        {
            int remain = W-currweight;
            ans += ((arr[i].val) / (double) arr[i].weight) * (double) remain;
            break;
        }
    }
    return ans;
}

int main(){

}