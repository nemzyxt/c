//Author : Nemuel Wainaina
//This program showcases the various operations and functions on strings in C programming language

#include<stdio.h>
#include<string.h>

int main(){
	char fname[15], lname[15];
	char str3[40];
	
	printf("Enter your First Name : ");
	scanf("%s", fname);
	printf("Enter your Last Name : ");
	scanf("%s", lname);
	
	printf("Size of fname : %d\n", strlen(fname));
	printf("Size of lname : %d\n", strlen(lname));
	
	strcpy(str3, fname);
	printf("strcpy(str3, fname) : %s\n", str3);
	
	printf("strcmp(fname, lname) : %d\n", strcmp(fname, lname));
	
	return 0;
}