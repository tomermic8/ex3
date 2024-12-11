/******************
Name:tomer michels
ID:322440892
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7
#define go_toyoga 0
#define go_hyunnight 1
#define go_mazduh 2
#define go_FolksVegan 3
#define go_Keyyuh 4
#define go_SUV 0
#define go_Sedan 1
#define go_Coupe 2
#define go_GT 3
#define any_type 1
#define no_value -1
#define any_car 0


char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"};

void printtype(int type) {
    //printing type name
    for (int i = 0; i < TYPES_NAMES; i++) {
        if (types[type][i] == '\0') {
            printf(" ");
            break;
        }
        printf("%c", types[type][i]);
    }
}

void printtypenospace(int type) {
    //printimg type names without space
    for (int i = 0; i < TYPES_NAMES; i++) {
        if (types[type][i] == '\0') {
            break;
        }
        printf("%c", types[type][i]);
    }
}

void printBrand(int brand) {
    //printing brand name
    for (int i = 0; i < BRANDS_NAMES; i++) {
        if (brands[brand][i] == '\0') {
            printf(" ");
            break;
        }
        printf("%c", brands[brand][i]);
    }
}

void printBrandnospace(int brand) {
    //printing brand name no space
    for (int i = 0; i < BRANDS_NAMES; i++) {
        if (brands[brand][i] == '\0') {
            break;
        }
        printf("%c", brands[brand][i]);
    }
}

int sales(int arr[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int specday, int specbrand) {
    //calculate sales for spec day
    //*****need to change array size to names
    int sumsales = 0;
    for (int i = 0; i < NUM_OF_TYPES; i++) {
        sumsales = sumsales + arr[specday][specbrand][i];
    }
    return sumsales;
}

int typesale(int arr[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int specday, int type) {
    //calculate sales of spec type
    int sumtype = 0;
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        sumtype = sumtype + arr[specday][i][type];
    }
    return sumtype;
}

int bestsellingbrand(int arr[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int brand) {
    //calculate all sales of breand
    int sumsales = 0;
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        if (arr[i][brand][0] == no_value) {
            //when we stopped populate the array
            return sumsales;
        }
        for (int j = 0; j < NUM_OF_TYPES; j++) {
            sumsales = sumsales + arr[i][brand][j];
        }
    }
    return sumsales;
}

int maximum(int a, int b, int c, int d, int e) {
    //find max 5 nums
    int max = a;
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    if (max < e) {
        max = e;
    }
    return max;
}

int maximumfour(int a, int b, int c, int d) {
    //find max 4 nums
    int max = a;
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    return max;
}

int mostsaletype(int arr[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int type) {
    //calculate all types sale
    int sumoftype = 0;
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        if (arr[i][any_car][type] == no_value) {
            //when we stopped populate the array
            return sumoftype;
        }
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            sumoftype = sumoftype + arr[i][j][type];
        }
    }
    return sumoftype;
}

double delta(int arr[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES], int brand) {
    //calculating the delta
    //whats happend if we didnt populate 2 days?????
    double deltaminus = 0; //delta after hefresh
    for (int i = 1; i < DAYS_IN_YEAR; i++) {
        int sumfordelta = 0;
        int sumofnprevday = 0;
        if (arr[i][any_car][0] == no_value) {
            //when we stop
            return deltaminus / (i - 1); //we look on transitions between days so i-1
        }
        for (int j = 0; j < NUM_OF_TYPES; j++) {
            sumfordelta = sumfordelta + arr[i][brand][j];
            sumofnprevday = sumofnprevday + arr[i - 1][brand][j];
        }
        deltaminus = deltaminus + (sumfordelta - sumofnprevday);
    }
    return deltaminus / 364; //if we populae the whole array return delta devide 364 transitions
}


int main() {
    int array[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES]; //filling the array with -1
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        //filling the array with -1
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                array[i][j][k] = no_value;
            }
        }
    }
    int day = 0; //day counter for 2

    int option = 0; //getting into the while
    while (option != done) {
        printf("Welcome to the Cars Data Cube! What would you like to do?\n"
            "1.Enter Daily Data For A Brand\n"
            "2.Populate A Day Of Sales For All Brands\n"
            "3.Provide Daily Stats\n"
            "4.Print All Data\n"
            "5.Provide Overall (simple) Insights\n"
            "6.Provide Average Delta Metrics\n"
            "7.exit\n");

        scanf("%d", &option);

        switch (option) {
            case addOne: {
                int brandcheck, suvcheck, sedancheck, coupecheck, gtcheck;
                printf("please enter brand name and their data\n"); //we didnt have any instructions how to write
                scanf("%d %d %d %d %d", &brandcheck, &suvcheck, &sedancheck, &coupecheck, &gtcheck);
                if (brandcheck > 4 || brandcheck < 0) {
                    printf("This brand is not valid\n");
                    break;
                }
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    //running till empty day
                    if (array[i][brandcheck][any_type] == no_value) {
                        //if no values in day so fill it and then break
                        array[i][brandcheck][go_SUV] = suvcheck;
                        array[i][brandcheck][go_Sedan] = sedancheck;
                        array[i][brandcheck][go_Coupe] = coupecheck;
                        array[i][brandcheck][go_GT] = gtcheck;
                        break;
                    }
                }
                break;
            }
            case 2: {
                int brand, suv, sedan, Coupe, GT;

                while (array[day][go_toyoga][any_type] == no_value || array[day][go_hyunnight][any_type] == no_value ||
                       array[day][go_mazduh][any_type] == no_value || array[day][go_FolksVegan][any_type] ==
                       no_value
                       || array
                       [day][go_Keyyuh][any_type] == no_value) {
                    //till we fill
                    //check  we fill all brands for day
                    printf("No data for brands "); //whice brand we didnt fill every time
                    if (array[day][go_toyoga][any_type] == no_value) {
                        printBrand(go_toyoga);;
                    }
                    if (array[day][go_hyunnight][any_type] == no_value) {
                        printBrand(go_hyunnight);
                    }
                    if (array[day][go_mazduh][any_type] == no_value) {
                        printBrand(go_mazduh);
                    }
                    if (array[day][go_FolksVegan][any_type] == no_value) {
                        printBrand(go_FolksVegan);
                    }
                    if (array[day][go_Keyyuh][any_type] == no_value) {
                        printBrand(go_Keyyuh); //****** maybe pssibility with extra space
                    }
                    printf("\nPlease complete the data\n"); //start change
                    scanf("%d", &brand); //
                    while (brand > 4 || brand < 0 || array[day][brand][any_type] != no_value) {
                        //if we fiiled that brand or brand doesnt exist
                        //
                        printf("This brand is not valid\n"); //
                        scanf("%d", &brand); //end change
                    }
                    scanf("%d %d %d %d", &suv, &sedan, &Coupe, &GT);
                    while (brand > 4 || brand < 0 || array[day][brand][any_type] != no_value) {
                        //check if brand already populate
                        printf("This brand is not valid\n");
                        printf("No data for brands ");
                        if (array[day][go_toyoga][any_type] == no_value) {
                            printBrand(go_toyoga); //changed
                        }
                        if (array[day][go_hyunnight][any_type] == no_value) {
                            printBrand(go_hyunnight);
                        }
                        if (array[day][go_mazduh][any_type] == no_value) {
                            printBrand(go_mazduh);
                        }
                        if (array[day][go_FolksVegan][any_type] == no_value) {
                            printBrand(go_FolksVegan);
                        }
                        if (array[day][go_Keyyuh][any_type] == no_value) {
                            printBrand(go_Keyyuh); //****** maybe pssibility with extra space
                        }
                        printf("\nPlease complete the data.\n");

                        scanf("%d %d %d %d %d", &brand, &suv, &sedan, &Coupe, &GT);
                    }

                    for (int i = 0; i < NUM_OF_TYPES; i++) {
                        //filling the type of the brand we chose
                        array[day][brand][i] = suv;
                        i++;
                        array[day][brand][i] = sedan;
                        i++;
                        array[day][brand][i] = Coupe;
                        i++;
                        array[day][brand][i] = GT;
                    }
                } //end of while didnt finish populate
                day = day + 1; //finish populate and move for next day;
                //here the break should be
                break;
            }
            case 3: {
                int analyzeday;
                printf("What day would you like to analyze?\n");
                scanf("%d", &analyzeday);
                analyzeday = analyzeday -1;
                if (analyzeday == 0 && array[analyzeday][any_car][any_type] == no_value)
                //for case we didnt populate any brand. like mobax
                {
                    int no_sale = 0;
                    printf("In day number %d:", analyzeday);
                    printf("The sales total was %d\n", no_sale);
                    printf("The best sold brand with %d sales was ", no_sale);
                    printBrand(go_toyoga);
                    printf("\nThe best sold type with %d sales was ", no_sale);
                    printtype(go_SUV);
                    printf("\n");
                    break;
                }

                while (analyzeday < 0 || analyzeday > 364 || array[analyzeday][any_car][any_type] == no_value) {
                    //check the day is available
                    printf("Please enter a valid day.\n");
                    printf("What day would you like to analyze?\n");
                    scanf("%d", &analyzeday);
                    analyzeday=analyzeday -1;
                    //day 1 for user its day 0 for us
                }
                int sumtoyoga = sales(array, analyzeday, go_toyoga); //get total sale of that day per company
                int sumtHyunNight = sales(array, analyzeday, go_hyunnight);
                int sumMazduh = sales(array, analyzeday, go_mazduh);
                int sumFolksVegan = sales(array, analyzeday, go_FolksVegan);
                int sumKeyYuh = sales(array, analyzeday, go_Keyyuh);


                int max = 0; //till row 327 checking the maximum total
                if (max < sumtoyoga) {
                    max = sumtoyoga;
                }

                if (max < sumtHyunNight) {
                    max = sumtHyunNight;
                }
                if (max < sumMazduh) {
                    max = sumMazduh;
                }
                if (max < sumFolksVegan) {
                    max = sumFolksVegan;
                }
                if (max < sumKeyYuh) {
                    max = sumKeyYuh;
                }
                printf("In day number %d:", analyzeday+1);
                printf("\nThe sales total was %d\n", sumtoyoga + sumtHyunNight + sumMazduh + sumFolksVegan + sumKeyYuh);

                if (max == sumtoyoga) {
                    //printing the maximum
                    printf("The best sold brand with %d sales was ", max);
                    printBrand(go_toyoga);
                } else if (max == sumtHyunNight) {
                    //for case we have equal brands printing the lower index
                    printf("The best sold brand with %d sales was ", max);
                    printBrand(go_hyunnight);
                } else if (max == sumMazduh) {
                    printf("The best sold brand with %d sales was ", max);
                    printBrand(go_mazduh);
                } else if (max == sumFolksVegan) {
                    printf("The best sold brand with %d sales was ", max);
                    printBrand(go_FolksVegan);
                } else if (max == sumKeyYuh) {
                    printf("The best sold brand with %d sales was ", max);
                    printBrand(go_Keyyuh);
                }

                int totalsuv = typesale(array, analyzeday, go_SUV); //getting total of every type per day
                int totalSedan = typesale(array, analyzeday, go_Sedan);
                int totalCoupe = typesale(array, analyzeday, go_Coupe);
                int totalGT = typesale(array, analyzeday, go_GT);

                int maxtype = 0; //finding the maximum till row 362
                if (maxtype < totalsuv) {
                    maxtype = totalsuv;
                }

                if (maxtype < totalSedan) {
                    maxtype = totalSedan;
                }
                if (maxtype < totalCoupe) {
                    maxtype = totalCoupe;
                }
                if (maxtype < totalGT) {
                    maxtype = totalGT;
                }

                if (maxtype == totalsuv) {
                    //printing the naximum type
                    printf("\nThe best sold type with %d sales was ", maxtype);
                    printtype(go_SUV);
                    printf("\n");
                } else if (maxtype == totalSedan) {
                    //for case we have equala type
                    printf("\nThe best sold type with %d sales was ", maxtype);
                    printtype(go_Sedan);
                    printf("\n");
                } else if (maxtype == totalCoupe) {
                    printf("\nThe best sold type with %d sales was ", maxtype);
                    printtype(go_Coupe);
                    printf("\n");
                } else if (maxtype == totalGT) {
                    printf("\nThe best sold type with %d sales was ", maxtype);
                    printtype(go_GT);
                    printf("\n");
                }

                break;
            }
            case 4: {
                printf("*****************************************\n");
                printf("\nSales for ");
                printBrandnospace(go_toyoga);
                printf(":\n");
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    //for on days
                    int k = 0; //running on types
                    if (array[i][go_toyoga][k] == no_value) {
                        //when no more values
                        //when no data
                        break;
                    }
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", i + 1, array[i][go_toyoga][k],
                           array[i][go_toyoga][k + 1],
                           array[i][go_toyoga][k + 2], array[i][go_toyoga][k + 3]); //print for each day
                }
                printf("Sales for ");
                printBrandnospace(go_hyunnight);
                printf(":\n");
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    int k = 0; //running on types
                    if (array[i][go_hyunnight][k] == no_value) {
                        //when no data
                        break;
                    }
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", i + 1, array[i][go_hyunnight][k],
                           array[i][go_hyunnight][k + 1],
                           array[i][go_hyunnight][k + 2], array[i][go_hyunnight][k + 3]);
                }

                printf("Sales for ");
                printBrandnospace(go_mazduh);
                printf(":\n");
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    int k = 0; //running on types
                    if (array[i][go_mazduh][k] == no_value) {
                        //when no data
                        break;
                    }
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", i + 1, array[i][go_mazduh][k],
                           array[i][go_mazduh][k + 1],
                           array[i][go_mazduh][k + 2], array[i][go_mazduh][k + 3]);
                }


                printf("Sales for ");
                printBrandnospace(go_FolksVegan);
                printf(":\n");
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    int k = 0; //running on types
                    if (array[i][go_FolksVegan][k] == no_value) {
                        //when no data
                        break;
                    }
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", i + 1, array[i][go_FolksVegan][k],
                           array[i][go_FolksVegan][k + 1],
                           array[i][go_FolksVegan][k + 2], array[i][go_FolksVegan][k + 3]);
                }

                printf("Sales for ");
                printBrandnospace(go_Keyyuh);
                printf(":\n");
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    int k = 0; //running on types
                    if (array[i][go_Keyyuh][k] == no_value) {
                        //when no data
                        break;
                    }
                    printf("Day %d- SUV: %d Sedan: %d Coupe: %d GT: %d\n", i + 1, array[i][go_Keyyuh][k],
                           array[i][go_Keyyuh][k + 1],
                           array[i][go_Keyyuh][k + 2], array[i][go_Keyyuh][k + 3]);
                }
                printf("\n*****************************************\n");
                break;
            }
            case 5: {
                int totaltoyoga = bestsellingbrand(array, go_toyoga); //chcecking total days for every brand
                int totalHyunNight = bestsellingbrand(array, go_hyunnight);
                int totalMazduh = bestsellingbrand(array, go_mazduh);
                int totalFolksVegan = bestsellingbrand(array, go_FolksVegan);
                int totalKeyYuh = bestsellingbrand(array, go_Keyyuh);

                int besttotal = maximum(totaltoyoga, totalHyunNight, totalMazduh, totalFolksVegan, totalKeyYuh);
                //checking maximum

                if (besttotal == totaltoyoga) {
                    //printing maximum
                    printf("The best-selling brand overall is ");
                    printBrandnospace(go_toyoga);
                    printf(": %d$\n", totaltoyoga);
                } else if (besttotal == totalHyunNight) {
                    //for case we have equal brands
                    printf("The best-selling brand overall is ");
                    printBrandnospace(go_hyunnight);
                    printf(": %d$\n", totalHyunNight);
                } else if (besttotal == totalMazduh) {
                    printf("The best-selling brand overall is ");
                    printBrandnospace(go_mazduh);
                    printf(": %d$\n", totalMazduh);
                } else if (besttotal == totalFolksVegan) {
                    printf("The best-selling brand overall is ");
                    printBrandnospace(go_FolksVegan);
                    printf(": %d$\n", totalFolksVegan);
                } else if (besttotal == totalKeyYuh) {
                    printf("The best-selling brand overall is ");
                    printBrandnospace(go_Keyyuh);
                    printf(": %d$\n", totalKeyYuh);
                }

                int totalallsuv = mostsaletype(array, go_SUV); //checking total types sale
                int totalalsedan = mostsaletype(array, go_Sedan);
                int totalalcoupe = mostsaletype(array, go_Coupe);
                int totalalgt = mostsaletype(array, go_GT);

                int msximumtype = maximumfour(totalallsuv, totalalsedan, totalalcoupe, totalalgt); //getting max

                if (msximumtype == totalallsuv) {
                    //printing max type
                    printf("The best-selling type of car is ");
                    printtypenospace(go_SUV);
                    printf(": %d$\n", totalallsuv);
                } else if (msximumtype == totalalsedan) {
                    //for case of equal types
                    printf("The best-selling type of car is ");
                    printtypenospace(go_Sedan);
                    printf(": %d$\n", totalalsedan);
                } else if (msximumtype == totalalcoupe) {
                    printf("The best-selling type of car is ");
                    printtypenospace(go_Coupe);
                    printf(": %d$\n", totalalcoupe);
                } else if (msximumtype == totalalgt) {
                    printf("The best-selling type of car is ");
                    printtypenospace(go_GT);
                    printf(": %d$\n", totalalgt);
                }


                int thedayitself;
                int maxday = 0;
                for (int i = 0; i < DAYS_IN_YEAR; i++) {
                    //need to check whats happend if we didnt populate at all!!!
                    if (array[i][any_car][any_type] == no_value) {
                        //no more populater days
                        //any car was 1!!!
                        printf("The most profitable day was day number %d: %d$\n", thedayitself + 1, maxday);
                        //+1 cause first day in array its 0
                        break;
                    }
                    int daytotal = 0;
                    for (int j = 0; j < NUM_OF_BRANDS; j++) {
                        for (int k = 0; k < NUM_OF_TYPES; k++) {
                            daytotal = daytotal + array[i][j][k];
                        }
                    }
                    if (daytotal > maxday) {
                        //new day>max day?
                        maxday = daytotal;
                        thedayitself = i;
                    }
                }

                break;
            }
            case 6: {
                int day_zero = 0;
                if (array[day_zero][any_car][any_type] == no_value) {
                    //for case  of no days like mobax
                    double no_delta = 0;
                    printf("Brand: %s, Average Delta: %f\n", brands[go_toyoga], no_delta);
                    printf("Brand: %s, Average Delta: %f\n", brands[go_hyunnight], no_delta);
                    printf("Brand: %s, Average Delta: %f\n", brands[go_mazduh], no_delta);
                    printf("Brand: %s, Average Delta: %f\n", brands[go_FolksVegan], no_delta);
                    printf("Brand: %s, Average Delta: %f\n", brands[go_Keyyuh], no_delta);
                    break;
                }


                double deltaToyoga = delta(array, go_toyoga); //getting delta
                double deltaHyunNight = delta(array, go_hyunnight);
                double deltaMazduh = delta(array, go_mazduh);
                double deltaFolksVegan = delta(array, go_FolksVegan);
                double deltaKeyYuh = delta(array, go_SUV);

                printf("Brand: %s, Average Delta: %f\n", brands[go_toyoga], deltaToyoga);
                printf("Brand: %s, Average Delta: %f\n", brands[go_hyunnight], deltaHyunNight);
                printf("Brand: %s, Average Delta: %f\n", brands[go_mazduh], deltaMazduh);
                printf("Brand: %s, Average Delta: %f\n", brands[go_FolksVegan], deltaFolksVegan);
                printf("Brand: %s, Average Delta: %f\n", brands[go_Keyyuh], deltaKeyYuh);
            }
        }
    }
    printf("Goodbye!");
}
