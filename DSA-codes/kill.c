#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include<string.h>
int getSignal(char * Signal)
{
        char Arr[20];
        strcpy(Arr,"");
        if(Signal[0]!='-')
                return -1;
        for(int i=1;Signal[i]!='\0';i++)
        {
                char Temp[1];
                Temp[0]=Signal[i];
                strcat(Arr,Temp);
        }
        if(strcmp(Arr,"SIGKILL")==0)
        {
                return SIGKILL;
        }
        else if(strcmp(Arr,"SIGTERM")==0)
        {
                return SIGTERM;
        }
        else if(strcmp(Arr,"SIGHUP")==0)
        {
                return SIGHUP;
        }
        return atoi(Arr);
}
int main(int argc, char * argv[])
{
        if(argc==2)
        {
                kill(atoi(argv[1]),SIGKILL);
        }
        else if(argc>2&&getSignal(argv[1])!=-1)
        {
                for(int i=2;i<argc;i++)
                {
                        kill(atoi(argv[i]),getSignal(argv[1]));
                }
        }
        else if(argc>2)
        {
                for(int i=1;i<argc;i++)
                {
                        kill(atoi(argv[i]),SIGKILL);
                }
        }
        return 0;
}