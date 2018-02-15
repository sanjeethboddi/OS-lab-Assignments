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
    int fd,count=0,t,buf_size=100,j;
    char buf[buf_size];
    fd=open(argv[1],O_RDONLY);
    if(fd ==-1){
        printf("Unable to open file\n exiting...\n");
        exit(0);
    }

    do{
        t=read(fd,buf,buf_size);
        for(j=0;j<t;j++){
            printf("%c",buf[j]);
        }
    }while(t==buf_size);

    close(fd);
}
