//Author : Nemuel Wainaina
//This is a simple program that showcases various operations to perform on arrays , these include :

/*sorting the array in descending order
 *finding the minimum value in the array
 *finding the maximum value in the array
 *calculating the average of the numbers in the array
 *calculating the standard deviation of the numbers in the array
*/

//Have Fun!!!

//The header files
#include<stdio.h>
#include<math.h>//for the sqrt function which we will use in calculating the standard deviation

//This function prints out the menu to the user, takes choice as input from the user
//and if the input is valid, returns it to the calling function, else, clears the screen and prints the menu again,
//and waits for the user to make a selection again
int choose_task(){
    int choice;
    printf("\tMENU\n");
    printf("---------------------------------------------------\n");
    printf("1. Sort the array in Descending order\n");
    printf("2. Find the minimum value of the array\n");
    printf("3. Find the maximum value of the array\n");
    printf("4. Calculate the average of Numbers in the array\n");
    printf("5. Calculate the standard deviation of the array\n");
    printf("---------------------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    //if the user enters an invalid choice
    if(choice<1 || choice>5){
        system("cls");
        choose_task();
    }

    else return choice;
}

//The function to sort the array in descending order
void sort_array(int* arr, int size){
    int temp, n = size;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j){
            if (arr[i] < arr[j]){
                temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Gets and returns the minimum value in the array
int get_min(int arr[], int size){
    int min=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<=min){
            min=arr[i];
        }
    }
    return min;
}

//Gets and returns the maximum value in the array
int get_max(int arr[], int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    return max;
}

//This function calculates and returns the average of the values in the array
float get_average(int arr[], int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    float average=(float) sum/size;
    return average;
}

//This function calculates and returns the standard deviation of the values in the array
float get_std_dev(int arr[], int size){
    int sum_of_x_sqrd=0;
    float avg=0, avg_sqrd=0;
    avg=get_average(arr, size);
    avg_sqrd=avg*avg;
    for(int i=0;i<size;i++){
        sum_of_x_sqrd+=(arr[i]*arr[i]);
    }
    float variance, std_dev;
    variance = ((float)sum_of_x_sqrd/size)-avg_sqrd;
    std_dev =  sqrt(variance);
    return std_dev;
}


//the main function, where program execution starts
int main(){
    printf("===================================================\n");

    //getting the number of values that the user will input into the array
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    printf("---------------------------------------------------\n");

    //declare an array of size "size"
    int arr[size];

    //loop to get the values from the user
    for(int i=0;i<size;i++){
        printf("Enter value %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("===================================================\n");

    //declare the variable to hold the user's choice of task or operation to perform on the array
    int choice;
    //print the menu to the user and get their choice
    choice=choose_task();

    printf("---------------------------------------------------\n");

    //initialize some variables
    int min, max;
    float average, std_dev;

    //Perform the correct task or operation on the array depending on the choice of the user
    switch(choice){
    case 1:
        sort_array(arr, size);
        printf("The Sorted Array is : ");
        for(int i=0;i<size;i++){
            printf("%d ", arr[i]);
        }
        break;
    case 2:
        min = get_min(arr, size);
        printf("The Minimum Value in the array is %d", min);
        break;
    case 3:
        max = get_max(arr, size);
        printf("The Maximum Value in the array is %d", max);
        break;
    case 4:
        average = get_average(arr, size);
        printf("The Average of the Values in the array is %.2f", average);
        break;
    case 5:
        std_dev = get_std_dev(arr, size);
        printf("The Standard Deviation of Values in the array is %.2f", std_dev);
        break;
    }

    printf("\n===================================================\n");
    printf("\t\t  @Nemzyxt");
    printf("\n===================================================\n\n");

    return 0;
}
