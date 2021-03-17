#include<iostream>
using namespace std;
class Value{
    int v;
    public:
      friend istream& operator >> (istream&,Value&);
      friend ostream& operator << (ostream&,Value&);
      bool operator < (Value&);
};
istream & operator >> (istream &i,Value &value)
 {
     i>>value.v;
     return i;
 }
 ostream & operator << (ostream &o,Value &value)
 {
     o<<value.v;
     return o;
 }

 bool Value::operator < (Value &value)
 {
    if(v<value.v)
      return true;
    else
      return false;
 }

 int main()
 {
 	 cout<<"Program to check smallest number among 2 numbers ";
     Value a,b;
     cout<<"\n\nEnter first and second number : ";
     cin>>a>>b;
     if(a<b)
	    cout<<a<<" is less than "<<b;
     else
	    cout<<b<<" is less than "<<a;
    return 0;
 }
 
 PP Lab Assignment 8: Write a C++ menu driven program to implement unary
operator overloading (prefix and postfix increment operator) and binary
operator overloading (+ and <).
Menu:
Press 1 to apply prefix increment operator on the object of class complex
Press 2 to apply postfix increment operator on the object of class complex
Press 3 to add two objects of class complex (using friend function)
Press 4 to compare two complex numbers using< ; operator
Overloading unary operator using member function:
Return_type operator op (arg list)
{
}
Operator overloaded functions can be invoked by expressions:
op x;
Or
x op;
Overloading unary operator using friend function:
friend return_type operator op (class_name &amp;obj_name);
Binary operator overloading to add two complex numbers using member
function:
complex operator +(complex m)
{
complex temp;
temp.real=real+m.real;
temp.imag=imag+m.imag;
return (temp);
}
Operator overloaded functions can be invoked by expressions:
c3=c1+c2; //c1,c2,c3 are objects of class complex, this statement is equivalent to c3=c1.operator+(c2);

Binary operator overloading to add two complex numbers using friend
function:

Friend function can also be used in place of member functions for overloading
a binary operator, the only difference being that a friend function requires two
arguments to be explicitly passed to it, while a member function requires only
one.
In the complex number program discussed in the previous section, the
statement:
c3=c1+c2;
is equivalent to:
c3= operator+(c1,c2);
Binary operator overloading to compare two complex numbers using
member function:
bool operator < (complex c)
{…
…
}

Operator overloaded functions can be invoked by expression like:
If (c1<c2) // c1 and c2 are the objects

