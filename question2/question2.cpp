#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	
	pid_t pid;
	
	/*创建子进程*/
	pid = fork();
	
	if(pid <0) 
		printf("fork error");
	if (pid == 0)
	  	execl("/usr/bin/vi","vi",NULL);
	if(pid>0)
	{
		while(1){}
		}

}
