#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

    if(argc!=2){
        printf("enter file name to which you want to append as command line argument\n");
        exit(0);
    }
    int fd,count=0,t,buf_size=100,j;
    char buf[buf_size],ch;
    fd=open(argv[1],O_RDWR|O_APPEND|O_CREAT,00700);
     if(fd ==-1){
        printf("Unable to open file\n exiting...\n");
        exit(0);
    }
	printf("Enter Text not more than 100 Characters and press Ctrl + D for exit:\n");
	while(read(STDIN_FILENO,&ch,1)&&count<=buf_size){	
	buf[count++]=ch;
	}
    write(fd,buf,count);
    close(fd);
}
