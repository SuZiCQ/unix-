#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>


int main(int argc,char *argv[]){

	struct stat *st;
	st=(struct stat*)malloc(sizeof(struct stat));
	int s=stat(argv[1],st);
	if(-1==s){
		perror("error");
		exit(-1);
	}
	unsigned long int inode=st->st_ino;

	long int time=st->st_mtim.tv_sec;

	unsigned int uid=st->st_uid;

	unsigned int gid=st->st_gid;

	long int filesize=st->st_size;

	unsigned int nlink=st->st_nlink;

	char *ptime=ctime(&time);

	struct passwd *pd=getpwuid(uid);

	char *username=pd->pw_name;

	struct group *gd=getgrgid(gid);

	char *groupname=gd->gr_name;

	switch(st->st_mode&S_IFMT){
	
		case S_IFREG:
			printf("-");
			break;
		case S_IFCHR:
			printf("d");
			break;
		case S_IFLNK:
			printf("l");
			break;
	}

	(st->st_mode&S_IRUSR)?printf("r"):printf("-");
	(st->st_mode&S_IWUSR)?printf("w"):printf("-");
	(st->st_mode&S_IXUSR)?printf("x"):printf("-");

	(st->st_mode&S_IRGRP)?printf("r"):printf("-");
	(st->st_mode&S_IWGRP)?printf("w"):printf("-");
	(st->st_mode&S_IXGRP)?printf("x"):printf("-");


	(st->st_mode&S_IROTH)?printf("r"):printf("-");
	(st->st_mode&S_IWOTH)?printf("w"):printf("-");
	(st->st_mode&S_IXOTH)?printf("x"):printf("-");


	printf(" %u ",nlink);
	printf("%s ",username);
	printf("%s ",groupname);

	printf("%ld ",filesize);

	printf("%s",ptime);
	free(st);




#if 0
	struct stat file;
	int statu=stat(argv[1],&file);
	if(-1==statu){
		perror("error");
		exit(-1);
	}
	printf("%d\t%d\t%d\t%d\t%d\n",file.st_ino,file.st_nlink,file.st_uid,file.st_gid,file.st_size);
#endif
	return 0;
}


