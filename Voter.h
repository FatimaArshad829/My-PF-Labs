#include<iostream>
using namespace std;
class Voter
{
	public:
	string name;
	int age;
	public:
	void setData();
	bool isEligible();
};
    void Voter::setData()
    {
    	cout<<"Enter the name:";
    	cin>>name;
    	cout<<"Enter the age:";
    	cin>>age;
	}
	bool Voter::isEligible()
	{
		return age>18;
	}