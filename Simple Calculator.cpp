//Simple Calculator

#include<iostream>
using namespace std;
int main()
{
	double a,b;
	char op;
	cout<<"\n Enter the two numbers = ";
	cin>>a>>b;
	
	cout<<"\n Enter an operator" "\n" "(+, -, *, /): ";
    cin>>op;
    
    switch(op) 
	{
        case '+':
            cout<<"\n Addition = "<<a+b;
            break;
        case '-':
            cout<<"\n Subtraction = "<<a-b;
            break;
        case '*':
            cout<<"\n Multiplication = "<<a*b;
            break;
        case '/':
            if (b!= 0)
                cout<<"\n Division = "<<a/b;
            else
                cout<<"\n Error! Can't divided by zero.";
            break;
        default:
            cout<<"\n Error! Please Enter valid operator.";
            break;
    }
}
