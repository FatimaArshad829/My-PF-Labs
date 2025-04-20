#include<iostream>
using namespace std;
class Calculator
{
	public:
	float num1;
	float num2;
	public:
float add()
	{
		return num1+num2;
	}
	float subtract()
	{
		return num1-num2;
	}
	float multiple()
	{
		return num1*num2;
	}
	float divide()
	{
		if(num2!=0)
		{
		return num1/num2;
	}
		else{
		cout<<"Error:Division by zero!"<<endl;
	}
	}
};