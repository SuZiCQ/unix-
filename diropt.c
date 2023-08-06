#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	if(argc!=2){
		printf("请输入 一个参数");
		exit(- 1);
	}
	DIR *dir=opendir(argv[1]);
	if(NULL==dir){
		perror("opendir");
		return -1;
	}
	printf("open success\n");

	struct dirent *dirp;
	while(NULL!=(dirp=readdir(dir)))
		printf("%s\t",dirp->d_name);
	printf("\n");
	closedir(dir);
}
