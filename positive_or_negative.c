//Author : Nemuel Wainaina
//This is a simple program that takes a number as input from the user, and prints back to the user
//whether the number is positive or negative

#include<stdio.h>

int main(){
    printf("Enter a number : ");
    int num;
    scanf("%d", &num);
    if(num>=0){
        printf("%d is a Positive Number .", num);
    }
    else{
        printf("%d is a Negative Number .", num);
    }
    return 0;
}
