// Online C compiler to run C program online
#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    int n;
    printf("enter n : ");
    scanf("%d", &n);

  for(int i=0;i<n;i++)
	{
		if(fork() == 0)
		{
			printf("pid(child) %d from parent(parent) %d\n",getpid(),getppid());
			//exit(0);

		}
	}
	for(int i=0;i<5;i++) // loop will run n times (n=5)
        wait(NULL);

}
