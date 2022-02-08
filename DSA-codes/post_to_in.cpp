#include<bits/stdc++.h>
using namespace std; 
bool isOperator(char x) { 
  if(x=='+'||x=='*'||x=='-'||x=='/')return true;
  else return false; 
} 
string postToInfix(string pre_exp)
 { 
  stack<string> s; 
  int length = pre_exp.size(); 
  for (int i=0;i<length;i++) 
  { 
    if (isOperator(pre_exp[i]))
     { 
      string op1 = s.top();   s.pop(); 
      string op2 = s.top();   s.pop(); 
      string temp = ")"+ op1 + pre_exp[i] + op2 +"("; 
      s.push(temp); 
    } 
    else { 
      s.push(string(1, pre_exp[i])); 
    } 
  } 
  return s.top(); 
}  
int main() 
{ 
  cout<<"enter a string: ";
  string pre_exp;cin>>pre_exp; 
  string inf=postToInfix(pre_exp);
  reverse(inf.begin(),inf.end());
  cout << "Infix : " <<  inf<<endl;
  return 0; 
} 
