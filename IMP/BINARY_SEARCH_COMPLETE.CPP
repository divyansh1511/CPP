#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] , int n , int k){
    int i = 0 , j = n - 1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int first_occurence(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            j = mid-1;
        }
        else if (arr[mid] < k)
        {
            i = mid+1;
        }
        else if(arr[mid] > k)
        {
            j = mid-1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

int lastoccurence(int arr[] , int n , int k){
    int i = 0, j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            i = mid+1;
        }
        else if (arr[mid] < k)
        {
            i = mid+1;
        }
        else if(arr[mid] > k)
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return ans;
}

int squareRoot(int n){
    int i = 0 , j = n-1;
    long long int mid = i + (j-i)/2;
    int ans = 0;
    while (i <= j)
    {
        long long int sq = mid*mid;
        if (sq == n)
        {
            return mid;
        }
        if (sq < n)
        {
            ans = mid;
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return ans;
}

int getPivot(int arr[] , int n){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        int prev = (mid - 1 + n)%n;
        int next = (mid+1)%n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            return mid;
        }
        else if(arr[mid] >= arr[0])
        {
            i = mid+1;
        }
        else if(arr[mid] >= arr[n])
        {
            j = mid-1;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int smallerorequal(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    int ans = 0;
    while (i < j)
    {
        if (arr[mid] > k)
        {
            j = mid - 1;
        }
        else
        {
            ans = mid+1;
            i = mid+1;
        }
        mid = i + (j-i)/2;
    }
    return ans;
}

int searchrotated(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    int mid = i + (j-i)/2;
    while (i < j)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[0] <= arr[mid])
        {
            if (arr[mid] > k && arr[0] <= k)
            {
                j = mid - 1;
            }
            else
            {
                i = mid+1;
            }
        }
        else
        {
            if(arr[mid] < k && arr[n-1] >= k)
            {
                i = mid+1;
            }
            else
            {
                j = mid - 1;
            }
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int matrixSearch(vector<vector<int>> A , int B){
    int N=A.size();
    int M=A[0].size();
    int start=0, end=N*M-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        int x=mid/M;
        int y=mid%M;
        if(A[x][y]==B) return 1;
        if(B<A[x][y]) end=mid-1;
        else start=mid+1;
    }
    return 0;
}

bool isPossible(vector<int> &arr , int m , int mid){
    int studentcount = 1;
    int currsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if (currsum > mid)
        {
            studentcount++;
            currsum = arr[i];
        }
        if (studentcount > m)
        {
            return false;
        }
    }
    return true;
}

int books(vector<int> &arr , int B){
    int n = arr.size();
    long long int sum = 0;
    int maxele = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxele = max(maxele , arr[i]);
    }
    long long int s = maxele;
    long long int e = sum;
    int mid = s + (e-s)/2;
    while (s <= e)
    {
        if (isPossible(arr , B , mid))
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int median(int arr1[] , int arr2[] , int n , int m){
    int lo = 0 , hi = n;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
        l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
        l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
        r1 = cut1 == n ? INT_MAX : arr1[cut1];
        r2 = cut2 == m ? INT_MAX : arr2[cut2];
        if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else if (l2 > r1)
        {
            lo = cut1 + 1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2 : min(r1 , r2);
        }
    }
}


int main(){
    // int arr[] = {10,30,30,30,40,50};
    // cout<<first_occurence(arr , 6 , 30)<<endl;
    // cout<<lastoccurence(arr , 6 , 30)<<endl;
    // cout<<squareRoot(11)<<endl;
    // int arr1[] = {5,6,1,2,3,4};
    // cout<<getPivot(arr1 , 6)<<endl;
    // int arr[] = {5,6,7,1,2,3,4};
    // cout<<searchrotated(arr , 7 , 3)<<endl;
    vector<vector<int>> v = {{1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}};
      cout<<matrixSearch(v , 3)<<endl;
}