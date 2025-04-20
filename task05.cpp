#include<iostream>
#include"Calculator.h"
using namespace std;
int main()
{
	Calculator cal;
	char op;
	cout<<"Enter two numbers:";
	cin>>cal.num1>>cal.num2;
	cout<<"\nEnter an operation to perform (+,-,*,/):";
	cin>>op;
	switch(op)
	{
		case'+':
			cout<<"Sum:"<<cal.add();
			break;
		case'-':
			cout<<"Difference:"<<cal.subtract();
			break;
		case'*':
			cout<<"Multiplication:"<<cal.multiple();
			break;
		case'/':
			if(cal.num2==0)
			{
				cout<<"Invalid";
			}
			else
			{
				cout<<"Divide:"<<cal.divide();
			}
			break;
			default:
				cout<<"Invalid operation.";
	}
	return 0;
}