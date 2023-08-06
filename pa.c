#include <stdio.h>
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
    printf("pid:%d\n",getpid());
    struct flock lock;
    //设置锁结构体的成员
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=20;

    //打开文件，以只读的方式打开文件
    int fd=open(argv[1],O_RDWR);

    char buf[3];

    read(fd,buf,3);
    printf("%s\n",buf);
    //if(fd==-1)E_MSG("open",-1);
    //对指定文件加读锁
    int f=fcntl(fd,F_SETLK,&lock);
    if(-1==f){
    	perror("flock");
	close(fd);
	exit(-1);
    }
    //if(f==-1)E_MSG("fcntl",-1);
    //到这里加读锁成功
    printf("read lock success...\n");
    getchar();//防止锁被解除
    //关闭文件描述符的时候，所有的记录锁都被移除
    //
    char b[3]; 
    read(fd,b,3);
    printf("%s\n",buf);

    close(fd);
    return 0;
}
