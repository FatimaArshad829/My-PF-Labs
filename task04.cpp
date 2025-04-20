#include<iostream>
#include"Temperature.h"
using namespace std;
int main()
{
	Temperature temp;
	cout<<"Enter temperature:";
	cin>>temp.celsius;
	temp.display();
	return 0;
}