//Author : Nemuel Wainaina

/*
 *This program takes a number as 
 *input from the user, and 
 *determines whether or not it is
 *prime, then prints the conclusion
 *to the user
 */
 
 #include<stdio.h>
 
 int main(){
 	int num, factors=0;
 	printf("Enter a number : ");
 	scanf("%d", &num);
 	for(int i=1;i<=num;i++){
 		if(num%i==0){
 			factors++;
 		}
 	}
 	
 	if(factors==2){
 		printf("The number %d is a Prime Number.\n", num);
 	}
 	else{
 		printf("The number %d is Not a Prime Number.\n", num);
 	}
 	
 	return 0;
 }
 