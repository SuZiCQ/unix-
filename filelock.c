#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc,char *argv[]){

	int flags=O_RDONLY;
	int fd=open(argv[1],flags);

	if(-1==fd){
		perror("open");
		exit(-1);
	}

	//char buf[5];
	//printf("%s\n",read(fd,buf,5));



	struct flock lock;

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=20;


	int f=fcntl(fd,F_SETLK,&lock);
	if(-1==f){
		perror("flock");
		exit(-1);
	}
	printf("read lock set success!");

	getchar();

	close(fd);

	return 0;
}

