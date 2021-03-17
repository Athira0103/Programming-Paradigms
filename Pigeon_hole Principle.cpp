#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int n,m;
	float t;
	cout<<"Enter the number of pigeons. "<<endl;
	cin>>n;
	cout<<"Enter the number of pigeon holes. "<<endl;
	cin>>m;
	if(n>m)
	{
		t=((float)(n-1)/m)+1;
	    cout<<"\nAtleast one pigeon hole must contain "<<ceil(t)<<" pigeons"<<endl;
	}
	else if(n==m)
	cout<<"The number of pigeons and holes are equal.Hence each hole will have one pigeon. ";
	else
	cout<<"The number of holes is more than pigeon. Hence only one pigeon needs to be accomodated in each hole and there will be empty holes too.";	
}
