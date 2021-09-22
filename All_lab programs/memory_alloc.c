#include<stdio.h>
struct Process{
    int blockocc;
    int mem_req;
    int occ_status;
};

struct Process p[20];

int total_memory= 2000;
int no_part = 0;
int part[20];

int set_memory(){
    int tot_mem = 2000;

    printf("max memory = 2000k\n\n");

    for(int i=0; i<20; i++){
        printf("enter memory partition size %d : \n", i+1);
        scanf("%d", &part[i]);
        tot_mem = tot_mem-part[i];
        if(tot_mem == 0){
            no_part =i+1;
            return 1;
        }
        else if(tot_mem < 0){
            printf("memory partition size exceeded ! \n");
            return 0;
        }
    }
    printf("max no. of partition exceeded ! \n");
    return 0;
}

int bestfit(int no_process){

    for(int i=0; i<no_process; i++){
        printf("enter memory req by process %d  : ", i+1);
        scanf("%d", &p[i].mem_req);

        int placed =0;
        int min_ind =-1;
        int min_val =5000;

        for(int j=0; j<no_part; j++){

            if(part[j] >= p[i].mem_req){

                int diff = part[j]-p[i].mem_req;
                if(diff < min_val){
                    min_val = diff;
                    min_ind = j;
                }

            }
        }
        if(min_val != 5000){
                part[min_ind] = part[min_ind]-p[i].mem_req;
                p[i].blockocc = min_ind;
                p[i].occ_status = 1;
                placed =1;
        }
        else if (placed == 0 ){
            printf("process cannot be accomodated ! \n");
        }
    }

    printf("\nThe process allocated at blocks : \n");
    for(int i=0; i<no_process; i++){
        if(p[i].occ_status == 1)
            printf(" process %d occoupied %d\n", i+1 ,p[i].blockocc+1);
    }
}

int worstfit(int no_process){

    for(int i=0; i<no_process; i++){
        printf("enter memory req by process %d  : ", i+1);
        scanf("%d", &p[i].mem_req);

        int placed =0;
        int max_ind =-1;
        int max_val =-5000;

        for(int j=0; j<no_part; j++){

            if(part[j] >= p[i].mem_req){

                int diff = part[j]-p[i].mem_req;
                if(diff > max_val){
                    max_val = diff;
                    max_ind = j;
                }

            }
        }
        if(max_val != -5000){
                part[max_ind] = part[max_ind]-p[i].mem_req;
                p[i].blockocc = max_ind;
                p[i].occ_status = 1;
                placed =1;
        }
        else if (placed == 0 ){
            printf("process cannot be accomodated ! \n");
        }
    }

    printf("\nThe process allocated at blocks : \n");
    for(int i=0; i<no_process; i++){
        if(p[i].occ_status == 1)
            printf(" process %d occoupied %d\n", i+1 ,p[i].blockocc+1);
    }

}

int nextfit(int no_process){

}

int firstfit(int no_process){

    for(int i=0; i<no_process; i++){
        printf("enter memory req by process %d  : ", i+1);
        scanf("%d", &p[i].mem_req);

        int placed =0;
        for(int j=0; j<no_part; j++){

            if(part[j] >= p[i].mem_req){
                part[j] = part[j]-p[i].mem_req;
                p[i].blockocc = j;
                p[i].occ_status = 1;
                placed =1;
                break;
            }
        }
        if(placed == 0){
            printf("process cannot be accomodated ! \n");
        }

    }
    printf("\nThe process allocated at blocks : \n");
    for(int i=0; i<no_process; i++){
        if(p[i].occ_status == 1)
            printf(" process %d occoupied %d\n", i+1 ,p[i].blockocc+1);
    }
}

int select_algo(){
    int sel;
    printf("enter preferred allocation method :\n 1)firstfit\n 2)bestfit\n 3)worstfit\n ");
    scanf("%d", &sel);

    int no_process;
    printf("enter no. of processes : ");
    scanf("%d", &no_process);

    switch(sel){
        case 1:
            firstfit(no_process);
            break;
        case 2:
            bestfit(no_process);
            break;
        case 3:
            worstfit(no_process);
            break;
        case 4:
            nextfit(no_process);
            break;

    }

}


int main(){

    //while(1){
        int set_mem_st;
        if(set_memory()){
            select_algo();
        }
        else{
            printf("error !!");
        }

    //}

}
