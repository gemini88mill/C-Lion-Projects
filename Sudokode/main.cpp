
#include <stdio.h>

#define SIZE 9



bool check_row_logic(int pInt[]);

bool row_level(int prepared_row[], int solution[][SIZE], bool row_check);

bool column_level(int prepared_row[], int solution[][SIZE], bool row_check);

bool subgrid_level(int prepared_row[], int solution[][SIZE], bool row_check);

unsigned int count(int i);

int main() {

    int solution[SIZE][SIZE];/* = {{3,5,7,6,4,8,9,1,2},
                                {2,1,6,5,3,9,7,4,8},
                                {9,4,8,7,1,2,5,3,6},
                                {5,2,1,4,8,6,3,9,7},
                                {4,6,3,1,9,7,2,8,5},
                                {7,8,9,3,2,5,1,6,4},
                                {6,3,2,9,7,4,8,5,1},
                                {1,7,4,8,5,3,6,2,9},
                                {8,9,5,2,6,1,4,7,3}};*/

    //int test[SIZE];

    int number_of_solutions = 0;
    scanf("%i", &number_of_solutions);

    int i, j, k;
    int value = 0;
    int explode[SIZE];
    int count = 0;

    for(k = 0; k < number_of_solutions; k++) {
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &value);

            while (value > 0) {
                explode[count] = value % 10;
                value = value / 10;
                count++;
            }

            for (j = 0; j < count; j++){
                solution[i][j] = explode[j];
                printf("%d ", explode[j]);
            }
            count = 0;
        }

    }

//    while ( value > 0 )
//    {
//        explode[count] = value % 10;
//        value = value / 10;
//        count++;
//    }
//    for(j = 0; j < SIZE; j++) {
//        for (int i = SIZE - 1; i >= 0; i--) {
//            solution[j][i] = explode[i];
//            printf("%d", solution[i][i]);
//        }
//        printf("\n");
//    }


    int prepared_row[SIZE];
    bool row_check = false; //boolean value to check store value of test.
    bool final_check[3] = {false, false, false};



    //------------------------ row level --------------------------------
    final_check[0] = row_level(prepared_row, solution, row_check);
    //-------------------------------------------------------------------

    //--------------------- Column level -------------------------------
    printf("\n\n");
    final_check[1] = column_level(prepared_row, solution, row_check);
    //------------------------------------------------------------------

    //----------------------subgrid level-------------------------------
    printf("\n\n");
    final_check[2] = subgrid_level(prepared_row, solution, row_check);
    //------------------------------------------------------------------

    //printf("%s", final_check[2] ? "true\n" : "false\n");
    //printf("%s", final_check[1] ? "true\n" : "false\n");
    //printf("%s", final_check[0] ? "true\n" : "false\n");

    if(final_check[0] == true && final_check[1] == true && final_check[2] == true){
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

unsigned int count(int i) {
    unsigned int ret=1;
    while (i/=10) ret++;
    return ret;
}

bool subgrid_level(int prepared_row[], int solution[][SIZE], bool row_check) {
    int i, j, k, l, m;

    for (l = 0; l < SIZE; l = l + 3) {
        //solution[column][row]
        for (i = 0; i < 3; i++) {
            prepared_row[i] = solution[i][l];
        }
        for (k = 3; k < 6; k++) {
            prepared_row[k] = solution[k - 3][l + 1];
        }
        for (j = 6; j < SIZE; j++) {
            prepared_row[j] = solution[j - 6][l + 2];
        }
        for (m = 0; m < SIZE; m++) {
            printf("%d ", prepared_row[m]);
        }
        row_check = check_row_logic(prepared_row);
        printf("%s", row_check ? "true\n" : "false\n");
        if (row_check == false){
            break;
        }

    }


    for (l = 0; l < SIZE; l = l + 3) {
        //solution[column][row]

        for (i = 0; i < 3; i++) {
            prepared_row[i] = solution[i + 3][l];
        }
        for (k = 3; k < 6; k++) {
            prepared_row[k] = solution[k][l + 1];
        }
        for (j = 6; j < SIZE; j++) {
            prepared_row[j] = solution[j - 3][l + 2];
        }
        for (m = 0; m < SIZE; m++) {
            printf("%d ", prepared_row[m]);
        }
        row_check = check_row_logic(prepared_row);
        printf("%s", row_check ? "true\n" : "false\n");
        if (row_check == false){
            break;
        }

    }


    for (l = 0; l < SIZE; l = l + 3) {
        //solution[column][row]

        for (i = 0; i < 3; i++) {
            prepared_row[i] = solution[i + 6][l];
        }
        for (k = 3; k < 6; k++) {
            prepared_row[k] = solution[k + 3][l + 1];
        }
        for (j = 6; j < SIZE; j++) {
            prepared_row[j] = solution[j][l + 2];
        }
        for (m = 0; m < SIZE; m++) {
            printf("%d ", prepared_row[m]);
        }
        row_check = check_row_logic(prepared_row);
        printf("%s", row_check ? "true\n" : "false\n");
        if (row_check == false){
            break;
        }

    }
    //this is extremely lame code, but it works... and im tired :(
    return row_check;
}

bool column_level(int prepared_row[], int solution[][SIZE], bool row_check) {
    int i, j;

    for ( j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) {
            prepared_row[i] = solution[i][j];
            printf("%d ", prepared_row[i]);
            row_check = check_row_logic(prepared_row);
        }
        printf("%s", row_check ? "true\n" : "false\n");
        if (row_check == false){
            break;
        }
    }
    return row_check;
}

bool row_level(int prepared_row[], int solution[][SIZE], bool row_check) {
    int i, j;

    for (j = 0; j < SIZE; j++) {
        for ( i = 0; i < SIZE; i++) {
            prepared_row[i] = solution[j][i];
            printf("%d ", prepared_row[i]);
            row_check = check_row_logic(prepared_row);
        }
        printf("%s", row_check ? "true\n" : "false\n");
        if (row_check == false){
            break;
        }
    }
    return row_check;
}

bool check_row_logic(int pInt[]) {
    //check to see if any numbers in the "row" array are equal to each other
    bool result = true;
    int i, j;
    int checked_val = 0;
    int count = 0;

    for (i = 0; i < SIZE; i++){
        checked_val = pInt[i]; //stores array in checked_val
        for (j = 0; j < SIZE; j++){
            //runs array again to check against checked_val
            if(pInt[j] == checked_val){
                //printf("yes\n");
                count++;
            } else {
                //printf("no\n");
            }
        }
        //printf("\n\n");
        if (count > 1){
            result = false;
            break;
        }
        count = 0;
    }
    return result;
}

