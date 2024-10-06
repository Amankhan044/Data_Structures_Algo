#include <iostream>
#define SPACE 10
using namespace std;

struct BSTreeNode
{
    int data;
    BSTreeNode *left;
    BSTreeNode *right;

    BSTreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BSTreeNode(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    BSTreeNode *root;

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(BSTreeNode *new_node)
    {
        if (root == NULL) 
        {
            root = new_node;
            cout << "Value inserted as root." << endl;
        }
        else
        {
            BSTreeNode *temp = root;
            while (temp != NULL)
            {
                if (temp->data == new_node->data)
                {
                    cout << "Duplicate value spotted! Please enter another value." << endl;
                }
                else if ((new_node->data < temp->data) && (temp->left == NULL))
                {
                    temp->left = new_node; // left child
                    cout << "Value added as left child." << endl;
                    break;
                }
                else if (new_node->data < temp->data)
                {
                    temp = temp->left;
                }
                else if ((new_node->data > temp->data) && (temp->right == NULL))
                {
                    temp->right = new_node; // right child
                    cout << "Value added as right child." << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void Preorder(BSTreeNode *r)
    { // NLR
        if (r == NULL)
        {
            return;
        }
        cout << r->data << "  ";
        Preorder(r->left);  // recursively printing left child
        Preorder(r->right); // recursively printing right child
    }

    void Inorder(BSTreeNode *r)
    { // LNR
        if (r == NULL)
        {
            return;
        }
        Inorder(r->left); // recursively printing left child
        cout << r->data << "  ";
        Inorder(r->right); // recursively printing right child
    }
    void Postorder(BSTreeNode *r)
    { // LRN
        if (r == NULL)
        {
            return;
        }
        Postorder(r->left);  // recursively printing left child
        Postorder(r->right); // recursively printing right child
        cout << r->data << "  ";
    }

    BSTreeNode *iterativeSearch(int value)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            BSTreeNode *temp = root;
            while (temp != NULL)
            {
                if (value == temp->data)
                {
                    return temp;
                }
                else if (value < temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    BSTreeNode *minValueNode(BSTreeNode *node)
    {
        BSTreeNode *current = node;
        while (current->left != NULL)
        {
            current = current->left; // traverses to the leftmost node in the right subtree to replace node with 2 childs in delete operation
        }
        return current;
    }

    BSTreeNode *deleteNode(BSTreeNode *r, int v)
    {
        if (r == NULL)
        {
            return r;
        }
        else if (v < r->data)
        {
            r->left = deleteNode(r->left, v);
        }
        else if (v > r->data)
        {
            r->right = deleteNode(r->right, v);
        }
        else
        {
            BSTreeNode *temp;
            if (r->left == NULL) // this node has either just a right child or no children
            {
                temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) // this node has only left child
            {
                temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
    }
};
int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << endl
             << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. printing traversal" << endl;
        cout << "3. searching a value" << endl;
        cout << "4. deleting a value" << endl;

        cin >> option;
        BSTreeNode *new_node = new BSTreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << endl
                 << "INSERT OPERATION" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->data = val;
            obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << endl
                 << "PRINTING BST :-" << endl;
            cout << "PRE-ORDER: ";
            obj.Preorder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.Inorder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.Postorder(obj.root);
            break;
        case 3:
            cout << endl
                 << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}