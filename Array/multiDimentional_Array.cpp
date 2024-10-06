#include <iostream>
using namespace std;

int main()
{
    int arr[2][3];
    int i, j;
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }


    cout << " the elements of the array are: "<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j];
        }
    }
}

// Two dimentional array
// int main()
// {
//     int array[2][3]={{1,2,3},{4,5,6}};
//     int i,j;
//     for(int i=0; i<2; i++){
//         for(int j=0; j<3;j++){
//             cout<<"The array is: "<<array[i][j]<<endl;
//         }
//     }
//     return 0;
// }

// Three dimentional array
// int main()
// {
//     int array[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}};
//     int i, j, k;
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             for (int k = 0; k < 4; k++)
//             {
//                 cout << "The array is: " << array[i][j][k] << endl;
//             }
//         }
//     }
//     return 0;
// }