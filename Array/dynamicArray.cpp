#include<iostream>
using namespace std;


int main()
{
    int size;
    cout<<"enter the size of Array"<<endl;

    cin>>size;
    int *dynamicArray;
    dynamicArray=new int[size];

    // To store the elements in the dynamicarray
    for(int i=0; i<size; i++){
        cout<<"Enter Element: ";
        cin>>dynamicArray[i];
        cout<<endl;
    }
    // to print the array in terminal
        cout<<"The elements are:"<<endl;

    for (int i=0; i<size; i++){
        cout<<dynamicArray[i]<<endl;
    }

    delete[] dynamicArray;
    return 0;
}