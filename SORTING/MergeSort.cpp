#include <iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r){
    int i=l; //storing index for left subarray
    int j=m+1;  //storing index for right subarray
    int k=l;   //storing index for temporary
    const int size=r+l; // jitni array return ho rahi tou temp array ka bhi utna size hona chahiye
    // cout<<size<<" ";    // r sabse bari index ko show kar raha aur l sabse chotti ko  
    int temp[size];

    while(i<=m &&j<=r){
       if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
        k++;
       }
       else{
        temp[k]=arr[j];
        j++;
        k++;
       }
    }
    while(i<=m){
        temp[k]=arr[i];
        i++;
        k++;
    }
     while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }

    for(int s=l; s<=r; s++){
        arr[s]=temp[s];
    }


}

void MergeSort(int arr[], int l, int r){
   if(l<r){
    int m=(l+r)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    Merge(arr,l,m,r);
   }
}


int main()
{    
    // [13,2,12,1,15,8,9]
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    cout<<"Enter "<<size<<"  no of elements in the array: "<<endl;
    int myArray[size];
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
    MergeSort(myArray, 0 ,(size-1));
    cout <<endl<< "Elements after sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
    // cout<<0-1;
    return 0;
}