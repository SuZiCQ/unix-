#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[]){

	int flags=O_WRONLY|O_CREAT;
	int fd=open(argv[1],flags,0644);
	if(-1==fd){
		printf("file not exits!\n");
		exit(-1);
	}
	printf("file open success!\n");
	char buf[14]="hello world!\n";
	write(fd,buf,14);
	close(fd);
	return 0;
}
