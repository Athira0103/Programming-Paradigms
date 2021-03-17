#include<iostream>
using namespace std;
int ch = 0;
int cs = 0;
class Item
{
	protected:
		char Title[10][20];
		float Price[10];
	public:
		virtual void get_data() = 0;
		virtual void display_data() = 0;
};

class Sales
{
        protected:
		int ts, s[10][3];
		void get_sales(int count)
		{
			cout<<"Enter Sales for three months. \n";
			for(int i=0;i<3;i++)
			{
				cout<<"Month "<<i+1<<" : ";
				cin>>s[count][i];
			}
		}
		int display_sales(int count)
		{
			ts=0;
			for(int i=0;i<3;i++)
			ts+=s[count][i];
			cout<<"\nTotal Sales : "<<ts;
			return ts;		
		}		
};
class hwitem : public Item , protected Sales
{
	private:
		int n;
	public:
		void get_data()
		{
			cout<<"\nEnter the total number of Hardware items: ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				if(i<=ch)
				{
					cout<<"\nItem "<<i+1;
				    cout<<"\nEnter the product name: ";
			        fflush(stdin);
		            cin>>Title[ch];	        	
			        cout<<"Enter Price: ";
			        cin>>Price[ch];			        
			        get_sales(ch);
			        ch++;
				}				
			}			
		}
		
		void display_data()
		{
			cout<<"\nHardware Items : ";
			for(int i=0;i<ch;i++)
			{
				cout<<"\nItem "<<i+1<<" : ";
				cout<<"\nProduct Name : "<<Title[i]<<"\nPrice : "<<Price[i];
			    int k = display_sales(i);
			    cout<<"\nTotal Amount : "<<Price[i]*k<<endl;
			}			
		}
};

class switem : public Item , protected Sales
{
	private:
		int q[10],n;
	public:
		void get_data()
		{
			cout<<"\nEnter the total number of Software items: ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				if(i<=cs)
				{
					cout<<"\nItem "<<i+1;
				    cout<<"\nEnter the product name: ";
			        fflush(stdin);
		            cin>>Title[cs];	        	
			        cout<<"Enter Price: ";
			        cin>>Price[cs];			        
			        get_sales(cs);
			        cs++;
				}				
			}			
		}
		
		void display_data()
		{
			cout<<"\nSoftware Items : ";
			for(int i=0;i<cs;i++)
			{
				cout<<"\nItem "<<i+1<<" : ";
				cout<<"\nProduct Name : "<<Title[i]<<"\nPrice : "<<Price[i];
			    int k = display_sales(i);
			    cout<<"\nTotal Amount : "<<Price[i]*k<<endl;
			}
		}
};

main()
{
	Item *I;
	hwitem h;
	switem s;
	int c;
	bool quit = false;
	cout<<"Choose the category of items to be added to the list. "<<"\n1. Hardware Items. "<<"\n2. Software Items. "<<"\n PRESS 3 to quit.";
	while(!quit)
	{		
		cout<<"\n\nEnter your choice: ";
		cin>>(c);
		switch(c)
		{
			case 1:
				{
				I=&h;
				I->get_data();
				I->display_data();
				break;				
				}
			case 2:
				{
				I=&s;
			    I->get_data();
			    I->display_data();
				break;	
				}
			case 3:
			    {
				quit=true;
				break;
			    }
			default:
				cout<<"\nWRONG CHOICE. ";
		}
	}
}
