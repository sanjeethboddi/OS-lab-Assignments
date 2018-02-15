#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

    if(argc!=2){
        printf("enter file name you want to read/write/create as command line argument\n");
        exit(0);
    }
    int fd,count=0,t=1;
    char buf[100];
    fd=open(argv[1],O_RDONLY|O_WRONLY|O_RDWR|O_CREAT|O_TRUNC);
    if(fd ==-1){
        printf("Unable to open file\n exiting...\n");
        exit(0);
    }
    printf("Enter some text as input:\n");

    t=read(STDIN_FILENO,buf,10);
    

    write(fd,buf,strlen(buf));
    close(fd);

}
