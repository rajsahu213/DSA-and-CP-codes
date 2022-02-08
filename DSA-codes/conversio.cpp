#include<iostream>
using namespace std;

void conversion(int n,int r,int r1,char a)
{
    static int i=n;
    if(n==0)
    {
        return;
    }
    else{
        r1=n%r;
        conversion(n/r,r,r1,a);
        switch(a)
        {
            case 'b':cout<<r1;
                     break;
            case 'x':{char arr[6]={'A','B','C','D','E','F'};
                     if(r1>9)cout<<arr[r1-10];      
                     else cout<<r1;
                     break;}
            case 'o':cout<<r1;
                     break;                 
            case 'p':string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
                    cout<<s[r1]<<" ";
        }
    }
}

int main()
{
    cout<<" n: ";
    int n,x;cin>>n;
    cout<<" r: ";
    char r;cin>>r;
    int r1;
    switch(r)
    {
        case 'b':r1=2;
                 break;
        case 'x':r1=16;
                 break;
        case 'o':r1=8;
                 break;
        case 'p':r1=10;
                 break;
    }
    conversion(n,r1,x,r);
    cout<<endl;
}