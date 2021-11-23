//Author : Nemuel Wainaina
//This is a Program that  takes marks for the seven units from the user
//grades them, and saves the unit name, marks and the grade for the unit in a text file


#include<stdio.h>
#include<stdlib.h>

//this function takes the marks as input and grades it according to the grading system in place
char* grade_for(int marks){
    if(marks>=0 && marks<40){
        return "F";
    }
    else if(marks>=40 && marks<50){
        return "D";
    }
    else if(marks>=50 && marks<60){
        return "C";
    }
    else if(marks>=60 && marks<70){
        return "B";
    }
    else if(marks>=70 && marks<=100){
        return "A";
    }
    else{
        return "INVALID";
    }
}

int main(){
    //welcoming text, haha!
    printf("Welcome to the Program ... \n");

    //the arrays for units, marks and the grades
    char* units[7]={"CSC111", "CSC112", "CSC113", "CSC114", "CSC115", "CCS001", "CCS009"};
    int marks[7];
    char* grades[7];

    //let's get the marks from the user
    for(int i=0;i<7;i++){
        printf("Enter the marks for unit %s : ", units[i]);
        scanf("%d", &marks[i]);
    }

    //let's grade the marks entered above and store the grades in array grades
    for(int i=0;i<7;i++){
        grades[i]=grade_for(marks[i]);
    }

    //time to store the values into a file
    FILE* fp = fopen("graded marks.txt", "w");
    if(fp==NULL){
        exit(1);
    }

    //writing the results to the text file
    fprintf(fp, "UNIT\t\tMARKS\t\tGRADE\n");
    for(int i=0;i<7;i++){
        fprintf(fp, "%s\t\t%d\t\t%s\n", units[i], marks[i], grades[i]);
    }
    //close the file pointer
    fclose(fp);

    return 0;
}

