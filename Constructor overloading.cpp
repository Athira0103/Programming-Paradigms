//Assignment 7  - C++ Program using Class  to perform addition of two complex numbers using the concept of constructor overloading and friend function.
#include<iostream>
#include<math.h>
using namespace std;
class complex
{	
	int real,img;
	public:
	friend void add(complex c1,complex c2);
	complex()
	{
	}	
	
	complex(int r)
	{
		real = r;
		img = r;
	}
	
	complex(int r,int i)
	{
		real = r;
		img = i;
	}
	
	complex(complex &c)
	{
		real = c.real;
		img = c.img;
	}
	
	void print()
	{
		cout<<real;
		if(img>=0)
		cout<<" + "<<img<<"i"<<endl;
		else
		cout<<" - "<<abs(img)<<"i"<<endl;
	}
		
};
void add(complex c1,complex c2)
{
	complex c4;
	c4.real = c1.real+c2.real;
	c4.img = c1.img+c2.img;
	cout<<"The sum is : ";
	c4.print();	
}

main()
{
	int n,m,o,p;	
	cout<<"Enter the real and imaginary values of 1st complex number. "<<endl;
	cin>>n>>m;
	complex c1(n,m);
	cout<<"Enter the real and imaginary values of 2nd complex number. "<<endl;
	cin>>o>>p;
	complex c2(o,p);
	cout<<"First number : ";
	c1.print();
	cout<<"Second number : ";
	c2.print();	
	complex c3(c1);
	cout<<"Third number : ";
	c3.print();
	add(c2,c3);	
}
