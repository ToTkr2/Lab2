# Lab2实验报告
1.打开一个vi进程。通过ps命令以及选择合适的参数，只显示名字为vi的进程。寻找vi进程的父进程，直到init进程为止。记录过程中所有进程的ID和父进程ID。将得到的进程树和由pstree命令的得到的进程树进行比较。  
在终端输入vi后，再另一个终端输入输入ps –lax|grep vi查看进程状态，找到父进程号，在用相 的命令查看父进程状态，直到父进程为1为止，可得一个进程树。  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/xt2.3.png)  
如图，可以看到1->1896->3048->3057->3081
输入pstree –p查看进程树  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.5.png)  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.4.png)  
可以看到进程树是一致的  

---
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
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.10.png)  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.9.png)  
如图所示，vi进程号为2320，父进程为2319，其中各项数据分别为进程号，父进程号，创建时间，控制终端，运行时间，进程名  
使用top -P命令将所有进程按CPU使用率由高到低排列  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.13.png) 

---
3.使用fork系统调用，创建如下进程树，并使每个进程输出自己的ID和父进程的ID。观察进程的执行顺序和运行状态的变化。  
代码在question3中  

```
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
#include "stdlib.h"



int main()
{
    pid_t p1,p2,p3,p4,p5;

      printf("p1 is parent with pid %d,ppid %d\n",getpid(),getppid());
	 
     if((p2=fork())==0)
     {
	     printf("p3 is p1's child with pid %d,ppid %d\n",getpid(),getppid());
	      return 0;
  	   }
  	   
  	   else if((p3=fork())==0)
  	   {
	        printf("p2 is p1's child with pid %d,ppid %d\n",getpid(),getppid());
	        
		 if((p4=fork())==0)
		 {
			 printf("p4 is p2's child with pid %d,ppid %d\n",getpid(),getppid());		
					return 0;
					}
					
		else if((p5=fork())==0)
                {
						printf("p5 is p2's child with pid %d,ppid %d\n",getpid(),getppid());
					return 0;
					}
					
			}
				
    else if(p1>0){}
		sleep(1);
    return 0;
}

```
结果如图  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.12.png)
可以看见p1进程号为3177，父进程号3175  
可以看见p2进程号为3179，父进程号3177  
可以看见p3进程号为3178，父进程号3177  
可以看见p5进程号为3181，父进程号3179  
可以看见p4进程号为3180，父进程号3179  
顺序如图所示  

---

4.修改上述进程树中的进程，使得所有进程都循环输出自己的ID和父进程的ID。然后终止p2进程(分别采用kill -9 、自己正常退出exit()、段错误退出)，观察p1、p3、p4、p5进程的运行状态和其他相关参数有何改变。  
代码在question4中  
```
#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"
#include "stdlib.h"

#define HASPRO -10

int main()
{
    pid_t p1,p2,p3,p4,p5;

    

    while((p1=fork()) == -1);

    if(!p1)
    {
        while((p2=fork()) == -1);

        if(!p2)
        {
            while ((p4=fork())==-1);
            if (!p4)
            {
                while(1)
                {
                    printf("p4 is p2's child with pid %d, ppid %d.\n",getpid(),getppid());
                    //wait(0);
                }
            }
            else
            {
                while ((p5=fork())==-1);

                if (!p5)
                {
                    while(1)
                    {
                        printf("p5 is p2's child with pid %d, ppid %d.\n",getpid(),getppid());
                        //wait(0);
                    }

                }
                else
                {
                    ;
                }

            }

            while(1)
            {
                printf("p2 is p1's child with pid %d,ppid %d.\n",getpid(),getppid());
                
            }
        }
        else
        {
            while ((p3=fork())==-1);

                if(!p3)
                {
                    while(1)
                    {
                        printf("p3 is p1's child with pid %d, ppid %d.\n",getpid(),getppid());
                        //wait(0);
                    }

                }
        
           else
          {
            ;
        }
}
        while(1)
        {
            printf("p1 is parent with pid %d, ppid %d.\n",getpid(),getppid());
            //wait(0);
        }
    }
    else
    {
        ;
    }

    return 0;
}


```

结果如图  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.11.png)  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.8.png)  
可以看见p1进程号为9635，父进程号1410  
可以看见p2进程号为9636，父进程号9535  
可以看见p3进程号为9637，父进程号9535  
可以看见p5进程号为9639，父进程号9536  
可以看见p4进程号为9638，父进程号9536  
out4为进程2正常运行的进程树  
当用kill -9停止进程2时结果如图  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.7.png)
out4为进程树  
当用exit(0)停止进程2时的结果如图  
![Image text](https://github.com/ToTkr2/Lab2/blob/master/img/2.6.png)
out5为进程树  
