#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main(int argc, char * argv[]){
  int i,e;
  if(argc<3){
    exit(0);
  }
  else{
    i=fork();
    if(i==-1){
      printf("Process creation unsuccessfull\n");
      exit(0);
    }
    else if(i>1){
      wait();
      printf("Child Terminated\n");
      exit(0);
    }
    else{
      printf("Child starts\n");
      e=execlp(argv[1],argv[2],NULL);
      if(e==-1)printf("exception: give proper path and name as arguements\n");
      exit(0);
    }
  }
}
