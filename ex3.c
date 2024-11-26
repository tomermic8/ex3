/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

char brands[5][15] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[4][10] = {"SUV", "Sedan", "Coupe", "GT"};


void printMenu(){
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
           "1.Enter Daily Data For A Brand\n"
           "2.Populate A Day Of Sales For All Brands\n"
           "3.Provide Daily Stats\n"
           "4.Print All Data\n"
           "5.Provide Overall (simple) Insights\n"
           "6.Provide Average Delta Metrics\n"
           "7.exit\n");
}


int main() {
    int cube[365][5][4];
    int days[5] = {0};
    int choice;
    printMenu();
    scanf("%d", &choice);

    while(choice != 7){
        switch(choice){
            case 1:
                //...
                break;
            case 2:
                //...
                break;
            /*
             ......
             */
            default:
                printf("Invalid input\n");
        }
        printMenu();
        scanf("%d", &choice);
    }
    printf("Goodbye!\n");
    return 0;

    return 0;
}


