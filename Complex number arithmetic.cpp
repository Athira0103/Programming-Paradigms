#include<iostream>
#include<math.h>
using namespace std;
typedef struct complex
{
	int real;
	int imaginary;
}Complexn;
void print(float r, float i);
int sub(int,int,int,int);
int multiply(int,int,int,int);
int divide(int,int,int,int);
int add(int,int,int,int);
int r,i;
int main()
{
	check:
	Complexn c1,c2;
	cout<<"\nEnter real part of first complex number ";
	cin>>c1.real;
	cout<<"Enter imaginary part of first complex number ";
	cin>>c1.imaginary;
	cout<<"\nFirst Number : ";
	print(c1.real,c1.imaginary);
	cout<<"\nEnter real part of second complex number ";
	cin>>c2.real;
	cout<<"Enter imaginary part of second complex number ";
	cin>>c2.imaginary;	
	cout<<"\n\nSecond Number : ";
	print(c2.real,c2.imaginary);
	add(c1.real,c2.real,c1.imaginary,c2.imaginary);
	sub(c1.real,c2.real,c1.imaginary,c2.imaginary);
	multiply(c1.real,c2.real,c1.imaginary,c2.imaginary);
	divide(c1.real,c2.real,c1.imaginary,c2.imaginary);	
	cout<<"\nDo you want to continue?"<<endl<<"If yes, press 1 else press any other key "<<endl;
	int o;
	cin>>o;
	if(o==1)
		goto check;	
}
int add(int r1,int r2,int i1,int i2)
{
	r=r1+r2;
	i=i1+i2;
	cout<<"\nThe resultant complex number after addition is : ";
	print(r,i);
}
int sub(int r1,int r2,int i1,int i2)
{
	r=r1-r2;
	i=i1-i2;
	cout<<"The resultant complex number after subtraction is : ";
	print(r,i);
}
int multiply(int r1,int r2,int i1,int i2)
{
	r=r1*r2 - i1*i2;
	i=r1*i2 + r2*i1;
	cout<<"The resultant complex number after multiplication is : ";
	print(r,i);
}
int divide(int r1,int r2,int i1,int i2)
{
	if(r2!=0 || i2!=0)
	{
		float r=(float)(r1*r2 + i1*i2)/(float)(r2*r2 + i2*i2);
		float i = (float)(r2*i1 - r1*i2)/(float)(r2*r2 + i2*i2);
		cout<<"The resultant complex number after division is : ";
		print(r,i);
	}
	else 
	cout<<"Division not possible!"<<endl;
}
void print(float r,float i)
{
	cout<<r;
	if(i>=0)
	cout<<" + "<<i<<"i"<<endl;
	else
	cout<<" - "<<abs(i)<<"i"<<endl;
}
