#include <bits/stdc++.h>
using namespace std;

bool checkBooksAllocate(vector<int> &A, int threshold, int B)
{
    int count = 0;

    int curr = 0;

    for (int i = 0; i < A.size(); i++)
    {

        if (count > B)
            return false;

        curr += A[i];

        if (curr > threshold)
        {

            curr = 0;

            count++;

            i--;
        }
    }

    count++;
    return count <= B;
}

int books(vector<int> &A, int B)
{

    if (B > A.size())
        return -1;

    long long low = *max_element(A.begin(), A.end());
    long long high = low * A.size();
    int n = A.size();
    long long mid;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (checkBooksAllocate(A, mid, B))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
}