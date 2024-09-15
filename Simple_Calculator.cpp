#include<iostream>
using namespace std;

int main()
{
  int num1;
  int num2;
  int op;
  
  cout<<"Enter 1st number:";
  cin>>num1;
  
  cout<<"Enter 2nd number:";
  cin>>num2;
  
  cout<<"Choose the operation:\n";
  cout<<" 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n";
  cin>>op;
  
  switch(op)
  {
    case 1:
     cout<<(num1+num2);
     break;
     
    case 2:
     cout<<(num2-num1);
     break;

    case 3:
     cout<<(num1*num2);
     break;
    
    case 4:
       cout<<(num2/num1);
       break;
     
     
     default:
       cout<<"Invalid Choice...";
       break;
  }
  
}