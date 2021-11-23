//Author : Nemuel Wainaina
//This is a simple program that takes input as length in feet from the user, converts the length into metres, and prints it to the user

#include<stdio.h>
#include<windows.h>

int main(){
    printf("Welcome ...\n\n");
    Sleep(2000);
    printf("Enter the Length in Feet : ");
    float feet;
    scanf("%f", &feet);
    float metres=feet*0.3048;
    printf("\nThe Length is %f Metres\n", metres);
    return 0;
}
