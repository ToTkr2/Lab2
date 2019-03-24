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
            exit(0);
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

