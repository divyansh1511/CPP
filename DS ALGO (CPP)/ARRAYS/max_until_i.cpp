#include<iostream>
using namespace std;

int main(){

    int arr[] = {2,4,1,3,5};
    
    int mx = -199999;

    for (int i = 0; i < 5; i++)
    {
        mx = max(mx , arr[i]);
        cout<<mx<<endl;
    }
    
}