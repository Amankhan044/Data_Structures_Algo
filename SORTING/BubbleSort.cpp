#include <iostream>
using namespace std;

void BubbleSort(int a[])
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int myArray[5];
    cout << "Enter the elements of Array: " << endl;
    int a;
    for (int i = 0; i < 5; i++)
    {

        cin >> a;
        myArray[i] = a;
    }

    cout << "Elements before sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myArray[i] << " ";
    }

    BubbleSort(myArray);
    cout<<endl << "Elements after sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myArray[i] << " ";
    }
}