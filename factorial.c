//Author : Nemuel Wainaina

/*
*This program takes a number as 
*input from the user, calculates its 
*factorial, then prints it to the user
*/

#include<stdio.h>

int factorial(int a){
	if(a<=1){
		return 1;
	}
	else{
		return a * factorial(a-1);
	}
}

int main(){
	int num, fact;
	printf("Enter a Number : ");
	scanf("%d", &num);
	fact=factorial(num);
	printf("The factorial of %d is : %d\n", num, fact); 
	return 0;
}