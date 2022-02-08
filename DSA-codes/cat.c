#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <fcntl.h>    
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>  //for file descriptor
int cat(int argc, char *argv[]) {
  int i, j; // Loop index variables
  int fd, count; // Open file descriptor and
  char buffer[4097];// count of bytes to read/write
  if (argc == 1) {
    // No argument file, then display the input taken from stdin
    while (fgets(buffer, 4096, stdin) != NULL)
    fputs(buffer, stdout);
    return 0;
  }
  for(int i=1; i<argc; i++) {
    if (strcmp(argv[i], "-") == 0) {
      // If "-" is specified as argument it refers to stdin
      fd = fileno(stdin);  //filehandle associated with given stream, return 0 for stdin,1 fro stdout , 2 for stderr
    }
    else {
      // Open the i’th argument file for reading
      fd = open(argv[i], O_RDONLY, 0);
    }
    if (fd<0) {
      sprintf(buffer, "Error: Opening file %s :", argv[i]);
      perror(buffer);
      continue;
    }
    // Read the contents from the file and display on stdout
    int d=fileno(stdout);
    while((count = read(fd, buffer, sizeof(buffer))) > 0) {
      write(d, buffer, count);
    }
    // If current file is not stdin, then close the file
    if (strcmp(argv[i], "-") != 0)close(fd);
  } 
  return 0;

}

int main(int argc, char *argv[]) {
  return cat(argc, argv);
}