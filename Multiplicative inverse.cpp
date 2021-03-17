#include<iostream>
using namespace std;
main()
{
	int a,b,r,gcd,x,y,t1,t2;
	cout<<"Enter the number of which the multiplicative inverse is to be found ";
	cin>>b;
	cout<<"Enter the mod number ";
	cin>>a;
	t1=a;
	t2=b;	
	while(t1%t2!=0)
		{
			r=t1%t2;
			t1=t2;
			t2=r;			
		}
	gcd=t2;
	cout<<"\nGCD : "<<gcd;
	if(gcd==1)
	{
		for(x=1;;x++)
		{
			if((a*x)%b == 1)
			{
				y=(a*x)/b;
				cout<<"\n"<<a<<" : "<<x<<"\n"<<b<<" : "<<y;
				y=a-y;				
				cout<<"\nThe multiplicative inverse of "<<b<<" mod ("<<a<<") is : "<<y;
				break;
			}
		}		
	}
	else
	cout<<"\nGCD is not equal to 1, hence cannot find multiplicative inverse ";
}
