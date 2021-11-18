//Author : Nemuel Wainaina

/*
 *This program takes in 3 values as 
 *input from the user, determines the
 *maximum, and prints it back to the
 *user
*/

#include<stdio.h>

int get_max(int a, int b, int c){
	if(a==b){
		if(a>c){
			return a;
		}
		else if(a==c){
			printf("The three numbers are equal.");
			exit(0);
		}
		else{
			return c;
		}
	}
	
	if(b==c){
		if(a>b){
			return a;
		}
		else if(a==c){
			printf("The three numbers are equal");
			exit(0);
		}
		else{
			return b;
		}
	}
	
	if(a==c){
			if(a>b){
			return a;
		}
		else if(a==b){
			printf("The three numbers are equal.");
			exit(0);
		}
		else{
			return b;
		}
	}
	
	if(a>b){
		if(a>c){
			return a;
		}
		else{
			return c;
		}
	}
	else{
		if(b>c){
			return b;
		}
		else{
			return c;
		}
	}
}

int main(){
	int a, b, c;
	printf("Enter the first number : ");
	scanf("%d", &a);
	printf("Enter the second number : ");
	scanf("%d", &b);
	printf("Enter the third number : ");
	scanf("%d", &c);
	
	int max=get_max(a, b, c);
	printf("\nThe Greatest of the 3 numbers is : %d\n", max);
	
	return 0;
}