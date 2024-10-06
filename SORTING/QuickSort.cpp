#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pindex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pindex];
    arr[pindex] = temp;
    return pindex;
}

void QuickSort(int arr[], int s, int e)
{

    if (s < e)
    {
        int p = partition(arr, s, e);
        QuickSort(arr, s, (p - 1));
        QuickSort(arr, (p + 1), e);
    }
}

int main()
{
    int size;
    cout << "Enter the size of array:  ";
    cin >> size;
    int myArray[size];
    cout << "Enter the elements of Array: " << endl;
    int b;
    for (int i = 0; i < size; i++)
    {

        cin >> b;
        myArray[i] = b;
    }

    cout << "Elements before sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    QuickSort(myArray, 0, (size - 1));
    cout << endl
         << "Elements after sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
    return 0;
}