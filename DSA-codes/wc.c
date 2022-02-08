#include<stdio.h>
#include <unistd.h> 
#include <fcntl.h> 
#include<string.h>
int main(int argc, char *argv[])
{
	int totwords=0,totlines=0, totbytes=0;
	int fd;
	int start=1;
	if(argc>=2&&(strcmp(argv[1],"-w")==0||strcmp(argv[1],"-l")==0||strcmp(argv[1],"-c")==0))
	{
	   start++;
	}
	for(int i=start;i<argc;i++)
	{
		int curwords=0,curlines=0,curbytes=0;
		char prev;
		char Buffer[1];
		fd=open(argv[i],O_RDONLY);
		while(read(fd,Buffer,1)==1)  //read each byte
		{
			if(Buffer[0]==' '||Buffer[0]=='\t')
			{
				if(prev!=' '&&prev!='\t')
				{
					curwords++;
				}
			}
			else if(Buffer[0]=='\n')
			{
				if(prev!=' '&&prev!='\t')
				curwords++;
				curlines++;
			}
			prev=Buffer[0];
			curbytes++;
		}
		if(start==1)
		printf("%d %d %d %s\n", curlines, curwords , curbytes, argv[i]);
		else if(strcmp(argv[1],"-l")==0)
		printf("%d %s\n", curlines, argv[i]);
		else if(strcmp(argv[1],"-w")==0)
		printf("%d  %s\n", curwords , argv[i]);
		else printf("%d %s\n",  curbytes, argv[i]);
		totwords+=curwords;
		totbytes+=curbytes;
		totlines+=curlines;
	}
	if((argc>2&&start==1))
	printf("total %d %d %d\n",totlines,totwords,totbytes);
}