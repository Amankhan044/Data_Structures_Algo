#include <iostream>
using namespace std;
void RowMajor(){
     
    int SizeofData=4;
  
           
    int Row, Column;
    cout << "Enter number of rows = ";
    cin >> Row;
    cout << "\nEnter number of columns = ";
    cin >> Column;
    cout<<endl;
    int Data[Row][Column];
    int TotalElement=Row*Column;
    for (int i = 0; i<Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            cout<<"Enter the elements sequentially :" ;
            cin >> Data[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Column; j++)
        {
            cout << "Array[" << i << "][" << j << "] =" <<
           Data[i][j] << endl;
        }
        
    }
    cout<<"Total Memory located "<<TotalElement*SizeofData<<endl;

	int *BaseAddress=&Data[0][0];
	int AddressData[Row][Column];
	int I[TotalElement];
	int S[TotalElement];
  
    int  Slot=0;
    for (int i = 0; i <TotalElement; i++)
    {
        int Product=1;
        for(int s=i+1;s<=TotalElement;s++)
		{
          Product=Product*S[s];
        
      	}
        Slot=Slot+I[i]*Product;
    }
    
    int k=0;
    while(k<TotalElement)
	{
      for(int i=0;i<Row;i++)
        {
          	for(int j=0;j<Column;j++)
		  	{
		        cout<<"Address of Data at through slot formula: "<< Data[i][j]<< " ";		
		        AddressData[i][j]=*BaseAddress+Slot*SizeofData;
		          cout<<AddressData[i][j]<<endl;
		          Slot++;
		          k++;
        	}
        }
    }
}
  
int main(){
    RowMajor();
	
    return 0;
} 
