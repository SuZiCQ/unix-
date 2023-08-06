#include <stdio.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
    printf("pid:%d\n",getpid());
    struct flock lock;
    //设置锁结构体的成员
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=6;

    //打开文件，以写的方式打开文件
    int fd=open(argv[1],O_RDWR);
    if(fd==-1){
    	perror("open");
	exit(-1);
    }
    //对指定文件加写锁
    int f=fcntl(fd,F_SETLK,&lock);
    if(f==-1){
    	perror("flock");
	close(fd);
	exit(-1);
    }
    //到这里加写锁成功
    printf("write lock success...\n");
    getchar();//防止锁被解除
    //关闭文件描述符的时候，所有的记录锁都被移除
    close(fd);
    return 0;
}
