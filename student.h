#include<iostream>
using namespace std;
class Student
{
	public:
	int rollNumber;
	string name;
	float marks;
	public:
	void getData()
	{
		cout<<"Enter student name:"<<endl;
		cin>>name;
		cout<<"Enter student marks:"<<endl;
		cin>>marks;
		cout<<"Enter student rollNumber:"<<endl;
		cin>>rollNumber;
	}
	void displayData()
	{
		cout<<"\nStudent information:"<<endl;
		cout<<"Name:"<<name<<endl;
		cout<<"rollNumber:"<<rollNumber<<endl;
		cout<<"marks:"<<marks<<endl;
	}
};