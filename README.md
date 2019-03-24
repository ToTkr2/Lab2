# Lab2实验报告
1.打开一个vi进程。通过ps命令以及选择合适的参数，只显示名字为vi的进程。寻找vi进程的父进程，直到init进程为止。记录过程中所有进程的ID和父进程ID。将得到的进程树和由pstree命令的得到的进程树进行比较。
在终端输入vi后，再另一个终端输入输入ps –lax|grep vi查看进程状态，找到父进程号，在用相 的命令查看父进程状态，直到父进程为1为止，可得一个进程树。
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/xt2.3.png)
如图，可以看到1->1896->3048->3057->3081
输入pstree –p查看进程树
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.5.png)
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.4.png)
可以看到进程树是一致的
2.编写程序，首先使用fork系统调用，创建子进程。在父进程中继续执行空循环操作；在子进程中调用exec打开vi编辑器。然后在另外一个终端中，通过ps –Al命令、ps aux或者top等命令，查看vi进程及其父进程的运行状态，理解每个参数所表达的意义。选择合适的命令参数，对所有进程按照cpu占用率排序。
代码在question2中
 ```
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
```
结果如图：




