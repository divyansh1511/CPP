#include<bits/stdc++.h>
using namespace std;

class stackusingarr{
    int* data;
    int lastelementindex;
    int capacity;

    public:
    stackusingarr(){
        data = new int[20];
        lastelementindex = -1;
        capacity = 20;
    }
    int size(){
        return lastelementindex+1;
    }
    bool isempty(){
        return lastelementindex == -1;
    }
    void push(int ele){
        if (lastelementindex == capacity)
        {
            int* newdata = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
        }
        lastelementindex++;
        data[lastelementindex] = ele;
    }
    int pop(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return data[lastelementindex--];
    }
    int top(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return data[lastelementindex];
    }
};

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

class stackusingll{
    node* head;
    int count;

    public:
    stackusingll(){
        head = NULL;
        count = 0;
    }
    int size(){
        return count;
    }
    bool isempty(){
        return count == 0;
    }
    void push(int ele){
        node* newnode = new node(ele);
        newnode->next = head;
        head = newnode;
        count++;
    }
    int pop(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        int rtval = head->data;
        head = head->next;
        count--;
        return rtval;
    }
    int top(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return head->data;
    }
};

class stackusingqueue{
    queue<int> q1;
    queue<int> q2;

    public:
    int size(){
        return q1.size();
    }

    bool isempty(){
        return q1.size() == 0;
    }

    void push(int element){
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(element);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop(){
        int a = q1.front();
        q1.pop();
        return a;
    }
};

bool isbalanced(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char currchar = str[i];
        if (currchar == '{' || currchar == '[' || currchar == '(')
        {
            s.push(currchar);
        }
        else if (currchar == '}')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last = s.top();
            s.pop();
            if (last != '{')
            {
                return false;
            }
        }
        else if (currchar == ']')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last = s.top();
            s.pop();
            if (last != '[')
            {
                return false;
            }
        }
        else if (currchar == ')')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last = s.top();
            s.pop();
            if (last != '(')
            {
                return false;
            }
        }
    }
    return true;
}

void insertsorted(stack<int> &s , int a){
    if (s.empty() || s.top() <= a)
    {
        s.push(a);
    }
    else
    {
        int b = s.top();
        s.pop();
        insertsorted(s , a);
        s.push(b);
    }
}

void sortstack(stack<int> &s){
    if (s.empty() || s.size() == 1)
    {
        return;
    }
    int a = s.top();
    s.pop();
    sortstack(s);
    insertsorted(s , a);
}

vector<int> nextGreaterele(vector<int> v){
    int n = v.size();
    stack<int> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            while (!s.empty() && s.top() < v[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
        }
        s.push(v[i]);
    }
    return ans;
}

int LargestRectangleArea(vector<int> heights){
    stack<int> st;
    heights.push_back(0);
    int ans = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int top = heights[st.top()];
            st.pop();
            int ran = st.empty() ? -1 : st.top();
            ans = max(ans , top*(i-ran-1));
        }
        st.push(i);
    }
    return ans;
}

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int balance =0;
    int deficit =0;
    int start = 0;
    for(int i=0; i<n; i++){
        balance += p[i].petrol - p[i].distance;
        if(balance <0){
            deficit += balance;
            start = i+1;
            balance =0;
        }
    }
       
    return balance + deficit >= 0 ? start : -1;
}

vector<int> stockspanproblem(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        ans[i] = s.empty() ? (i+1) : i - s.top();
        s.push(i);
    }
    return ans;
}

//-------------------------------------Queue------------------------------//

class queueusingll{
    node* head;
    node* tail;
    int count = 0;

    public:
    queueusingll(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    int size(){
        return count;
    }
    bool isempty(){
        return count == 0;
    }
    void enqueue(int ele){
        node* newnode = new node(ele);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    int dequeue(){
        if (isempty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return head->data;
    }

};

int rottenoranges(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int tot = 0, cnt = 0, days = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (grid[i][j] != 0)
            {
                tot++;
            }
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
            if (!q.empty())
            {
                days++;
            }
        }
    }
    return tot == cnt ? days : -1;
}

vector<int> slidingMaximum(vector<int> &A, int B) {
    int n = A.size();
    deque<int> dq;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front() == i-B){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= B-1){
            v.push_back(A[dq.front()]);
        }
    }
    return v;
}


int main(){

}