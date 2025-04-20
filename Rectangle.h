#include<iostream>
using namespace std;
 class Rectangle
{
	public:
	int length;
	int width;
	public:
	void setDimensions();
	int area();
	int perimeter();
};
    void Rectangle::setDimensions()
    {
    	cout<<"Enter the length:";
    	cin>>length;
    	cout<<"Enter the width:";
    	cin>>width;
	}
	int Rectangle::area()
	{
	return length*width;
	}
	int Rectangle::perimeter()
	{
		return 2*(length+width);
	}