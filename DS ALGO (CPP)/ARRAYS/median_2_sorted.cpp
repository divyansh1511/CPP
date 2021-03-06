#include<iostream>
using namespace std;

int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
    if((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
    else
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            m2 = m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2)/2;
    }
}

int main(){
    int arr1[] = {2,4,6,8};
    int arr2[] = {1,3,5,7};
    cout<<getMedian(arr1 , arr2 , 4 ,4);
}