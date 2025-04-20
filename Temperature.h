#include<iostream>
using namespace std;
class Temperature
{
	public:
	double celsius;
	public:
		double inFahrenheit()
		{
			return (celsius*9/5) + 32;
        }
        void display()
        {
        	double Fahrenheit = inFahrenheit();
        	cout<<"Temperature in Fahrenheit: "<<Fahrenheit<<endl;
		}
};