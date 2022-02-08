#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	a=10;
	int *p;
	p=&a;
	cout<<"address of a is: "<<p<<endl;
	cout<<"value of a is: "<<*p<<endl;
	int **p1;
	p1=&p;
	cout<<"address of pointer p is: "<<p1<<endl;
	cout<<"value at address p is: "<<*p1<<endl;
	int ***p2;
	p2=&p1;
	cout<<"address of pointer p1 is: "<<p2<<endl;
	cout<<"value at address p1 is: "<<*p2<<endl;

	cout<<"access value of a from p1: "<<*(*p1)<<endl;
	cout<<"access value of a from p2: "<<*(*(*p2))<<endl;
}