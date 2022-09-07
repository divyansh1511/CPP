#include<bits/stdc++.h>
using namespace std;

int maxarearectangle(vector<int> &histogram){
    histogram.push_back(0);
    int area = 0 , n = histogram.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && histogram[st.top()] >= histogram[i])
        {
            int h = histogram[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            area = max(area , h*(right-left-1));
        }
        st.push(i);
    }
    return area;
}

int maximal_rectangle(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    vector<int> histogram(m , 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                histogram[j] += 1;
            }
            else
            {
                histogram[j] = 0;
            }
        }
        res = max(res , maxarearectangle(histogram));
    }
    return res;
}

int main(){

}