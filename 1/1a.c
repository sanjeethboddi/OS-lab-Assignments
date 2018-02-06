#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int i=fork();
	if(i==-1){
		printf("Process creation unsuccessfull\n");
	}
	else if(i==0){
		printf("Child process\n");
		printf("the process_id of child_process is: %d\n",getpid());
		printf("value of x is: %d\n",i);
		printf("the process_id of parent process is:%d\n",getppid());
	}
	else if(i>0){
		printf("Parent process\n");
		printf("the process_id of parent_process is: %d\n",getpid());
		printf("value of x is: %d\n",i);
		printf("the process_id of shell is:%d\n",getppid());
	}

}
