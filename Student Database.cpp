//  Variable - PRN,Name,Batch,Branch,Division,5 subj1,subj2,subj3,subj4,subj5
// Methods -  getData(),displyadata(),calculatePerc()
#include<iostream>
#include<string.h>
using namespace std;
class student
{
	long long int prn;
	char name[10],name2[20],batch[10],branch[20],div,grade;
	public :
	float m[5],o[5];
	float percent;
	void getdata()
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
		for(int i=0;i<5;i++)
		{
			cout<<"Enter student marks of subject "<<i<<" : "<<endl;
			cin>>m[i];
			cout<<"Enter total marks of subject "<<i<<" : "<<endl;
			cin>>o[i];
			m[i]=(m[i]/o[i])*100;
		}
	}
	
	void displaydata()
	{
		cout<<"\nName : "<<name<<" "<<name2<<endl;
		cout<<"PRN : "<<prn<<endl;
		cout<<"Branch : "<<branch<<endl;
		cout<<"Batch : "<<batch<<"\nDivision : "<<div<<endl;
		
	}
	void calculatePerc()
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
		percent = (m[0]+m[1]+m[2]+m[3]+m[4])/(float)5;
		if(percent >=90)
		grade = 'O';
		else if(percent>=80)
		grade = 'A';
		else if(percent>=70)
		grade = 'B';
		else if(percent>=60)
		grade = 'C';
		else if(percent>=50)
		grade = 'D';
		else 
		grade = 'P';		
	    }
	
	    if(grade=='F')
	    cout<<"You have failed, better luck next time!"<<endl;		
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
	int n;
	student s[50];
	cout<<"Enter the number of student records to be created ";
	cin>>n;
	if(n>0 && n<=50)
	{
		for(int i=0;i<n;i++)
	    {	
		cout<<"\nStudent "<<i+1<<":"<<endl;
		s[i].getdata();		
		s[i].displaydata();
		s[i].calculatePerc();
		}
	}
	else if(n>50)
	cout<<"Maximum 50 entries allowed "<<endl;
	else 
	cout<<"No valid entries allowed "<<endl;	
}
