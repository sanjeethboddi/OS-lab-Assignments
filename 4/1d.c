#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
void main(int argc, int *argv[]){
  if(argc!= 2){
    printf("enter the file name as command line arguments\n");
    printf("exiting....\n\n");
    exit(0);
  }
  int a;
  struct stat buf;
  char mtime[100];
  a=stat(argv[1],&buf);
  if(a<0){
    printf("file with that name does not exist\n");
    printf("exiting...\n\n");
    exit(0);
  }
  printf("user id of owner: %o\n",buf.st_uid);
  printf("group id of owner: %o\n",buf.st_gid);
  printf("blocksize for filesystem I/O: %o\n",buf.st_blksize);
  printf("number of 512B blocks allocated: %o\n",buf.st_blocks);
  printf("total size, in bytes: %o\n",buf.st_size);
  printf("number of hard links: %o\n",buf.st_nlink);
  printf("%s",ctime(&buf.st_atime));
  printf("%s",ctime(&buf.st_mtime));
  if(buf.st_mode==S_IRUSR){
    printf("owner has read permission\n");
  }
  else if(buf.st_mode==S_IWGRP){
    printf("group has write permission\n");
  }
  else if(buf.st_mode==S_IXOTH){
    printf("others have execute permission\n");
  }

}
