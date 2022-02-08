#include<iostream>
#include<cstring>
using namespace std;

int eval(char s[],int *a,int n)
{
    static int i=0;
    static int j=0;
    static int ans=0;
    if(i==n)
    {
        return ans;
    }
    else{
        int b=s[i];
        if(b<=57&&b>=48)
        {
            a[j]=b-48;
            i++;j++;
            eval(s,a,n);
        }
        else{
            if(s[i]=='+')
            {
                ans=(a[j-1]+a[j-2]);
                i++;
                j=j-2;
                a[j]=ans;
                j++;
                eval(s,a,n);
            }
            else if(s[i]=='-')
            {
                ans=(a[j-2]-a[j-1]);
                i++;
                j=j-2;
                a[j]=ans;
                j++;
                eval(s,a,n);                
            }
            else if(s[i]=='*')
            {
                ans=(a[j-1]*a[j-2]);
                i++;
                j=j-2;
                a[j]=ans;
                j++;
                eval(s,a,n);                
            }
            else if(s[i]=='/')
            {
                ans=(a[j-2]/a[j-1]);
                i++;
                j=j-2;
                a[j]=ans;
                j++;
                eval(s,a,n);                
            }
        }
    }
}

int main()
{
    int *p;
    char s[50];
    cout<<"enter a string: ";
    cin.getline(s,50);
    int n=strlen(s);
    p=new int[n];
    int result=eval(s,p,n);
    cout<<"the answer is: "<<result<<endl;
}