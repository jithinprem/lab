#include<stdio.h>

int a[5];
int empty = 5;
int full =0;
int mutex =1;


void wait(int *m){
    if(*m>0)
        *m = *m-1;
    //printf("new val - %d\n", *m);
}
void signal(int *m){
    *m = *m+1;
}

int main(){


    while(1){

        int x;
        printf("\n\n");
        printf("empty : %d ,  full : %d ,  mutex : %d ,  \n", empty, full, mutex);
        printf("1. produce    2.consume  \n");
        scanf("%d", &x);

        if(x ==1){
            if(empty != 0 && mutex ==1){
                printf(" enter data : ");
                wait(&empty);
                wait(&mutex);
                scanf("%d", &a[full]);
                signal(&mutex);
                signal(&full);
            }
            else{
                printf("the buffer is full .. \n");
            }
        }
        else if(x==2){
            if(full > 0 && mutex==1){
                wait(&full);
                wait(&mutex);
                printf("data : ");
                signal(&mutex);
                signal(&empty);
            }
            else{
                printf("buffer empty ... \n");
            }
        }
        else{
            break;
        }

    }

}
