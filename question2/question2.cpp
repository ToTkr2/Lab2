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
