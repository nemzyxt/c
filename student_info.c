//Author : Nemuel Wainaina

/*The program takes input from the user of 5 students, this information includes the student names, registration number, age and marks for the 7 subjects
 *the information is then saved to a file called students.txt
 *the content is then displayed on the screen
*/

#include<stdio.h>

typedef char string[50];

//structure to hold the students' details
typedef struct{
    string names;
    string reg_number;
    int age;
    int marks[7];
}Student;

int main(){
    char* units[7] = {"CSC111", "CSC112", "CSC113", "CSC115", "CCS001", "CCS009", "CSC126"}; //An array of the seven units

    Student students[2]; //defining an array of 5 student structures

    //Time to take input from the user for the 5 students
    for(int i=0;i<2;i++){
        printf("\n----------------#Student %d----------------\n", i+1);
        printf("Name : ");
        fscanf(stdin, " %[^\n]s", students[i].names);
        printf("Registration Number : ");
        scanf("%s", students[i].reg_number);
        printf("Age : ");
        scanf("%d", &students[i].age);
        printf("Marks ...\n");
        for(int j=0;j<7;j++){
            printf("\tUnit %s : ", units[j]);
            scanf("%d", &students[i].marks[j]);
        }
    }

    //Saving the information to a file
    FILE* fp = fopen("students.txt", "w");
    for(int i=0;i<2;i++){
        fprintf(fp, "%s\n", students[i].names);
        fprintf(fp, "%s\n", students[i].reg_number);
        fprintf(fp, "%d\n", students[i].age);
        //the marks now ...
        for(int j=0;j<7;j++){
            fprintf(fp, "%d\n", students[i].marks[j]);
        }
    }

    //Closing pointer to the file
    fclose(fp);

    printf("\n-----------------------------------------------------------------------------------------------\n");

    //Printing to the screen
    for(int i=0;i<2;i++){
        printf("\n----------------#Student %d----------------\n", i+1);
        printf("Name : %s\n", students[i].names);
        printf("Registration Number : %s\n", students[i].reg_number);
        printf("Age : %d\n", students[i].age);
        printf("Marks ...\n");
        for(int j=0;j<7;j++){
            printf("\tUnit %s : %d\n", units[j], students[i].marks[j]);
        }
    }

    printf("\n-----------------------------------------------------------------------------------------------\n");

    return 0;
}
