//Author : Nemuel Wainaina
//This is Simple program that enables the user to be able to convert temperature from degrees to celsius and vice versa

//include the header files
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//function to convert temperature from celsius to fahrenheit
void celsius2Fahrenheit(){
    printf("Enter the Temperature in Celsius : ");
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = (celsius*1.8)+32;
    printf("The Temperature in Fahrenheit is %.2f\n", fahrenheit);
}

//function to convert temperature from fahrenheit to celsius
void fahrenheit2Celsius(){
    printf("Enter the Temperature in Celsius : ");
    float fahrenheit;
    scanf("%f", &fahrenheit);
    float celsius = (fahrenheit-32)/1.8;
    printf("The Temperature in  Celsius is %.2f\n", celsius);
}

//The main function where program execution starts
int main(){
    printf("Welcome to the Program ... \n");

    //for the program to sleep for 2 seconds before proceeding with execution of the other statements
    Sleep(2000);

    int exit=0;

    //loop to constantly prompt the user for temperature values to convert
    do{
        system("cls");
        printf("\t1. Celsius To Fahrenheit\n");
        printf("\t2. Fahrenheit To Celsius\n");
        printf("Choose your conversion : ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
        case 1:
            celsius2Fahrenheit();
            break;
        case 2:
            fahrenheit2Celsius();
            break;
        }
        printf("\nWould you like to exit ?\n\t1. Yes\n\t2. No\n>>>");
        scanf("%d", &exit);
    }while(exit==2);

    //to close the terminal
    system("exit");

    return 0;
}
