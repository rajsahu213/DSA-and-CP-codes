#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
	int status;
	if(argc>=0 && strcmp(argv[1],"-i")==0)
	{
		for(int i=2;i<argc;i++){
		status=-1;
		char c;
		printf("Do you want to delete?y/n \n");
		scanf("%c",&c);
		if(c=='y')
		{
			status=remove(argv[i]);
			if(status==0)printf("Deletion successful\n");
			else printf("Error while deletion \n");
		}
	 }
	}
	else
	{
		for(int i=1;i<argc;i++){
		status=-1;
		status=remove(argv[i]);
		if(status==0)printf("Deletion successful \n");
		else printf("Error while deletion \n");
	 }
	}
}