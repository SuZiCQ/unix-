#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[]){

	int flags=O_RDWR|O_CREAT|O_APPEND;
	unsigned int mode=0644;
	int fd=open(argv[1],flags,mode);
	char *buf="hello world\n";
	write(fd,buf,strlen(buf));
	close(fd);


	return 0;
}



