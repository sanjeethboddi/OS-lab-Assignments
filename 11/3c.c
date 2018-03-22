#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define buffer_size 1024
void main(int argc,char * argv[]){
	if(argc !=3){
		printf("Please enter source file name and destination file name as command line arguments properly..\n exitting...\n");
	}
	char buffer[buffer_size];
	int fd1, fd2 ,ret1, ret2 ;
	
	fd1 = open(argv[1], O_RDONLY);
	if(fd1==-1){
		printf("Unable to open file with specified name\n");
	}
	
	fd2= open(argv[2], O_CREAT| O_RDWR,S_IRUSR |S_IXGRP|S_IROTH);
	if(fd2== -1){
		printf("Unable to create the destination file\n");
		exit(0);
	}
	
	do{
		ret1 = read(fd1, buffer, buffer_size);	
		ret2 = write(fd2, buffer, ret1);
	}while(ret1!=0);
	printf("succesfully copied\n");
	close(fd1);
	close(fd2);
	return;
}
