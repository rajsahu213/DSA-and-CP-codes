#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;



int main()
{
	ifstream Mary1,Mary2;
	Mary1.open("output1.txt",ios::binary);
	Mary2.open("output2.txt",ios::binary);
	
//---------- compare number of lines in both files ------------------//
	int c1,c2;
	c1 = 0; c2 = 0;
	string str;
	while(!Mary1.eof())
	{
		getline(Mary1,str);
		c1++;
	}
	Mary1.clear();   //  set new value for error control state  //
	Mary2.seekg(0,ios::beg);
	while(!Mary2.eof())
	{
		getline(Mary2,str);
		c2++;
	}
	Mary2.clear();
	Mary2.seekg(0,ios::beg);
	
 	if(c1 != c2) 
	{
		cout << "Different number of lines in files!" << "\n";
		cout << "Mary1 has " << c1 << " lines and Mary2 has " 
				     << c2 << " lines" << "\n";  
	}
//---------- compare two files line by line ------------------//
	char string1[256], string2[256];
	int j = 0;
	while(!Mary1.eof())
	{
		Mary1.getline(string1,256);
		Mary2.getline(string2,256);
		j++;
		if(strcmp(string1,string2) != 0)
		{
			cout << j << "-the strings are not equal" << "\n";
			cout << "   " << string1 << "\n";
			cout << "   " << string2 << "\n";
		}
	}
	
	return 0;
}