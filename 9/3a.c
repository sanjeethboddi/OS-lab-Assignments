#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv){
	char buf[1000];
	char * list[1000];
	char name[100];
	int c=0;
	struct dirent **namelist;
    int n;
	getcwd(buf,1000);
	n = scandir(buf, &namelist, NULL, alphasort);
    if (n == -1) {
    	printf("error scanning directory... \nexiting...\n");
		exit(0);
	}
	while(c++<n-1){
		strcpy(name,namelist[c]->d_name);
		if(name[0]!='.')printf("%s\n", name);
		free(namelist[c]);
	}
	free(namelist);
}
