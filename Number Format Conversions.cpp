#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int dtob(int);
int dtoO(int);
int dtoh(int);
int otod(int);
int btod(long);
int htod(char []);
	int x,n,c,d,j,o,an,a,k;
	int ar[20];
	    long no;
	    char h[10];
int main()
{
	check:
	an=0,a=0;
	cout<<"Enter : \n1 to convert decimal to all other formats \n2 to convert binary to all other formats \n3 to convert octal to all other formats \n4 to convert hexadecimal to all formats ";
	cout<<"\nEnter your choice ";
	cin>>c;
	    switch (c)
	    {
	    case 1:
		{
			cout<<"\nEnter the decimal number (without floating points) ";
			cin>>x;
			dtob(x);
			dtoO(x);
			dtoh(x);
		    break;
		}
		case 2:
		{
			cout<<"\nEnter the binary number (without floating points) ";
			cin>>no;
			k = btod(no);
			cout<<"\nThe decimal number is : "<<k;
			dtoO(k);
			dtoh(k);
			break;
		}
		case 3:
		{
			cout<<"\nEnter the octal number (without floating points) ";
			cin>>n;
			k= otod(n);
			cout<<"\nThe decimal number is : "<<k;	
			dtob(k);
			dtoh(k);	
			break;
		}
		case 4:
		{
			cout<<"\nEnter the hexadecimal number (without floating points) ";
			cin>>h;
			k = htod(h);
			cout<<"\nThe decimal number is : "<<k;
			dtob(k);
			dtoO(k);
			break;			
		}
		default:
			cout<<"\nWrong choice\n ";						
	}
	cout<<"\nDo you want to continue?";
		cout<<"\nIf 'yes'type 1. If 'no' type 0 \n";
		cin>>o;
		if(o==1)
		goto check;	
				
}
int dtob(int n)
    {
    a=0;
	while(n>0)
		{
			d=n%2;
			ar[a]=d;
			n=n/2;
			a++;
		}
	cout<<"\nThe binary number is : ";
	for(j=a-1;j>=0;j--)
	cout<<ar[j]; 			   
	}
int dtoO(int n)
    {
	a=0;
	while(n>0)
	{
		d=n%8;
		ar[a]=d;
		n=n/8;
		a++;
	}		    
	cout<<"\nThe octal number is : ";
	for(j=a-1;j>=0;j--)
	cout<<ar[j];			
	}
	
int dtoh(int n)
    {
	a=0;
	while(n>0)
	{
		d=n%16;
		ar[a]=d;
		n=n/16;
		a++;				
    }		    
	cout<<"\nThe hexadecimal number is : ";
	for(j=a-1;j>=0;j--)
	{
		if(ar[j]>=10)
		cout<<(char)(ar[j]+55);
		else
        cout<<ar[j];
    }
    }
    
int btod(long no)
    {
	    while(no>0)
	    {
			d=no%10;
		    an=an+(d*pow(2,a));
			no=no/10;
			a++;
		}
		return(an);
	}
	
int otod(int no)
	{
	    while(no>0)
		{
		    d=no%10;
			an=an+(d*pow(8,a));
			no=no/10;
			a++;
		}
		return (an);
	}
	
int htod(char h[])
	{
		int l,i=0;
		l=strlen(h);
		for(a=l-1,i=0;a>=0;a--,i++)
		{
			if((h[a]>=48)&&(h[a]<=57))
			d=h[a]-48;
			else
			d=h[a]-55;
			an=an+(d*pow(16,i));				
		}
		return (an);
			
	}
