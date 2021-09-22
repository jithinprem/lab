#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    printf("process A (pid): %d\n",getpid());
    int b_id = fork();
    if(b_id == 0){
        printf("process B (pid): %d, Parent pid: %d\n",getpid(),getppid());
        int d_id = fork();
        if(d_id == 0){
            printf("process D, (pid): %d, Parent pid: %d\n",getpid(),getppid());
            int h_id = fork();
            if(h_id == 0){
                printf("process H, (pid): %d, Parent pid: %d\n",getpid(),getppid());
                int i_id = fork();
                if(i_id == 0){
                    printf("process I, (pid): %d, Parent pid: %d\n",getpid(),getppid());
                }
            }
        }
        else{
            int e_id = fork();
            if(e_id == 0){
                printf("process E, (pid): %d, Parent pid: %d\n",getpid(),getppid());

            }else{
                int f_id = fork();
                if(f_id == 0){
                    printf("process F, (pid): %d, Parent pid: %d\n",getpid(),getppid());

                }
            }
        }
    }else{
        int c_id = fork();
        if(c_id == 0){ //  C
            printf("process C (pid): %d, Parent pid: %d\n",getpid(),getppid());
            int g_id = fork();
            if(g_id == 0){ // G
                printf("process G (pid): %d, Parent pid: %d\n",getpid(),getppid());
            }
        }
    }
    wait(NULL);
    return 0;
}
