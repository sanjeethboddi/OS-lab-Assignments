#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char * argv[]){
  if(argc != 2){
    printf("enter the directory name as command line arguments\n");
    printf("exiting...\n\n");
    exit(0);
  }
  DIR *dir;
  struct dirent * sd;
  dir = opendir(argv[1]);
  if(dir==NULL){
    printf("Failed to open (OR) NO directory exists with that name");
    exit(0);
  }

  while((sd=readdir(dir))!=NULL){
    printf("--> %s\n",sd->d_name);
  }

  closedir(dir);
}
