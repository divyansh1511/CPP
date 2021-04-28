#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6};
    int tofind = 5;
    int first = 0;
    int last = 5;
    int middle = (first + last)/2;

    while (first <= last)
    {
        if (arr[middle] == tofind)
        {
            cout<<middle<<endl;
            break;
        }
        else if (tofind > arr[middle])
        {
            first = middle+1;
        }
        else
        {
            last = middle - 1;
        }
    }
    if (first >last)
    {
        cout<<"element not found"<<endl;
    }
    
}