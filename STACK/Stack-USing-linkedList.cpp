#include <iostream>
#include <stack>
using namespace std;

class Linkedlist
{
private:
    struct node
    {
        int data;
       struct node *link;
    };
     struct node *top;

public:
    Linkedlist()
    {
        top = NULL;
    }
    int isempty()
    {
        if (top == NULL)
        {
            return 0;
        }
        else
        {

            return -1;
        }
    }
    void push(int x)
    {
        node *newnode = new node();
        newnode->data = x;
        newnode->link = top;
        top = newnode;
    }
    void pop()
    {
        if (isempty() == 0)
        {
            cout << "Stack is empty";
        }
        else
        {
            node *deleteNode;
            deleteNode  = top;
            top = top->link;
            delete (deleteNode);
        }
    }
    void DisplayList()
    {
         node* temp;
        temp=top;
        cout << "Elements of Linked List are: " << endl;
        if (isempty() == 0)
        {
            cout << "Empty Linked List";
        }
        else
        {
           
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->link;
            }
        }
    }
    void peekTop(){
        if (isempty()==0)
        {
            cout<<"List is Empty";
        }
        else{
            cout<<top->data;
        }
        
    }
    ~Linkedlist(){
        delete top;
    }
};

int main()
{
    Linkedlist obj;
    obj.isempty();
    obj.push(12);
    obj.push(14);
    obj.push(17);
    obj.push(13);
    obj.pop();
    obj.DisplayList();

}