#include<stdio.h>
// no. of processes = n
// each process is given with the req (3 resources), alloc, need  // use structure

struct Process{
    int req[3];   // the total required to execute
    int alloc[3]; // already allocated
    int need[3];  // req - alloc
    int fin_status; //finish status
    int pid;
};
struct Process p[10];
int resource[3];
int fin_seq[20];
int k=0;

void arrInput(int A[], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
}

int input(){
    // function used to input values
    // take no. of processes and loop in it, retrive the req and alloc, calc need on the way
    int n;
    printf("How many processes : ");
    scanf("%d", &n);


    for(int i=0; i<n; i++){
        p[i].pid = i;
        printf("\nAllocated: \n");
        arrInput(p[i].alloc, 3);

        printf("Max for %d process: \n", i);
        arrInput(p[i].req , 3);



        p[i].need[0] = p[i].req[0]-p[i].alloc[0];
        p[i].need[1] = p[i].req[1]-p[i].alloc[1];
        p[i].need[2] = p[i].req[2]-p[i].alloc[2];
        printf("The requirement is : %d, %d, %d  \n", p[i].need[0], p[i].need[1], p[i].need[2]);
    }
    return n;
}

int execute(int i){
    for(int j=0; j<3; j++){
        if(p[i].need[j] > resource[j]){
            //printf("process %d not executed !\n", i);
            return 0;
        }
    }
    //printf("process %d completed successfully ! \n", p[i].pid);
    resource[0] = resource[0] + p[i].alloc[0];
    resource[1] = resource[1] + p[i].alloc[1];
    resource[2] = resource[2] + p[i].alloc[2];
    p[i].fin_status = 1;
    fin_seq[k++] = i;
    return 1;
}

int main(){
    printf("enter the resource available (3 resources) : \n");
    arrInput(resource, 3);
    int n = input();
    int change_made =0;
    int no_completed = 0;
    do{
            change_made = 0;
            for(int i=0; i<n; i++){
                if(p[i].fin_status != 1)
                    change_made = change_made + execute(i);
            }
            no_completed = no_completed + change_made;

    }while(change_made !=0);

    if(no_completed == n){
        printf("\nsafe sequence : ");
        for(int i=0; i< n; i++){
            printf("%d  ",fin_seq[i]);
        }
        printf("\n\n");
    }
    else{
        printf("no safe sequence exist ! ");
    }

}
