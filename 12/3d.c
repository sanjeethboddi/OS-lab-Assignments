#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
void main(int argc,char * argv[]){
	if(argc !=2){
		printf("Please enter file name to delete as command line arguments properly..\n exitting...\n");
	}
	
	int fd,ret;
	
	
	ret=unlink(argv[1]);
	if(ret< 0){
	printf("error\n");
	}
}
