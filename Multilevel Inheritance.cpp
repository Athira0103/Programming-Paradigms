#include<iostream>
#include<string.h>
using namespace std;
class student
{ 
	long long int prn;
	char name[10],name2[20],batch[10],branch[20],div,grade;
	protected :
	void get_data()
	{
		cout<<"Enter student name(first and second name) ";
		cin>>name>>name2;
		cout<<"Enter student prn ";
		cin>>prn;
		fflush(stdin);
		cout<<"Enter student branch ";
		cin>>branch;
		fflush(stdin);
		cout<<"Enter student batch ";
		cin>>batch;
		cout<<"Enter student division ";
		cin>>div;
	}
		void displaydata()
	{
		cout<<"\nName : "<<name<<" "<<name2<<endl;
		cout<<"PRN : "<<prn<<endl;
		cout<<"Branch : "<<branch<<endl;
		cout<<"Batch : "<<batch<<"\nDivision : "<<div<<endl;
		
	}
};

class marks : protected student
{
	protected:
		float m[5],o[5];
		float percent;
		char grade;		
	public:	
	void getdata()
	{
		get_data();
		int x,i=0;
		while(i<=4)
		{
		cout<<"Enter student marks for subject "<<i+1<<" ";
		check:
		cin>>x;
		if(x>=0)
		m[i]=x;
		else 
		{
			cout<<"Enter valid marks (not negative) ";
			goto check;
		}
		cout<<"Enter out of marks ";
		cin>>o[i];
		m[i]=(m[i]/o[i])*100;
		i++;
		}
		
		
	}
	void calculate_perc()
	{
		int check =0;
		for(int i=0;i<5;i++)
		{
			if(m[i]<40)
			{
			grade = 'F';
			check=1;
			break;
		    }
		}
		if(check==0)
		{
		percent = (m[0]+m[1]+m[2]+m[3]+m[4])/5;
		if(percent >=90)
		grade = 'O';
		else if(percent>=80 && percent <90)
		grade = 'A';
		else if(percent>=70 && percent <80)
		grade = 'B';
		else if(percent>=60 && percent <70)
		grade = 'C';
		else if(percent>=50 && percent <60)
		grade = 'D';
		else 
		grade = 'P';		
	    }
	}
};

class result : public marks
{
	public:
	void display_data()
	{
		displaydata();
		if(grade=='F')
		{
			for(int i=0;i<=4;i++)
			{
				if(m[i]<40)
				cout<<"\nSubject "<<i+1<<" : Fail";
			}
			cout<<"\nYou have failed, better luck next time!"<<endl;
		}				
		else
		{
		cout<<"Congrats! You passed."<<endl;
		cout<<"Percentage : "<<percent<<"%"<<endl;
		cout<<"Grade : "<<grade<<endl;
	    }
	}	
};

main()
{
	result r;
	int n;
	cout<<"Enter the number of student results to be created ";
	check:
	cin>>n;
	if(n<0)
	{
		cout<<"Enter a valid number (not negative)";
		goto check;
	}
	cout<<"\nRESULTS: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"\nStudent "<<i+1<<" : \n";
		r.getdata();
		r.calculate_perc();
		r.display_data();
	}
}
