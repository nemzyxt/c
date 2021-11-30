//Author : Nemuel Wainaina

#include<stdio.h>

//the function takes the total price as an argument and if the price is above 5000/=, the customer is given a 5% discount
float discount_calc(int amount){
    float discount = 0;
    if(amount>5000){
        discount = amount * 0.05;
    }
    return discount;
}

//this function takes an array containing a list of prices for the various items purchased, finds and returns the total price by adding all these prices
int calc_total_price(int prices[], int no_of_items){
    int sum = 0;
    for(int i=0;i<no_of_items;i++){
        sum += prices[i];
    }
    return sum;
}

//the main function, where the program execution starts
int main(){
    int again = 1;

    printf("----------------------------------------------------------------------------\n");
    printf("\t\tWelcome to the Invoice Creator Program ...\n\t\t\t@Nemzyxt\n");

    do{
        char customer_name[50]; // Holds the customer name
        char date[10]; //Holds the transaction date
        int no_of_items; //Variable to hold the number if items purchased by the customer
        int total_price; //Sum of all individual prices of the items
        float discount; //If any, the discount is stored in this variable
        float after_discount; //The new price after the discount if any has been deducted from the total_

        /*Section for taking details of the order
          *Customer name
          *Date the invoice was issued
          *Number of items ordered
          *Item names
          *Price of each item
        */
        printf("----------------------------------------------------------------------------\n");
        printf("Enter Customer Name : ");
        scanf("%s", customer_name); //Date
        printf("Enter the date of issue of the Invoice [DD/MM/YYYY] : ");
        scanf("%s", date); //Date
        printf("Enter the Number of Items Ordered : ");
        scanf("%d", &no_of_items); //Number of items

        //Arrays to hold items list and their prices
        char items_list[no_of_items][50]; //Holds the list of items
        int prices[no_of_items]; //Holds the prices for the items

        //Taking items list and the prices
        for(int i=0;i<no_of_items;i++){
            printf("Enter item %d : ", i+1);
            scanf("%s", items_list[i]);
            printf("Enter the total price for the %s : ", items_list[i]);
            scanf("%d", &prices[i]);
        }

        //Some calculations now,
        total_price = calc_total_price(prices, no_of_items); //Calculate the total price
        discount = discount_calc(total_price); //The discount if any
        after_discount = total_price - discount; //The final price after discounting the total price above

        //Storing the invoice to a file
        FILE* fp = fopen("invoices.txt", "a");
        fprintf(fp, "\n****************************************************************************\n");
        fprintf(fp, "Customer Name : %s\n", customer_name);
        fprintf(fp, "Date          : %s\n", date);
        fprintf(fp, "\n----------------------------------------------------------------------------\n");
        fprintf(fp, "\t\t\t\t---ITEMS---\t\t\t\t\n");
        fprintf(fp, "----------------------------------------------------------------------------\n");
        fprintf(fp, "Item Number\t\tItem Name\t\tPrice(KShs)\n");
        for(int i=0;i<no_of_items;i++){
            fprintf(fp, "%d.\t\t\t%s\t\t\t%d\n", i+1, items_list[i], prices[i]);
        }
        fprintf(fp, "----------------------------------------------------------------------------\n");
        fprintf(fp, "Total Price  : %d\n", total_price);
        fprintf(fp, "Discount     : %.2f\n", discount);
        fprintf(fp, "Final Price  : %.2f\n", after_discount);
        fprintf(fp, "============================================================================\n");
        fclose(fp);

        printf("Would you like to generate another invoice ?\n1.Yes\n2.No\n>>> ") ;
        scanf("%d", &again);


    }while(again == 1);

    return 0;
}
