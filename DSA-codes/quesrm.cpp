#include<iostream>
#include<string>
using namespace std;
int main(int argc,char* argv[]){
 int flag;
 int n=argc;
 string s=argv[1];
 if(n>=2&&s=="-i"){
  for(int i=2;i<argc;i++){
    flag=-1;
    char ans;
    cout<<"Do you want to delete this file? Y/N \n";
    cin>>ans;
    if(ans=='Y')
    {
       flag=remove(argv[i]);
       if(flag==0){
          cout<<"File Deleted Successfully\n";
       }
    }
   }
 }
 else{
     for(int i=1;i<argc;i++){
        flag=-1;
        flag=remove(argv[i]);
        if(flag!=0){
          cout<<"File Not Deleted Successfully\n";
        }
     }
 }
return 0;
}
