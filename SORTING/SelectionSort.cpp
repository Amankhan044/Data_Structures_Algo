#include <iostream>
using namespace std;

void SelectionSort(int a[])
{
    int i, min;
    for (int i = 0; i < 4; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
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

    SelectionSort(myArray);
    cout <<endl<< "Elements after sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myArray[i] << " ";
    }
    return 0;
}