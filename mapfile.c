#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>


int main(int argc,char *argv[]){

	int flags1=O_RDWR|O_CREAT|O_APPEND;  //以追加的方式打开文件，若文件不存在，则创建文件
	int fd=open(argv[1],flags1,0644);

	int length=4096;		//设置该虚拟空间为4KB
	int prot=PROT_READ|PROT_WRITE;	//指定该虚拟空间是可读可写的
	int flags2=MAP_SHARED;		//指定对该虚拟空间的操作会同步到文件
	char *p=mmap(NULL,length,prot,flags2,fd,0);

	//int *pi=mmap(NULL,length,prot,flags2,fd,0);

	




	close(fd);			//关闭文件不影响已映射区域的使用，即还是会修改文件。

	strcpy(p,"hello world\n");	//在虚拟空间写入信息

	munmap(p,length);		//解除映射；

	return 0;
}
