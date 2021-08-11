#include<iostream>
using namespace std;

//---------------BRUTE FORSE-----------------//
// TIME COMPLEXITY : O(N^2)

// int main(){
//     int n,x;
//     cin>>n>>x;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
    
//     int mi = INT16_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         int s = 0;
//         for (int j = i; j < n; j++)
//         {
//             s += a[j];
//             if (s > x)
//             {
//                 mi = min(mi , j-i+1);
//             }
//         }
//     }
//     cout<<mi<<endl;
// }

//--------------------------------------------------//

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int mi = INT16_MAX;
    int i=0 , j=0;
    int s = 0;
    while (i<=j && j<n)
    {
        while (s<k && j<n)
        {
            s += a[j];
            j++;
        }
        while (s>k && i<j)
        {
            mi = min(mi , j-i);
            s -= a[i];
            i++;
        }
    }
    cout<<mi<<endl;
}