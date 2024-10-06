#include <iostream>
using namespace std;

void InsertionSort(int a[])
{
    int j = 0;
    int key;

    for (int i = 1; i < 5; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int myArray[5];
    cout << "Enter the elements of Array: " << endl;
    int b;
    for (int i = 0; i < 5; i++)
    {

        cin >> b;
        myArray[i] = b;
    }

    cout << "Elements before sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myArray[i] << " ";
    }

    InsertionSort(myArray);
    cout <<endl<< "Elements after sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myArray[i] << " ";
    }
    return 0;
}