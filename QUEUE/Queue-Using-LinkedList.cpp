#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Queue
{
    node *front;
    node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x)
    {
        node *newnode = new node(x);
        if (front == NULL)
        {
            rear = newnode;
            front = newnode;
            return;
        }

        rear->next = newnode;
        rear = newnode;
    }

    void dequeu()
    {
        if (front == NULL)
        {
            cout << "queue underflow: ";
            return;
        }
        node *deletenode = front;
        front = front->next;

        delete deletenode;
    }

    void display()
    {
        node *temp;
        if (front == 0 && rear == 0)
        {
            cout << "Queue is empty: ";
        }
        else
        {
            temp = front;
            while (temp != 0)
            {
                cout << temp->val;
                temp = temp->next;
            }
        }
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "no element in queue: ";
            return 7;
        }
        return front->val;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    cout << q1.peek() << endl;
    q1.dequeu();
    cout << q1.peek() << endl;
    q1.dequeu();

    cout << q1.peek() << endl;
    q1.dequeu();

    cout << q1.peek() << endl;
    q1.dequeu();

    cout << q1.peek() << endl;
    q1.dequeu();
    cout << q1.empty() << endl;

    return 0;
}
