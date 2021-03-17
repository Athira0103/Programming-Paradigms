#include<iostream>
using namespace std;
int count =0;
class Person
{
	protected:
		char name[50][20], dept[50][15], id[50][15];
	public:
		virtual void getdata() = 0;
		virtual void display() = 0;
};

class Employee : public Person
{
	public:
		float salary[50];
		char job[50][30];
		int n;
		void getdata()
		{
			cout<<"Enter the number of employee records : ";
			cin>>n;
			if((count+n)<50)
			{
				for(int i=0;i<n;i++)
			    {
				cout<<"\nEnter the Name of Employee "<<i+1<<": ";
				cin>>name[i];
				cout<<"Enter Employee ID : ";
				cin>>id[i];
				cout<<"Enter the department : ";
				cin>>dept[i];
				cout<<"Enter the Job : ";
				cin>>job[i];
				cout<<"Enter salary: ";
				cin>>salary[i];
				count++;
			    }
			}			
		}
		
		void display()
		{
		    cout<<"\nEMPLOYEE DETAILS : ";
			for(int i=0;i<n;i++)
			{
				cout<<"\n\nEMPLOYEE"<<i+1<<" : ";
				cout<<"\nName : "<<name[i];
				cout<<"\nEmp_ID : "<<id[i];
				cout<<"\nDepartment : "<<dept[i];
				cout<<"\nJob : "<<job[i];
				cout<<"\nSalary : "<<salary[i];
			}
    	}
};

class Student : public Person
{
	public:
		float percent[50];
		int n;
		void getdata()
		{
			cout<<"Enter the number of student records : ";
			cin>>n;
			if((count+n)<50)
			{
				for(int i=0;i<n;i++)
			    {
				cout<<"\nEnter the Name of Student "<<i+1<<": ";
				cin>>name[i];
				cout<<"Enter Student ID : ";
				cin>>id[i];
				cout<<"Enter the Student department : ";
				cin>>dept[i];
				cout<<"Enter Student percentage : ";
				cin>>percent[i];
				count++;
			    }
			}			
		}
		
		void display()
		{
		    cout<<"\nSTUDENT DETAILS : ";
			for(int i=0;i<n;i++)
			{
				cout<<"\n\nSTUDENT"<<i+1<<" : ";
				cout<<"\nName : "<<name[i];
				cout<<"\nStudent_ID : "<<id[i];
				cout<<"\nDepartment : "<<dept[i];
				cout<<"\nPercentage : "<<percent[i];
			}
    	}
};

main()
{
	Person *p;
	Employee e;
	Student s;
	int c;
	bool quit = false;
	cout<<"Type of personal records to be entered. "<<"\n1.Employee details "<<"\n2.Student details"<<"\nPRESS 3 to quit.";
	while(!quit)
	{		
		cout<<"\n\nEnter your choice: ";
		cin>>(c);
		switch(c)
		{
			case 1:
				{
				p=&e;
				p->getdata();
				p->display();
				break;				
				}
			case 2:
				{
				p=&s;
			    p->getdata();
			    p->display();
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

