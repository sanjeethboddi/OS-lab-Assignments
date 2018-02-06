#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int i=fork();
	if(i==-1){
		printf("Process creation unsuccessfull\n");
    exit(0);
	}
	else if(i==0){
		printf("Child Starts\n");
		printf("printing odd numbers");
		for(int i=1;i<=9;i+=2)printf("\t%d",i);
		printf("\nchild ends\n");
	}
	else if(i>0){
    wait(0);
    printf("Parent Starts\n");
		printf("printing odd numbers");
		for(int i=0;i<=10;i+=2)printf("%d\t",i);
		printf("\nparent ends\n");
	}

}
