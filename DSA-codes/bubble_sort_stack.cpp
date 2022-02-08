#include<iostream>
#include<stack>
#include<cstring>
#include<climits>
using namespace std;

// struct stack
// {
//     int top;
//     int element[50];
//     int size;
// };

// void push(stack &s,int a)
// {
//     if(s.top==s.size-1)
//     {
//         cout<<"the stack is full\n";
//     }
//     else{
//         s.top+=1;
//         s.element[s.top]=a;
//     }
// }

// int pop(stack &s)
// {
//     if(s.top==-1)
//     {
//         return -1;
//     }
//     else{
//         return s.element[s.top--];
//     }
// }

// int peek(stack &s)
// {
//     if(s.top==-1)
//     {
//         return -1;
//     }
//     else{
//         return s.element[s.top];
//     }
// }

// void bubble_sort(int a[],int n)
// {
//     stack s1,s2;
//     s1.top=s2.top=-1;
//     s1.size=s2.size=n+5;
//     int temp;
//     push(s1,INT_MIN);
//     push(s2,INT_MIN);
//     for(int i=0;i<n;i++)
//     {
//         push(s1,a[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(i%2==0)
//         {
//             while(s1.top!=0)
//             {
//                 if(peek(s1)>peek(s2))
//                 {
//                     push(s2,pop(s1));
//                 }
//                 else{
//                     temp=pop(s2);
//                     push(s2,pop(s1));
//                     push(s1,temp);
//                 }            
//             }
//             a[n-i-1]=pop(s2);
//         }
//         else{
//             while(s2.top!=0)
//             {
//                 if(peek(s2)>peek(s1))
//                 {
//                     push(s1,pop(s2));
//                 }
//                 else{
//                     temp=pop(s1);
//                     push(s1,pop(s2));
//                     push(s2,temp);
//                 }
//             }
//             a[n-i-1]=pop(s1);
//         }
//     }
// }


void bubble_sort(int a[],int n)
{
    stack<int> s1,s2;
    for(int i=0;i<n;i++)
    {
        s1.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            s2.push(s1.top());
            s1.pop();
            while(!s1.empty())
            {
                if(s1.top()>s2.top())
                {
                    s2.push(s1.top());s1.pop();
                }
                else
                {
                    int temp=s1.top();s1.top()=s2.top();s2.top()=temp;
                }
            }
            a[n-i-1]=s2.top();s2.pop();
        }
        else
        {
            s1.push(s2.top());
            s2.pop();
            while(!s2.empty())
            {
                if(s2.top()>s1.top())
                {
                    s1.push(s2.top());s2.pop();
                }
                else
                {
                    int temp=s2.top();s2.top()=s1.top();s1.top()=temp;
                }
            }
            a[n-i-1]=s1.top();s1.pop();
        }
    }
}


int main()
{
    cout<<"enter n: ";
    int n;cin>>n;
    cout<<"enter the number \n";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);
    cout<<"the sorted array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}