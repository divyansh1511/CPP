#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

static bool cmp(Job &a , Job &b){
    return a.profit > b.profit;
}
    
vector<int> JobScheduling(Job arr[], int n) 
{
    sort(arr , arr+n , cmp);
    int a = 0 , ww = 0;
    vector<int> t(101 , -1);
    for(int i=0;i<n;i++){
        int j = arr[i].dead - 1;
        while(j >= 0 && t[j] != -1){
            j--;
        }
        if(j >= 0 && t[j] == -1){
            a++;
            ww += arr[i].profit;
            t[j] =1;
        }
    }
    return vector<int>{a,ww};
} 

int main(){

}