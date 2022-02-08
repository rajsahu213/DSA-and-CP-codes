#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[]){
   for(int i=1;i<argc;i++){
       ifstream fp;
       string line;
       fp.open(argv[i]);
       while(fp){
         getline(fp,line);
         cout<<line<<endl;
       }
       fp.close();
   }
   return 0;
}
