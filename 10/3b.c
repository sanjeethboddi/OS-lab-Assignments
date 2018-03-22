#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define max_line_size 1000
void main(int argc,char * argv[]){
	if(argc !=3){
		printf("Please enter file name and string to search as command line arguments properly..\n exitting...\n");
	}
	int pointer=0;
	int fd,n,t;
	char line[max_line_size];
	fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		printf("Unable to open file with specified name\n");
	}
	else{
		do{
			do{
				t=read(fd, &line[pointer], 1);
				pointer++;
			}while(t!=0 && line[pointer-1]!='\n');
			
			if(strstr(line, argv[2])!=NULL){
				printf("found the string in:  %s\n",line);
			}
			pointer =0;
			memset(line,'\0', max_line_size);
		}while(t!=0);
	}

}


