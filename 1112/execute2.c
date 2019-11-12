#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf("parent process start\n");
	if(fork() ==0){
		execl("/bin/echo","echo","hello",NULL);
		fprintf(stderr, "first false");
		exit(1);
	}

	if(fork() ==0){
		execl("/bin/date","date",NULL);
		fprintf(stderr,"second false");
		exit(2);
	}

	if(fork()==0){
		execl("/bin/ls","ls","-l",NULL);
		fprintf(stderr,"third false");
		exit(3);
	}
	printf("parent process end\n");
}

