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

class marks : public student
{
	protected:
		float m[5],o[5];
			
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
	
};

class sports
{
	protected:
	int spmarks;
	public:
	void getsports()
	{
	cout<<"Enter sports mark (out of 100): ";
	check1:
	int x;
	cin>>x;
	if(x>=0)
	spmarks=x;
	else
	{
		cout<<"Enter valid mark ( not negative ) ";
		goto check1;
	}
	}
	
};

class result : public marks, public sports
{
	private:
		float total, total_s;
		float percent,percent_s;
		char grade;	
	public:
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
		total=m[0]+m[1]+m[2]+m[3]+m[4];
		total_s=m[0]+m[1]+m[2]+m[3]+m[4]+spmarks;
		percent = (total)/5;
		percent_s = (total_s)/6;
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
			cout<<"You have failed, better luck next time!"<<endl;
		}
				
		else
		{
		cout<<"Congrats! You passed."<<endl;
		cout<<"Total marks (without sports) : "<<total<<endl;
		cout<<"Percentage (without sports) : "<<percent<<"%"<<endl;
		cout<<"Grade (without sports): "<<grade<<endl;
		cout<<"Total marks (with sports) : "<<total_s<<endl;
		cout<<"Percentage (with sports) : "<<percent_s<<"%"<<endl;
	    }
	}	
	
};

main()
{
	result r;
	int n;
	cout<<"Enter the number of student results to be created ";
	check2:
	cin>>n;
	if(n<0)
	{
		cout<<"Enter valid number ( not negative ) ";
		goto check2;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"\nStudent "<<i+1<<" : \n";
		r.getdata();
		r.getsports();
		r.calculate_perc();
		r.display_data();
	}
}


