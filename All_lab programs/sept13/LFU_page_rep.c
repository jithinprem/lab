#include <stdio.h>

//no_f = no of frames
//str_len = length of input string
//str[] = input string
//frame_arr[] = frames, -1 means unoccoupied


int Present(int val, int arr[], int n){
    for(int i=0; i<n; i++){
        if(val == arr[i])
            return 1;
    }
    return 0;
}

int There_is_space(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i] == -1){
            return i;
        }
    }
    return -1;
}

int print_val(int frame_size, int frame_arr[]){
     for(int j=0; j<frame_size; j++){
        if(frame_arr[j]== -1){
            printf("%c  ", '-');
        }
        else
            printf("%d  ", frame_arr[j]);
    }
        printf("\n");
}

int tozero(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = 0;
    }
}

int ret_zero(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            return i;
        }
    }
    return -1;
}

int Lfu(int str_len, int str[], int no_f, int frame_arr[]){
        int freq_list[100];
        int rem_pointer =-1;

        tozero(freq_list, 100);

        for(int i=0 ; i<str_len; i++){
            freq_list[str[i]] += 1;

            if( Present(str[i], frame_arr, no_f) == 1){     //checking if the page is present
                printf("present\n");
            }
            else{

                int sp = There_is_space(frame_arr, no_f);
                if( sp >= 0){
                    //add it to space
                    frame_arr[sp] = str[i];
                    print_val(no_f, frame_arr);
                }
                else{
                    //find the least frequently used and delete
                    int min = freq_list[frame_arr[0]];
                    int min_ind =0;
                    for(int i=0; i<no_f; i++){
                        if(min > freq_list[frame_arr[i]])
                            min_ind = i;
                    }

                    frame_arr[min_ind] = str[i];

                    print_val(no_f, frame_arr);
                }

            }
    }

}

int main() {


    //ref_ string
    int str[100] = {1,7,4,7,3,1,1,3};
    int str_len;
    //no_frame
    int no_f;
    int frame_arr[20];

    for(int i=0; i<20; i++){
        frame_arr[i] = -1;
    }

    printf("length of ref_ string : ");
    scanf("%d", &str_len);

    printf("ref_ string : ");
    for(int i=0; i<str_len ; i++){
        scanf("%d", &str[i]);
    }

    printf("enter no_of frames : ");
    scanf("%d", &no_f);

    Lfu(str_len, str, no_f, frame_arr);




}
