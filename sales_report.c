/*
Name: John Rader
KUID: 3139234
Lab Session: Wednesday 1pm
Lab Assignment: 5
Description: Provides a sales report with a given input file
Collaborators: None
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns a month based on given index -> [0, 11]
void print_month_from_index(int index){
    char *word = "";

    switch(index){
        case 0:
            word = "January";
            break;
        case 1:
            word = "February";
            break;
        case 2:
            word = "March";
            break;
        case 3:
            word = "April";
            break;
        case 4:
            word = "May";
            break;
        case 5:
            word = "June";
            break;
        case 6:
            word = "July";
            break;
        case 7:
            word = "August";
            break;
        case 8:
            word = "September";
            break;
        case 9:
            word = "October";
            break;
        case 10:
            word = "November";
            break;
        case 11:
            word = "December";
            break;
    }

    printf("%s", word);
}

float avg(float arr[], int length){
    float sum = 0;

    for (int i = 0; i < length; i++){
        sum += arr[i];
    }

    return (float) sum / length;
}

int main(){
    // get user input from file

    float sales[12];

    // read input file
    FILE *file_ptr;
    file_ptr = fopen("sales_report_input.txt", "r");
    if(file_ptr == NULL){
        printf("File input cannot be found. Please name the file \"sales_report_input.txt\" and place it in the same directory as the program executable.");
    }

    // read line by line to sales
    for (int i = 0; i < 12; i++){
        char str[50];
        fgets(str, 50, file_ptr);
        sales[i] = atof(str);
    }

    // print sales summary report
    printf("Monthly Sales Report for 2024 \n\n");

    // print sales amounts
    printf("Month \t\tSales\n");
    for (int i = 0; i < 12; i++){
        print_month_from_index(i);

        // remove a tab space from feb, sept, nov, dec
        if (i == 1 || i == 8 || i == 10 || i == 11){
            printf("\t%.2f\n", sales[i]);
        }else{
            printf("\t\t%.2f\n", sales[i]);
        }
    }

    printf("\nSales summary report:\n");

    // find minimum value of sales
    float max = sales[0];
    int max_month_index = 0;

    float min = sales[0];
    int min_month_index = 0;
    
    for (int i = 0; i < 12; i++){
        // find the max value
        if (sales[i] > max){
            max = sales[i];
            max_month_index = i;
        }
        // find the min value
        if (sales[i] < min){
            max = sales[i];
            min_month_index = i;
        }
    }

    // 12 month data:
    printf("\n");
    printf("Minimum sales: %.2f (", min);
    print_month_from_index(min_month_index);
    printf(")\n");

    printf("Maximum sales: %.2f (", max);
    print_month_from_index(max_month_index);
    printf(")\n");

    printf("Average sales: %.2f \n", avg(sales, 12));
    printf("\n");

    printf("Six-Month moving average report:\n\n");

    // moving averages
    for (int i = 5; i <= 11; i++){
        int first_month_index = i - 5;

        // print months
        print_month_from_index(first_month_index);
        printf("-");
        print_month_from_index(i);
        printf("\t");

        // print average
        float window[] = {sales[i-5],sales[i-4],sales[i-3],sales[i-2],sales[i-1],sales[i]};
        printf("%.2f\n", avg(window, 6));
    }

    // sort sales using bubble sort
    int indexes[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for (int i = 0; i < 12 - 1; i++){
        for (int j = i; j < 12 - 1; j++){
            if(sales[j] > sales[j + 1]){
                // swap values
                float temp_val = sales[j + 1];
                sales[j + 1] = sales[j];
                sales[j] = temp_val;

                // swap indexes
                int temp_index = indexes[j + 1];
                indexes[j + 1] = indexes[j];
                indexes[j] = temp_index;
            }
        }
    }

    // print sorted
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month\t\tSales\n");
     
    // traverse in reverse order to get highest to lowest
    for (int i = 11; i >= 0; i--){
        int month_index = indexes[i];
        print_month_from_index(month_index);
        if (month_index == 1 || month_index == 8 || month_index == 10 || month_index == 11){
            printf("\t%.2f\n", sales[i]);
        }else{
            printf("\t\t%.2f\n", sales[i]);
        }
    }


    return 0;
}