#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> &a , pair<int,int> &b){
    return a.second < b.second;
}

int maxmeetings(int start[] , int end[] , int n){
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i] , end[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int a = v[0].second;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > a)
        {
            c++;
            a = v[i].second;
        }
    }
    return c;
}

int minimumPlatforms(int ari[] , int dep[] , int n){
    vector<int> v(2361 , 0);
    for (int i = 0; i < n; i++)
    {
        v[ari[i]]++;
        v[dep[i]+1]--;
    }
    int ans = 0;
    for (int i = 1; i < 2361; i++)
    {
        v[i] = v[i] + v[i-1];
        ans = max(ans , v[i]);
    }
    return ans;
}

//-----------Job Sequencing------------//

static bool cmp2(pair<int,int> &a , pair<int,int> &b){
    double x = (double)a.second/(double)a.first;
    double y = (double)a.second/(double)a.first;
    return x > y;
}

double FractionalKnapsack(int weight[] , int val[] , int W , int n){
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({weight[i] , val[i]});
    }
    sort(v.begin() , v.end() , cmp2);
    double sum = 0.0;
    double w1 = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (w1 >= W)
        {
            break;
        }
        if (w1 + v[i].first <= W)
        {
            sum += v[i].second;
            w1 += v[i].first;
        }
        else if (w1 < W)
        {
            double a = (double) v[i].second/v[i].first;
            sum += (W-w1)*a;
            w1 = W;
        }
    }
    return sum;
}

int minnoofcoins(vector<int> arr , int amount){
    sort(arr.begin() , arr.end() , greater<int>());
    int i = 0;
    int c = 0;
    while (i < arr.size())
    {
        while(arr[i] < amount){
            amount -= arr[i];
            c++;
        }
        i++;
    }
    return c;
}

int main(){

}