#include<iostream>
using namespace std;

class StackUsingArray{
private:
  int top;
  int *stack;
  int size;
  
public:
StackUsingArray(){
    stack =new int [size];
    top=-1;
    size=5;
}

   void push(int x){
    if(top==size-1)
    {cout<<"stack overflow"<<endl;
    return;
   }
   else{top++;
   stack[top]=x;}
};
 void pop(){
    if(top==-1)
    {cout<<"stack underflow"<<endl;
    return;
   }
   else{top--;}
};
void display(){
   int i;
   for(int i=top ;i >=0;i--){
      cout<<stack[i]<<endl;
   }
}
 int peekTop(){
    if(top==-1){
         cout<<"stack underflow"<<endl;
         return 0;
    
   }else {
  return stack[top];}
};




};
int main(){
    StackUsingArray obj;
    obj.push(10);
    obj.push(30);
    obj.display();
    obj.pop();
    cout<<obj.peekTop()<<endl;
    obj.pop();
    cout<<obj.peekTop()<<endl;
    obj.push(5);
    cout<<obj.peekTop()<<endl;
    return 0;
    
     



}