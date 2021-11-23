//Author : Nemuel Wainaina
//A simple calculator that performs arithmetic operations on two values supplied by the user

#include<stdio.h>

int add(int, int);
int sub(int, int);
int mult(int, int);
int div(int, int);
int mod(int, int);

int main(){
	printf("Welcome ...\n");
	int sum, diff, prod, quotient, rem;
	int a, b;
	printf("Enter the first Number : ");
	scanf("%d", &a);
	printf("Enter the second Number : ");
	scanf("%d", &b);
	sum=add(a, b);
	diff=sub(a, b);
	prod=mult(a, b);
	quotient=div(a, b);
	rem=mod(a, b);
	
	printf("\nSum of %d and %d is : %d\n", a, b, sum);
	printf("Difference of %d and %d is : %d\n", a, b, diff);
	printf("Product of %d and %d is : %d\n", a, b, prod);
	printf("%d divided by %d : %d remainder %d\n\n", a, b, quotient, rem);
	
	return 0;
}

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	if(a>=b){
		return a-b;
	}
	else{
		return b-a;
	}
}

int mult(int a, int b){
	return a*b;
}

int div(int a, int b){
	if(b==0){
		printf("Cannot divide a Number by Zero !");
		exit(1);
	}
	return a/b;
}

int mod(int a, int b){
	return a%b;
}