//Author : Nemuel Wainaina
//This is a simple book store program

#include<stdio.h>
#include<windows.h>

//the file name
#define FILENAME "book_details.txt"

//declaring the book structure
typedef struct{
    char title[25];
    char author[25];
    int quantity;
    int price;
}Book;

//function to add book details
void add_book(Book* bk){
    printf("\tAdd Book Details ...\n");
    printf("----------------------------\n");
    printf("Enter the Book Title : ");
    scanf("%s", bk->title);
    printf("Enter the Book Author : ");
    scanf("%s", bk->author);
    printf("Enter the Book Quantity : ");
    scanf("%d", &bk->quantity);
    printf("Enter the Price of the Book : ");
    scanf("%d", &bk->price);
    if(bk->quantity <= 0){
        printf("[!] Error : Invalid Book Quantity - Can only be greater than or equal to one!\n");
        system("cls");
        add_book(bk);
    }
}

//function to save book details to a file
void save_book_details(Book bk){
    FILE* fp = fopen(FILENAME, "a");
    if(fp == NULL){
        printf("[!] An error occurred while trying to open the file ... \n");
        exit(1);
    }
    fprintf(fp, "%s\n", bk.title);
    fprintf(fp, "%s\n", bk.author);
    fprintf(fp, "%d\n", bk.quantity);
    fprintf(fp, "%d\n", bk.price);
}

//function to get the total number of books in the store
int get_number_of_books(){
    FILE* fp = fopen(FILENAME, "r");
    Book bk;
    int i = 0;
    while(!feof(fp)){
        //read the details from the file
        fscanf(fp, "%s", bk.title);
        fscanf(fp, "%s", bk.author);
        fscanf(fp, "%d", &bk.quantity);
        fscanf(fp, "%d", &bk.price);
        //update the value of i
        i+=bk.quantity;
    }
    return i-1;
}

//get number of different books in store
int book_number(){
    FILE* fp = fopen(FILENAME, "r");
    Book bk;
    int i = 0;
    while(!feof(fp)){
        //read the details from the file
        fscanf(fp, "%s", bk.title);
        fscanf(fp, "%s", bk.author);
        fscanf(fp, "%d", &bk.quantity);
        fscanf(fp, "%d", &bk.price);
        //update the value of i
        i+=1;
    }
    return i-1;
}

//function to extract and print out the book details saved in the file
void extract_bk_details(){
    printf("\t Book Details : \n");
    printf("---------------------------\n");
    FILE* fp = fopen(FILENAME, "r");
    if(fp == NULL){
        printf("[!] An error occurred while trying to open the file ... \n");
        exit(1);
    }
    Book bk;
    int bk_num = book_number();
    for(int i=0;i<bk_num;i++){
        //read the details from the file
        fscanf(fp, "%s", bk.title);
        fscanf(fp, "%s", bk.author);
        fscanf(fp, "%d", &bk.quantity);
        fscanf(fp, "%d", &bk.price);

        //print them on the console screen
        printf("{%d} .\n", i+1);
        printf(" Book Title : %s\n", bk.title);
        printf(" Book Author : %s\n", bk.author);
        printf(" Book Quantity : %d\n", bk.quantity);
        printf(" Book Price : %d\n", bk.price);
    }
}


//just a function to print a simple menu to the user, and get the user's option
int print_menu(){
    printf("\n----------------------------\n");
    printf("\tMENU :\n");
    printf("-----------------\n");
    printf("1. Add book details.\n");
    printf("2. View books details.\n");
    printf("3. View total number of books\n");
    printf("4. Exit\n");
    printf("Please enter the desired task :: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 4){
        exit(0);
    }
    if(choice<1 || choice>4){
        printf("Invalid Selection !!!");
        system("cls");
        print_menu();
    }
    return choice;
}

//the main function where execution of the program starts
int main(){
    printf("Welcome ...\n");

    //A structure used for holding data on the  book details
    Book b1;

    while(1){
        int option = print_menu();
        //printf("The selected option is %d", option);
        switch(option){
        case 1:
            //take the book details from the user, then save them to the file
            add_book(&b1);
            save_book_details(b1);
            printf("[+] Book Details Saved!\n\n");
            print_menu();
            break;
        case 2:
            extract_bk_details();
            break;
        case 3:
            printf("===================================================\n");
            //get the total number of books from the information that's saved in the file, and print it to the user
            printf("[+] The Total Number of Books is : %d", book_number());
            printf("\n===================================================\n");
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
