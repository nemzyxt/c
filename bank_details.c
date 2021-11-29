//Author : Nemuel Wainaina
//This is a simple program that takes information of the 5 customers, saves it to a text file, and also prints the information to the screen

#include<stdio.h>

int main(){
    start:
    //Get the number of customers from the user
    printf("=============================================================================\n");
    printf("[*] Enter the Number of Customers whose information you want to enter : ");
    int n;
    scanf("%d", &n);

    //Ensure it's at least 5
    if(n<5){
        printf("\n[-] You are required to enter information for at least 5 customers !\n");
        Sleep(2000);   //sleep for 2 seconds
        system("cls"); //clear the console screen
        goto start;    //go back to the beginning of the program
    }

    //Declare the arrays to hold the customers' data
    char f_names[n][16];
    char l_names[n][16];
    int account_numbers[n];
    int account_balances[n];

    //Let's take the input from the user(s)
    for(int i=0;i<n;i++){
        printf("\n---------------------------------CUSTOMER %d---------------------------------\n", i+1);
        printf("Enter the First Name : ");
        scanf("%s", f_names[i]);
        printf("Enter the Last Name : ");
        scanf("%s", l_names[i]);
        printf("Enter the Account Number : ");
        scanf("%d", &account_numbers[i]);
        printf("Enter the Account Balance : ");
        scanf("%d", &account_balances[i]);
    }

    //Let's store the above information in a file called bank_details.txt
    //First create a pointer to the file that we want to write to
    FILE* fp = fopen("bank_details.txt", "w");
    //Check for any error in trying to open the file
    if(fp == NULL){
        printf("Could not open the file !");
        exit(1);
    }

    //Now let us feed the above information into the file
    fprintf(fp, "  NAME\t\t\t\tACCOUNT_NUMBER\t\tACCOUNT_BALANCE\n");
    for(int i=0;i<n;i++){
        fprintf(fp, "%d.%s %s\t\t\t%d\t\t\t%d\n", i+1, f_names[i], l_names[i], account_numbers[i], account_balances[i]);
    }

    //Print a success message after successfully writing the information to the file
    printf("\n[+] Successfully written the information to file : bank_details.txt\n\n");
    printf("-----------------------------------------------------------------------------\n");

    //let us now close the file pointer
    fclose(fp);

    //Print out the details that we have stored on the screen as well
    printf("  NAME\t\t\t\tACCOUNT_NUMBER\t\tACCOUNT_BALANCE\n");
    for(int i=0;i<n;i++){
        printf("%d.%s %s\t\t\t\t%d\t\t\t%d\n", i+1, f_names[i], l_names[i], account_numbers[i], account_balances[i]);
    }

    return 0;
}
