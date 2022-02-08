#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <fcntl.h>    
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>		
int main(int argc, char const *argv[]){
	char buffer[4096];
	while(fgets(buffer,4096,stdin)!=NULL){
		fputs(buffer,stdout);
	}
	return 0;
}