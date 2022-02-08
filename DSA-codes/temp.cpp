//snigdh_op
//Snigdh Verma
#include<bits/stdc++.h>
#define mod 998244353
#define INFI 1e15
#define INFIM 1e18
#define ll long long int
#define ld long double
#define pb push_back
#define f(t) for(int i=0;i<t;i++)
#define fi first
#define se second
#define all(t) t.begin(),t.end()
#define mii map<int,int>
#define pii pair<int,int>
#define mll map<long long int,long long int>
#define pll map<long long int,long long int>
#define vll vector<long long int>
#define endl "\n"
#define fio ios_base::sync_with_stdio(false)
using namespace std;

int main()
{   fio;
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {

        string s;
        cin>>s;
        int n=s.length();
        stack<char>st;
        ll arr[4]={748683265,748683265,748683265,748683265};
        ll fact=748683265;
        int i=0;
        while(i<s.size())
        {
            if(s[i]!=')')
            {
                st.push(s[i]);
            }
            else
            {
                while(st.top()=='#')st.pop();
                char ch1=st.top();
                st.pop();
                while(st.top()!='(')st.pop();
                st.pop();
                
                ll temp[4];
                if(ch1=='|')
                {
                    temp[0]=(fact*arr[0])%mod;
                    temp[1]=((fact+arr[1])%mod+(fact*arr[2])%mod+(fact*arr[3])%mod-(fact*arr[1])%mod)%mod;
                    temp[2]=((fact*arr[0])%mod+(arr[2]*fact)%mod)%mod;
                    temp[3]=((fact*arr[0])%mod+(arr[3]*fact)%mod)%mod;
                }
                else if(ch1=='&')
                {
                    temp[0]=((fact+arr[0])%mod+(fact*arr[2])%mod+(fact*arr[3])%mod-(fact*arr[0])%mod)%mod;
                    temp[1]=(fact*arr[1])%mod;
                    temp[2]=((fact*arr[2])%mod+((fact*arr[2])%mod+(fact*arr[1])%mod)%mod)%mod;
                    temp[3]=((fact*arr[3])%mod+((fact*arr[3])%mod+(fact*arr[1])%mod)%mod)%mod;
                }
                else if(ch1=='^')
                {
                    temp[0]=((fact*arr[0])%mod+(fact*arr[1])%mod+(fact*arr[2])%mod+(fact*arr[3])%mod)%mod;
                    temp[1]=((fact*arr[0])%mod+(fact*arr[1])%mod+(fact*arr[2])%mod+(fact*arr[3])%mod)%mod;
                    temp[2]=((fact*arr[2])%mod+(fact*arr[0])%mod+(fact*arr[1])%mod+(fact*arr[3])%mod)%mod;
                    temp[3]=((fact*arr[2])%mod+(fact*arr[0])%mod+(fact*arr[1])%mod+(fact*arr[3])%mod)%mod;
                }
                arr[0]=temp[0];
                arr[1]=temp[1];
                arr[2]=temp[2];
                arr[3]=temp[3];
            }
            i++;
        }
        for(int i=0;i<4;i++)
        {
            cout<<arr[i]<<" ";

        }
        cout<<endl;
    }
    return 0;}