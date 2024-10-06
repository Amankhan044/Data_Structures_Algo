#include<iostream>
using namespace std;


int main()
{
    int array[40],SIZE,i;
    cout<<"Enter the size of array:"<<endl;
    cin>>SIZE;
    cout<<"Enter the elements of  array :"<<endl ;
    for (i=0; i<SIZE; i++)
    {
        cin>>array[i];
    }
    cout<<"Elements of  array are : "<<endl;
    for(i=0; i<SIZE;i++)
    {
        cout<<array[i];
    }

}