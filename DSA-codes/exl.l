%{
	#include<iostream>
	using namespace std;
	int vc=0;
	int cc=0;
%}
DIGIT [0-9]

%%
\+?{DIGIT}+    {vc++;}
-{DIGIT}+      {cc++;}
%%

main()
{
	cout<<"enter numbers: ";
	yylex();
	cout<<"no of v: "<<vc<<"\n";
	cout<<"no of c: "<<cc<<"\n";
	return 0;
}