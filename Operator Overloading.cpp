#include<iostream>
#include<math.h>
using namespace std;  
class Complex 
{ 
private: 
    float real, img; 
public:
	friend Complex operator + (Complex &c1, Complex &c2); 
    Complex()
	{
	}
	
	Complex(float r, float i) 
	{
		real = r;
		img = i;
	} 
	
    void operator ++()
	{
		++real;
		++img;
		cout<<"The complex number after pre-increment is : ";
	}
	
	void operator ++(int)
	{
		real++;
		img++;
		cout<<"The complex number after post-increment is : ";
	}
	bool operator < (Complex c)
	{
		int a,b;
		a=real*real + img*img;
		b=c.real*c.real + c.img*c.img;
		if(a>b)
		return false;
		else if(a==b)
		{
			if(real>c.real)
			return false;
			else 
			return true;
		}
		else
		return true;
	}

    void print() 
	{ 
	cout<<real;
	if(img>=0)
	cout<<" + "<<img<<"i" <<endl;
	else
	cout<<" - "<<abs(img)<<"i" <<endl;
	} 
}; 

Complex operator + (Complex &c1, Complex &c2)
{
	Complex c4;
	c4.real = c1.real+c2.real;
	c4.img = c1.img+c2.img;
	cout<<"\nThe sum is : ";
	return c4;
} 
 
int main() 
{
	int ch;
	float r,i,r1,i1;
	bool quit = false;
	while(!quit)
	{
		cout<<"\nEnter \n1.To pre-increment a complex number \n2.To post-increment a complex number \n3.To add 2 complex numbers \n4.To compare 2 complex numbers \n5.To quit. ";
	    cin>>ch;
	    switch (ch)
	    {
	    	case 1:
	    		{
	    			cout<<"\nEnter the real and imaginary part of the given complex number ";
	    			cin>>r>>i;
	    			Complex c1(r, i),c2;
	    			cout<<"The given complex number is : ";
	    			c1.print();
	    			++c1;
	    			c1.print();
	    			break;
				}
			case 2:
				{
					cout<<"\nEnter the real and imaginary part of the given complex number ";
	    			cin>>r>>i;
	    			Complex c1(r, i),c2;
	    			cout<<"The given complex number is : ";
	    			c1.print();
	    			c1++;
	    			c1.print();
	    			break;
				}
					
			case 3:
				{
					cout<<"\nEnter the real and imaginary part of first complex number ";
	    			cin>>r>>i;
	    			cout<<"Enter the real and imaginary part of second complex number ";
	    			cin>>r1>>i1;
	    			Complex c1(r, i),c2(r1,i1);
	    			cout<<"\nFirst complex number is : ";
	    			c1.print();
	    			cout<<"Second complex number is : ";
	    			c2.print();	    			
	    			Complex c3 = c1+c2;
	    			c3.print();
	    			break;
				}
			case 4:
				{
					cout<<"\nEnter the real and imaginary part of first complex number ";
	    			cin>>r>>i;
	    			cout<<"Enter the real and imaginary part of second complex number ";
	    			cin>>r1>>i1;
	    			Complex c1(r, i),c2(r1,i1);
	    			cout<<"\nFirst complex number is : ";
	    			c1.print();
	    			cout<<"Second complex number is : ";
	    			c2.print();	
					if(c1<c2)
					cout<<"\nSecond number is greater than first number\n";
					else
					cout<<"\nFirst number is greater than second number\n";   			
					break;
				}
			case 5:
				{
					cout<<"Quitting the program ";
					quit=true;
					break;
				}
			default:
				cout<<"Wrong Choice ";
		}
	}
} 
