#include<iostream>
#include"Rectangle.h"
using namespace std;
	int main()
	{
		Rectangle r1;
		r1.setDimensions();
		cout<<"Area:"<<r1.area()<<endl;
		cout<<"Perimeter:"<<r1.perimeter()<<endl;
		return 0;
	}