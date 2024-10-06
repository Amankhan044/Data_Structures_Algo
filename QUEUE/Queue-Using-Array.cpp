#include <iostream>
using namespace std;

class Queue
{

private:
    int front;
    int rear;
    int *queue;
    int size;

public:
    Queue()
    {
        size = 10;
        queue = new int[size];
        front = -1;
        rear = -1;
    };
    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue overflow";
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = x;
        }
        else
        {
            rear++;
            queue[rear] = x;
        }
    };
    void dequeu()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow";
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            cout << "DeQueue element is:" << front[queue];
            front++;
        }
    };
    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow";
        }
        else
        {
            for (int i = front; i < rear + 1; i--)
            {
                cout << "elements of Queue are:" << queue[i];
            }
        }
    }

    void peek()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow";
        }
        else
        {
            cout << queue[front];
        }
    }
};

int main()
{

    Queue obj;
    obj.enqueue(12);
    obj.enqueue(13);
    obj.enqueue(14);
    obj.display();
    obj.dequeu();
    obj.peek();
    obj.enqueue(15);
    obj.enqueue(16);
    obj.dequeu();
    obj.display();
}