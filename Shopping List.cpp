// C++ program using class to process shopping list for a departmental store.
// The list include details such as code no and price of each item and 
//perform the operations like adding, deleting items to the list and printing the total value of an order.
#include<iostream>
#include<string.h>
using namespace std;
class Items
{
	private :
		char name[20][10];
		char code[20][10];
		float p[20];
		int q[20];	   
		
	public:		
		float total;
			
	int getdata(int i)
	{
		char n[20];
		cout<<"Enter the name of the item ";
		cin>>n;
		for(int j=0;j<i;j++)
		{
			if(stricmp(name[j],n)==0)
			{
				cout<<"The item already exist in the list. If you wanna modify the list, choose option 3. "<<endl;
				return 0;
			}
		}
		strcpy(name[i],n);
		cout<<"Enter the code ";
		cin>>code[i];
		cout<<"Enter the price of the item ";
		check1:
		cin>>p[i];
		if(p[i]<=0)
		{
		cout<<"Enter valid price (not negative). "<<endl;
		goto check1;			
		}		
		cout<<"Enter the quantity of the item ";
		check2:		
		cin>>q[i];
		if(q[i]<=0)
		{
		cout<<"Enter valid quantity (not negative). "<<endl;
		goto check2;			
		}		
		cout<<"The item is added to the list"<<endl;
		return 1;
		
	}
	int del(char n[10],int i)
	{
	    for(int j=0;j<i;j++)
		{
			if(stricmp(code[j],n)==0)
			{
			for(int k=j;k<i-1;k++)
			{
			strcpy(name[k],name[k+1]);
			strcpy(code[k],code[k+1]);
			p[k] =p[k+1];
			q[k] = q[k+1];
			}
			cout<<"The item is deleted from the list "<<endl;
			return 1;
		    }
	    }
	    cout<<"There is no such item in the list to be deleted"<<endl;
	    return 0;
	}
	int modify(char n[10],int i)
	{
		for(int j=0;j<i;j++)
		{
			if(stricmp(code[j],n)==0)
			{
				cout<<"Enter the modified price of the item ";
				check3:
				cin>>p[j];
				if(p[j]<=0)
				{
				cout<<"Enter valid price (not negative). "<<endl;
				goto check3;
				}
				cout<<"Enter the modified quantity of the item ";
				check4:
				cin>>q[j];
				if(q[j]<=0)
				{
				cout<<"Enter valid quantity (not negative). "<<endl;
				goto check4;
				}		
				cout<<"The item is modified in the list"<<endl;
				return 1;
			}
		}
		cout<<"The item doesnt exist in the list "<<endl;
		return 0;				
	}
	void display(int i)
	{
		if(i>0)
		{
			cout<<"Name\tCode\tQuantity\tPrice"<<endl;
		    for(int j=0;j<i;j++)
			cout<<name[j]<<"\t"<<code[j]<<"\t"<<q[j]<<"\t\t"<<p[j]<<endl;
		}
		else
		cout<<"The list is empty "<<endl;
		
	}
	void calculate(int i)
	{
		total = 0;
		for(int j=0;j<i;j++)
		{
			total+=p[j]*q[j];
		}
		cout<<"The total amount is : "<<total<<endl;
	}		
};

main()
{
	int i=0,ch,r;
	Items myList;
	char n[10];	
	bool quit=false;
	cout<<"Enter \n1 to add item to the list \n2 to delete item from the list \n3 to modify an existing item \n4 to display the current list \n5 to display the final bill \n6 to quit"<<endl;
	while(!quit)
	{
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			{
				r=myList.getdata(i);
				if(r==1)
				i++;
				break;
			}
		case 2:
			{
				if(i>0)
				{
				cout<<"Enter the code of the item to be deleted ";
				cin>>n;
				r= myList.del(n,i);
				if(r==1)
				i--;
				}
				else
				cout<<"The list is empty "<<endl;
				break;				
			}
		case 3:
			{
				if(i>0)
				{
					cout<<"Enter the code of item to be modified ";
				    cin>>n;
				    myList.modify(n,i);
				}
				else 
				cout<<"The list is empty "<<endl;
				break;
			}
		case 4:
			{
				myList.display(i);
				break;
			}
		case 5:
			{
				myList.display(i);
				myList.calculate(i);
				break;
			}
		case 6:
			{
				quit = true;
				break;
			}
		default:
			{
			cout<<"Wrong Choice "<<endl;
			break;
		    }
        }
    }
}
