#include<iostream>
using namespace std;
class polygon
{
	protected:
		float w,h,ar;
	public:
		virtual void area()=0; 
		virtual void set_values()=0;
};

class rectangle: public polygon
{
	public:
		void set_values()
		{
			cout<<"\nDetails of the rectangle :";
			cout<<"\nEnter the length of the rectangle ";
			cin>>h;
			cout<<"Enter the breadth of the rectangle ";
			cin>>w;
		}
		void area()
 	    {
			ar = h*w;
			cout<<"Area of the rectangle is : "<<ar<<endl;
			cout<<"\n";
		}
};

class triangle: public polygon
{
	public:
		
		void set_values()
	    {
			cout<<"\nDetails of the triangle :";
			cout<<"\nEnter the height of the triangle ";
			cin>>h;
			cout<<"Enter the width of the triangle ";
			cin>>w;
		}
		void area()
		{
			ar = (h*w)/2;
			cout<<"Area of the triangle is : "<<ar<<endl;
			cout<<"\n";
		}
	
};

main()
{
	int ch;
	polygon *p;
	triangle t;
	rectangle r;
	bool quit = false;
	while(!quit)
	{
		cout<<"To calculate area of given shapes. Enter :\n1.Triangle \n2.Recangle \n3.Quit ";
		cout<<"\nEnter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					p=&t;
					p ->set_values();
					p ->area();
					break;
				}
			case 2:
				{
					p=&r;
					p ->set_values();
					p ->area();
					break;
				}
			case 3:
				{
					quit = true;
					break;
				}
			default:
				cout<<"Wrong choice "<<endl;
		}		
	}
}
