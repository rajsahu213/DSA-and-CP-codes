#include <iostream>

using namespace std;

int main()
{

double num;
int intnum, m, d, c, l, x, v, i, n;
char yes ='y';

while (yes == 'y')
{
cout << "Enter a number: ";
cin >> num;
intnum = (int)num;

if (intnum >= 1000)
{  
    m = intnum / 1000;
    n = 0;
		{
		for (n=0; n < m; n++)
		cout << "M";
		}
	intnum = intnum%1000;
}

if (intnum >= 900)
{
	cout << "CM";
	intnum = intnum%900;
}
	else if (intnum >= 500)
    {
			{
			d = intnum / 500;
			n = 0;
			for (n=0; n < d; n++)
			cout << "D";
			}
        intnum = intnum%500;
    }
       
if (intnum >= 400)
{
	cout << "CD";
	intnum = intnum%400;
}       
    else if (intnum >= 100)
	{
		    {
            c = intnum / 100;
            n = 0;
            for (n=0; n < c; n++)
            cout << "C";
			}
		intnum = intnum%100;
	}

if (intnum >= 90)
{
cout << "XC";
intnum = intnum%90;
}

	else if (intnum >= 50)
	{
			{
            l = intnum / 50;
			n = 0;
            for (n=0; n < l; n++)
            cout << "L";
			}
		intnum = intnum%50;
	}
if (intnum >= 40)
{
cout << "XL";
intnum = intnum%40;
}
       
	else if (intnum >= 10)
	{
			{
            x = intnum / 10;
            n = 0;
            for (n=0; n < x; n++)
            cout << "X";
			}
		intnum = intnum%10;
	}

if (intnum >= 9)
{
cout << "IX";
intnum = intnum%9;
}

	else if (intnum >= 5)
	{
			{
            v = intnum / 5;
            n = 0;
            for (n=0; n < v; n++)
            cout << "V";
			}
		intnum = intnum%5;
	}
if (intnum >= 4)
{
cout << "IV";
intnum = intnum%4;
}
	else if (intnum >= 1)
	{
           i = intnum;
           n = 0;
           for (n=0; n < i; n++)
           cout << "I";
	}
	    cout << "\nWould you like to run this program again? (y/n): ";
	    cin >> yes;
        cout << endl; 
}
return 0;
}