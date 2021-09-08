#include <iostream>

using namespace std;

class implement
{
private:
    int front, rear;

public:
    int count;
    int n;
    int arr[5];
    implement(int size)
    {
        n = size;
        front = -1;
        count = 0;
        rear = -1;
    }

    bool isfull();
    void enqueue(int val);
    bool isempty();
    void dequeue();
    void display();
};
bool implement::isfull()
{

    if (front == (rear + 1) % n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void implement::enqueue(int value)
{
    if (isfull())
    {
        cout << "queue is full " << endl;
        return;
    }
    count = 0;
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
    }

    arr[rear] = value;
}

bool implement::isempty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void implement::dequeue()
{
    if (isempty())
    {
        cout << "queue is empty" << endl;
        return;
    }
    count = 1;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}
void implement::display()
{
    if (isempty())
    {
        cout << "queue is empty" << endl;
    }
    if (front > rear)
    {
        for (int i = rear; i <= n - 1; i++)
        {
            if (count == 1 && i == front - 1)
            {
                continue;
            }
            cout << arr[i] << " ";
        }
    }
    else
    {

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    implement queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(6);
    queue.display();
    queue.enqueue(6);
    queue.dequeue();
    queue.display();

    return 0;
}