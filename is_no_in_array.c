//Author : Nemuel Wainaina
//This is a program that checks whether the number entered by the user is present in the array

#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    //First print the array
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    printf("\nEnter the number to check whether it is in the array : ");
    int num;
    scanf("%d", &num);
    int flags=0;
    //search for its occurrence in the array
    for(int i=0;i<5;i++){
        if(arr[i]==num){
            printf("The number is present in the array, at index %d\n", i);
            exit(0);
        }
    }
    printf("The number is not present in the array !\n");
    return 0;
}

