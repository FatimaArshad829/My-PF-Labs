#include<iostream>
#include"Voter.h"
using namespace std;
	int main()
	{
		Voter v;
		v.setData();
		if(v.isEligible())
		{
			cout<<"You are eligible to vote."<<endl;
		}
		else{
			cout<<"You are not eligible to vote."<<endl;
		}
		return 0;
	}