#include<iostream>
using namespace std;
class Product
{
	private:
		string name;
		double price;
		int quantity;
	public:
		void setName(string n)
		{
			if(!n.empty()){
				name=n;
			}else
			{
				cout<<"Invalid name.It cannot be empty."<<endl;
			}
		}
		void setPrice(double p){
			if(p>0){
				price=p;
			}else{
				cout<<"Invalid price.It must be greater than 0."<<endl;
			}
		}
		void setQuantity(int q)
		{
			if(q>=0){
				quantity=q;
			}else
			{
				cout<<"Invalid quantity.It must be 0 or more."<<endl;
			}
		}
		string getName()
		{
			return name;
		}
		int getQuantity()
		{
			return quantity;
		}
		double getPrice()
		{
			return price;
		}
};