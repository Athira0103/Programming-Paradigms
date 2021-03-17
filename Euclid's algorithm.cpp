#include<iostream>
using namespace std;
main()
{
	int a,b,t1,t2,r,q;
	cout<<"Enter the dividend ";
	cin>>a;
	cout<<"Enter the divisor ";
	cin>>b;	
	t1=a;
	t2=b;
	cout<<"\n";
	if(a>=b)
	{
		while(a%b!=0)
		{
			cout<<"GCD of ("<<a<<","<<b<<") = ";
			r=a%b;
			q=a/b;
			cout<<b<<"("<<q<<")"<<" + "<<r<<" = ";
			a=b;
			b=r;
			cout<<"GCD of ("<<a<<","<<b<<")"<<endl;			
		}
		cout<<"GCD of ("<<a<<","<<b<<") = ";
		r=a%b;
		q=a/b;
		cout<<b<<"("<<q<<")"<<" + "<<r<<endl;
		cout<<"\nGCD of ("<<t1<<","<<t2<<") = "<<b;
	}
	else
	cout<<"Dividend is less than divisor "<<endl;
}
