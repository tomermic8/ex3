#include <stdio.h>
#include <string.h>

char brands[5][15] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[4][10] = {"SUV", "Sedan", "Coupe", "GT"};



void addDayForBrand(int cube[365][5][4], int brand, int days[5]){

    int day = days[brand], typeSales[4];
    for(int i = 0; i < 4; i++){
        scanf("%d", &cube[day][brand][i]);
    }
    days[brand]++;
}


void printCube(int cube[365][5][4], int days[5]){
    printf("*****************************************\n\n");
    for(int brand = 0; brand < 5; brand++){
        printf("Sales for %s: \n", brands[brand]);
        for(int day = 0; day < days[brand]; day++){
            printf("Day %d- ", day+1);
            for(int type = 0; type < 4; type++){
                printf("%s: %d ", types[type], cube[day][brand][type]);
            }
            printf("\n");
        }
    }
    printf("\n\n*****************************************");
}



int main() {
    int cube[365][5][4];
    int days[5] = {0};
    for(int i = 0; i < 365; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 4; k++){
                cube[i][j][k] = -1;
            }
        }
    }
    int choice;
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
           "1.Enter Daily Data For A Brand\n"
           "2.Populate A Day Of Sales For All Brands\n"
           "3.Provide Daily Stats\n"
           "4.Print All Data\n"
           "5.Provide Overall (simple) Insights\n"
           "6.Provide Average Delta Metrics\n"
           "7.exit\n");
    scanf("%d", &choice);

    while(choice != 7){
        if(choice == 1){
            int brand;
            printf("What brand?\n");
            scanf("%d", &brand);
            if(brand < 0 || brand > 4){
                printf("No such brand\n");
            }
            else{
                addDayForBrand(cube, brand, days);

            }
        }
        else if(choice == 2){
            int nextDay = days[0]+1, flag=0, flagPrintMessage = 1, brand;
            while(!flag){
                flagPrintMessage = 1;
                flag = 1;
                for(int i = 0; i < 5; i++){


                    if(days[i] != nextDay){
                        if(flagPrintMessage){
                            printf("No data for brands ");
                            flagPrintMessage = 0;
                        }
                        printf("%s ", brands[i]);
                        flag = 0;
                    }
                }
                if(flag){
                    break;
                }
                printf("\nPlease complete the data\n");
                scanf("%d", &brand);
                if(brand < 0 || brand > 4 || days[brand] == nextDay){
                    printf("This brand is not valid\n");
                    continue;
                }
                addDayForBrand(cube, brand, days);
            }
        }
        else if(choice == 3){
            int day = -1;
            while(day == -1){
                printf("What day would you like to analyze?\n");
                scanf("%d", &day);
                if(day > days[0]){
                    printf("Please enter a valid day.\n");
                    day = -1;
                    continue;
                }

                int total = 0, brandSales[5] = {0}, typeSales[4] = {0}, topBrand = 0, topType = 0;
                for(int brand=0; brand<5; brand++){
                    for(int type=0; type<4; type++){
                        int sale = cube[day-1][brand][type];
                        total += sale;
                        brandSales[brand] +=sale;

                        typeSales[type] += sale;
                        if(typeSales[type] > typeSales[topType]){
                            topType = type;
                        }
                    }
                    if(brandSales[brand] > brandSales[topBrand]){
                        topBrand = brand;
                    }
                }
                printf("In day number %d:\n"
                       "The sales total was %d\n"
                       "The best sold brand with %d sales was %s\n"
                       "The best sold type with %d sales was %s\n\n", day, total, brandSales[topBrand], brands[topBrand],
                       typeSales[topType], types[topType]);

            }

        }

        else if(choice == 4){
            printCube(cube, days);
        }

        else if(choice == 5){
            int total = 0, brandSales[5] = {0}, typeSales[4] = {0}, topBrand = 0, topType = 0, topDay = 0, topDailySales = 0;
            for(int day = 0; day < days[0]; day++){
                int dayTotal = 0;
                for(int brand=0; brand<5; brand++){
                    for(int type=0; type<4; type++){
                        int sale = cube[day][brand][type];
                        dayTotal += sale;
                        brandSales[brand] +=sale;

                        typeSales[type] += sale;
                        if(typeSales[type] > typeSales[topType]){
                            topType = type;
                        }
                    }
                    if(brandSales[brand] > brandSales[topBrand]){
                        topBrand = brand;
                    }
                }
                if(dayTotal > topDailySales){
                    topDay = day;
                    topDailySales = dayTotal;
                }
            }
            printf("The best-selling brand overall is %s: %d$\n"
                   "The best-selling type of car is %s: %d$\n"
                   "The most profitable day was day number %d: %d$\n", brands[topBrand], brandSales[topBrand],
                   types[topType], typeSales[topType], topDay +1, topDailySales);
        }

        else if(choice == 6){
            int brandDeltas[5] = {0};
            for(int day = 1; day < days[0]; day++){
                for(int brand = 0; brand < 5; brand++){
                    int totalDay = 0, totalDayPrev = 0;
                    for(int type = 0; type <4; type++){
                        totalDay += cube[day][brand][type];
                        totalDayPrev += cube[day-1][brand][type];

                    }
                    brandDeltas[brand] += totalDay - totalDayPrev;
                }
            }
            for(int brand = 0; brand < 5; brand ++){
                printf("Brand: %s, Average Delta: %f\n", brands[brand], (float) brandDeltas[brand] / (days[0] - 1));
            }
        }
        else{
            printf("Invalid input\n");
        }
        printf("Welcome to the Cars Data Cube! What would you like to do?\n"
               "1.Enter Daily Data For A Brand\n"
               "2.Populate A Day Of Sales For All Brands\n"
               "3.Provide Daily Stats\n"
               "4.Print All Data\n"
               "5.Provide Overall (simple) Insights\n"
               "6.Provide Average Delta Metrics\n"
               "7.exit\n");
        scanf("%d", &choice);



    }

    printf("Goodbye!");

    return 0;
}
/*
2
0 1 1 1 1
1 2 1 1 1
2 1 1 1 3
3 1 1 1 1
4 1 1 1 1

 2
 0 1 1 1 1
 1 2 1 1 4
 2 1 1 1 3
 3 20 1 1 1
 4 1 1 1 1

 2
 0 1 1 1 1
 1 2 1 3 1
 2 1 1 1 3
 3 1 1 1 1
 4 1 1 1 1

 2
 0 1 1 1 1
 1 2 2 3 3
 2 1 1 1 3
 3 1 1 1 1
 4 1 1 1 1

 3
 5
 4

 4
 */

