#include<iostream>
#include<cstring>
using namespace std;

struct stack
{
    int top;
    char element[50];
    int size;
};

void push(stack &s,char a)
{
    if(s.top==s.size-1)
    {
        cout<<"the stack is full\n";
    }
    else{
        s.top+=1;
        s.element[s.top]=a;
    }
}

char pop(stack &s)
{
    if(s.top==-1)
    {
        return 'e';
    }
    else{
        return s.element[s.top--];
    }
}

char peek(stack &s)
{
    if(s.top==-1)
    {
        return 'e';
    }
    else{
        return s.element[s.top];
    }
}

void oper(stack &s,char a)
{
    switch(a)
    {
        case '+': while(s.top!=-1)
                        {
                            if(s.element[s.top]=='(')
                            {
                                break;
                            }
                            else{
                                cout<<pop(s);
                            }
                        }      
                        push(s,a);
                        break;

        case '-': while(s.top!=-1)
                        {
                            if(s.element[s.top]=='(')
                            {
                                break;
                            }
                            else{
                                cout<<pop(s);
                            }
                        }      
                        push(s,a);
                        break;                        
        case '*' : if(s.top=='*'||s.top=='/')
                            cout<<pop(s);
                        else{
                            push(s,a);
                        }
                        break;

        case '/' : if(s.top=='*'||s.top=='/')
                            cout<<pop(s);
                        else{
                            push(s,a);
                        }
                        break;                        
        case '(' : push(s,a);
                   break;
        case ')' : while(peek(s)!='(')
                   {
                        cout<<pop(s);
                   }  
                   pop(s);                           
                   break;
        default: break;           
    }
}

void inf_to_post(stack &s,char a[])
{
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        int b=a[i];
        if(b<=57&&b>=48)
        {
            cout<<a[i];
        }
        else{
            oper(s,a[i]);
        }
    }
    while(s.top!=-1)
    {
        cout<<pop(s);
    }
    cout<<endl;
}

int main()
{
    struct stack s;
    s.top=-1;
    s.size=40;
    cout<<"enter a string: ";
    char a[40];
    cin.getline(a,40);
    inf_to_post(s,a);
}