#include <bits/stdc++.h>
using namespace std;

//---------------------activit selcetion problem(n-metting room)-----------------//

int maxmetting(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end());
    int c = 1;
    int s = v[0].second;
    int e = v[0].first;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > e)
        {
            c++;
            e = v[i].first;
        }
    }    
    return c;
}

//----------------------------JOB SCHEDULLING-------------------------//

struct Job
{
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
            // c++;
            t[j] =1;
        }
    }
    return vector<int>{a,ww};
}

//---------------------Fractional KNAPSACK-----------------------//

struct Item{
    int value;
    int weight;
};

static bool comp(Item a, Item b)
{
    double x=(double)a.value/(double)a.weight;
    double y=(double)b.value/(double)b.weight;
    if(x>y)
        return true;
    else
        return false;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,comp);
    double sum=0.0;
    double wei=0.0;
    for(int i=0;i<n;i++)
    {
        if(wei>=W)
            break;
           
        if(wei+arr[i].weight<=W )
        {
            sum=sum+arr[i].value;
            wei+=arr[i].weight;
        }
        else if(wei<W)
        {
            double d=(double)arr[i].value/(double)arr[i].weight;
            sum=sum+(W-wei)*d;
            wei=W;
        }
    }
    return sum;
}

//----------------------MIN Platform------------------------//

int findPlatform(int arr[], int dep[], int n)
{
    int i=1;
	int j=0;
    sort(arr,arr+n);
	sort(dep,dep+n);
    int maxm=1;
	int plateform=1;
    while(i<n&&j<n)
    {
    	if (arr[i]<=dep[j])
        {
	        plateform++;
    	    i++;
    	}
        else 
	    {
    	    plateform--;
    	    j++;
        }
	    maxm=max(maxm,plateform);
    }
	return maxm;
}

//--------------MIN AND MAX COST OF CANDIES---------------------//

vector<int> candyStore(int a[], int N, int K)
{
    int cnt = ceil(N*1.0/(K+1));
    sort(a,a+N);
    int s1 = 0, s2 = 0;
    for(int i=0;i<cnt;i++)
    {
        s1+=a[i];
        s2+=a[N-1-i];
    }
    return {s1,s2};
}

//----------------max product subarr------------------//

int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_zero++;
            continue;
        }

        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
 
        prod = prod * a[i];
    }

    if (count_zero == n)
        return 0;

    if (count_neg & 1) {

        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;
        prod = prod / max_neg;
    }
    return prod;
}

int main()
{
}