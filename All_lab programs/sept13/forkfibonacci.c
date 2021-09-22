#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void fibonacci(int inp){

   int a=0, b=1;
   int n=a+b;
   int i=inp;

   pid_t pid = fork();
   if(pid == 0){
       printf("This is child process :\n ");
       printf(" %d ", n);
       while(i>0){
           n = a+b;
           printf("%d ", n);
           a=b;
           b=n;
           i--;
           if(i==0){
               printf("child ended.....\n");
           }
       }
   }
   else{
       waitpid(pid, NULL, 2);
       printf("this is parent process.. \n");
       int count =0;
       for(int i=1; i>0; i++){
           int t =0;
           for(int j=i; j>0 ;j--){
               if(i%j == 0){
                   t++;
               }
           }
           if(t == 2){
               printf(" %d ", i);
               count++;
               //printf("(%d) ", count);
           }
           if(count == inp){
               break;
           }
       }


       printf("parent process ends now....\n");
   }


}
int main(){
    int i;
    printf("enter your number : \n");
    scanf("%d", &i);
    fibonacci(i);

}
