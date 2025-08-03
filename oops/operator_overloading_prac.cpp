#include<iostream>
using namespace std;
class invert_position
{
    int x,y;
    public:
        invert_position(int a,int b)
        {
        x=a;
        y=b;
        }
    void show()
        {
            cout<<"\nx="<<x;
            cout<<"\ny="<<y;
        }
    friend void operator -(invert_position&); //you need to pass by reference if you want updation in your object
};
void operator -(invert_position &i)
{
    i.x=-i.x;
    i.y=-i.y;
}
int main()
{
    invert_position i(2,3);
    -i;
    i.show();
    return 0;
}



// CPP program to demonstrate 
// Overloading new and delete operator 
// for a specific class
#include<iostream>
#include<stdlib.h>

using namespace std;
class student
{
	string name;
	int age;
public:
	student()
	{
		cout<< "Constructor is called\n" ; 
	}
	student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void display()
	{
		cout<< "Name:" << name << endl;
		cout<< "Age:" << age << endl;
	}
	void * operator new(size_t size)
	{
		cout<< "Overloading new operator with size: " << size << endl;
		void * p = ::operator new(size); 
		//void * p = malloc(size); will also work fine
	
		return p;
	}

	void operator delete(void * p)
	{
		cout<< "Overloading delete operator " << endl;
		free(p);
	}
};

int main()
{
	student * p = new student("Yash", 24);
	p->display();
	delete p;
}


#include <iostream>
using namespace std;
class sarray
{ 
int arr[10]; 
public: sarray() 
{ 
for(int i=0; i<10; i++) 
{ 
arr[i]=i; 
} 
} 
int &operator ()(int i) 
{ 
return arr[i]; 
}
};
int main()
{ 
sarray a1; 
cout<<a1(2); 
a1(3)=7; 
cout<<a1(3); 
return 0;
}


/*
why can't we declare a opaertor overloading dunction using memeber function as static.
Because each operator need one or more operands. So if we will declare it as static then we can't call it using objects(operands).

In order to call it upon some operand which is nothing but an object the function has to be non-static.

Below is a condition which must be satisfied while doing function overloading.

It must have at least one operand which is of user defined type.
So suppose we declare our operator overloading function as static. Then 1st of all the above condition will not be satisfied.

Another reason is, inside static functions we can access only static data members. But while doing operator overloading we have to access all the data members. So if we will declare our operator overloading function as static we cannot access all the data members.

So operator overloading function has to be a non-static member function.

But there an exception.

If we use a friend function for operator overloading then it can be declared as static.*/



// // C++ Program to implement 
// // Input/Output Operators 
// // Overloading 
#include <iostream> 
using namespace std; 

class Fraction { 

private: 
	int numerator; 
	int denominator; 

public: 
	// constructor 
	Fraction(int x = 0, int y = 1) 
	{ 
		numerator = x; 
		denominator = y; 
	} 

	// Operator Overloading Performed 
	// Friend function used because of two classes 
	friend istream& operator>>(istream& input, Fraction& c) 
	{ 
		input >> c.numerator >> c.denominator; 
		return input; 
	} 

	friend ostream& operator<<(ostream& output, Fraction& c) 
	{ 
		output << c.numerator << "/" << c.denominator; 
		return output; 
	} 
}; 

int main() 
{ 
	Fraction x; 
	cout << "Enter a numerator and denominator of "
			"Fraction: "; 
	cin >> x; 
	cout << "Fraction is: "; 
	cout << x; 
	return 0; 
}


#include <bits/stdc++.h>
using namespace std;
 const size = 3;
 class Vector
 {
 int v[size];
 public:
 Vector(); // constructs null Vector
 Vector(int *x); // constructs Vector from array
 friend Vector operator *(int a, Vector b); // friend 1
 friend Vector operator *(Vector b, int a); // friend 2
 friend istream & operator >> (istream &, Vector &);
 friend ostream & operator << (ostream &, Vector &);
 };
 Vector :: Vector()
 {
 for(int i=0; i<size;i++)
 v[i] = 0;
 }
 Vector :: Vector(int *x)
 {
 for(int i=0; i<size; i++)
 v[i] = x[i];
 }
 ostream & operator << (ostream &dout, vector &b)
 {
 dout << "(" << b.v[0];
 for(int i=1; i<size;i++){
 dout << ", " << b.v[i];
 }
 dout << ")";
 return(dout);
 }
 int x[size] = {2,4,6};
 int main()
 {
 Vector m; // invokes constructor 1
 Vector n = x; // invokes constructor 2
 cout<<n;
return 0;
 }