//Author : Nemuel Wainaina
//This program takes 2 numbers as input from the user, it then swaps the values by use of pointers, then prints the values after having swapped them

#include<stdio.h>

void swap(int*, int*);

int main(){
	int a, b;
	
	printf("Enter value of a : ");
	scanf("%d", &a);
	printf("Enter value of b : ");
	scanf("%d", &b);
	
	printf("\nBefore Swapping :\n\t");
	printf("a = %d , b = %d", a, b);
	swap(&a, &b);
	printf("\nAfter Swapping :\n\t");
	printf("a = %d , b = %d\n", a, b);
	
	return 0;
}

void swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}