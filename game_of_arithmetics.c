//Author : Nemuel Wainaina

/*
 *This is the Question :

 *Create a game that will help primary school children practice with arithmetic.
 *The program should have a menu that the learner will choose what operation
 *they want to practice with (Addition, subtraction, division and multiplication).
 *The learner should be able to choose the level he wants to play with.
 *Low level has numbers between 1-10, mid-level has numbers between 11-50 and high level has numbers between 51-100).
 *Once the learner chooses the levels, and the operation to practice with,
 *the program should generate two random numbers for the learner to give an answer to the operation selected.
 *If the answer is correct the learner earns a 1 point.
 *If the answer is wrong the program should display the correct answer to the learner.
 *The program should enable the learner play as many times as they wish. When the learner has finished playing,
 *the program should be able to display the total points earned.
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//This is the function that prints to the user a list of the possible operations that can be carried out
//and then the user gets to select the operation they wish to carry out
int choose_operation(){
    printf("\tOPERATIONS ::\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("4. Multiplication\n");
    printf("4. Division\n\n");
    printf("Select the type of operation you would like to do [1, 2, 3, 4]: ");
    int operation;
    scanf("%d", &operation);
    printf("\n");
    return operation;
}

int choose_level(){
    printf("\tLEVELS ::\n");
    printf("1. Low-level [1-10]\n");
    printf("2. Mid-level [11-50]\n");
    printf("3. High-level [50-100]\n\n");
    printf("Select the level you want to play [1, 2, 3] : ");
    int level;
    scanf("%d", &level);
    printf("\n");
    return level;
}

//This function generates 2 random numbers based on the specification of the user
//and returns them as an array of 2 numbers, which will be received by a pointer in the calling end
int* rand_num(int level){
    srand(time(NULL));
    static int nums[2];
    switch(level){
    case 1:
        nums[0]=rand()%10+1;
        nums[1]=rand()%10+1;
        break;
    case 2:
        nums[0]=rand()%39+11;
        nums[1]=rand()%39+11;
        break;
    case 3:
        nums[0]=rand()%49+51;
        nums[1]=rand()%49+51;
        break;
    }
    return nums;
}

//This function takes 2 numbers as input and returns the sum of the 2 numbers
int add(int a, int b){
    return a+b;
}

//This function takes 2 numbers as input and returns the difference between the 2 numbers
int subtract(int a, int b){
    if(a>=b){
        return a-b;
    }
    else{
        return b-a;
    }
}

//This function takes 2 numbers as input and returns the product of the 2 numbers
int mult(int a, int b){
    return a*b;
}

//This function takes 2 numbers as input and returns the result of dividing the 2 numbers by each other
float divide(int a, int b){
    if(a>=b){
        return (float)a/b;
    }
    else{
        return (float)b/a;
    }
}

//The main function, where actual program execution starts
//and where the main logic of the program is going to be contained
int main(){
    //This is a variable which will be containing the total number of points awarded to the player for each correct answer given
    int points=0;

    //variable to track the number of rounds the user plays the game
    int round=0;

    int user_att;//variable to store the user attempt

    int operation, level;//Variables to hold user's choice of the level and operation to work with

    int* nums;//pointer to integer which will be used to store the 2 random numbers generated in rand_num function

    int result;//to store output from the functions carrying out the arithmetic operations
    float result2;//this is the variable we are going to use to store the result of the division operation as it returns a float as the result

    int play=1;

    GAMEPLAY_LOOP:
    do{
        //To clear the console screen before another game play
        system("cls");
        //welcome to the game
        printf("******************************************************\n");
        printf("\t\tWELCOME TO THE GAME...\n");
        printf("\t\t#Developed by Nemuel Wainaina\n\t\tGitHub : nemzyxt\n");
        printf("******************************************************\n");

        round++;
        printf("\n@Round :: %d\n\n", round);

        //Let us get the level the user would like to play in
        level=choose_level();

        //a basic if statement to make sure that the user selects a level within rang, between 1 and 3
        if(level<1 || level>3){
            continue;
        }

        //Now let us get the 2 random numbers in that level
        nums=rand_num(level);
        //Now let us get the operation that the user would like to execute
        operation=choose_operation();

        //Now, let us use the switch to decide on which operation we are going to actually do
        switch(operation){
        case 1:
            result=add(nums[0], nums[1]);
            printf("The random numbers generated are : %d and %d\n", nums[0], nums[1]);
            printf("What is the Sum of %d and %d ? ", nums[0], nums[1]);
            scanf("%d", &user_att);
            if(user_att==result){
                points++;
                printf("The answer is Correct!\nYour Total Points are now : %d\n\n", points);
            }
            else{
                printf("The answer is Incorrect.\n");
                printf("The Correct answer is : %d\n\n", result);
            }
            break;
        case 2:
            result=subtract(nums[0], nums[1]);
            printf("The random numbers generated are : %d and %d\n", nums[0], nums[1]);
            printf("What is the Difference of %d and %d ? ", nums[0], nums[1]);
            scanf("%d", &user_att);
            if(user_att==result){
                points++;
                printf("The answer is Correct!\nYour Total Points are now : %d\n\n", points);
            }
            else{
                printf("The answer is Incorrect.\n");
                printf("The Correct answer is : %d\n\n", result);
            }
            break;
        case 3:
            result=mult(nums[0], nums[1]);
            printf("The random numbers generated are : %d and %d\n", nums[0], nums[1]);
            printf("The Product of the numbers is : %d\n", result);
            printf("What is the Product of %d and %d ? ", nums[0], nums[1]);
            scanf("%d", &user_att);
            if(user_att==result){
                points++;
                printf("The answer is Correct!\nYour Total Points are now : %d\n\n", points);
            }
            else{
                printf("The answer is Incorrect.\n");
                printf("The Correct answer is : %d\n\n", result);
            }
            break;
        case 4:
            result2=divide(nums[0], nums[1]);
            float user_att2;
            printf("The random numbers generated are : %d and %d\n", nums[0], nums[1]);
            printf("What is the result of Dividing %d and %d ? ", nums[0], nums[1]);
            scanf("%f", &user_att2);
            if(user_att2==result2){
                points++;
                printf("The answer is Correct!\nYour Total Points are now : %d\n\n", points);
            }
            else{
                printf("The answer is Incorrect.\n");
                printf("The Correct answer is : %f\n\n", result2);
            }
            break;
        default:
            printf("Incorrect input !!!\n");

        }

        printf("\n******************************************************\n");

        printf("\nWould you like to play again ?\n\t1. Yes\n\t2. No\n>>> ");
        scanf("%d", &play);
    }while(play==1);

    printf("\n\n------------------------------------------------------\n");
    printf("\n\tTotal Points Earned : %d", points);
    printf("\n\n******************************************************\n");
    printf("\tHope you enjoyed the Game!\n");
    printf("\t#Nemuel");
    printf("\n******************************************************");
    printf("\n******************************************************\n");

    return 0;
}

