#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;
	pid = fork(); // creating child process
	if (pid < 0) {
		fprintf(stderr, "fork failed!");
		return 1;
	}
	else if (pid == 0) {
		printf("child process with pid= %d\n", getpid() );
	}
	else {
		printf("parent process with pid= %d\n", getpid() );
	}
	return 0;
}