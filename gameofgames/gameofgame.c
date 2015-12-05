/*created by Raphael Miller
 * NID: ra677877
 * December 7th 2015*/

#include <stdio.h>
#include <stdlib.h>

struct House_data {
    int house_name;


    int is_visited;
    int is_open;

    int open_time;
    int close_time;
};

struct Distance_Handler{
    int distance_from;
    int distance_to;
};

struct Game_Time_Handler{
    int current_game_time;
};




int main() {

    //number of input cases for problem
    int input_cases, i;

    //number of games to complete, second value collected
    int games_to_complete, j = 0;
    int starting_time, ending_time, k;


    struct House_data *house;
    struct Distance_Handler *distance_handler;
    struct Game_Time_Handler game_time;




    scanf("%d", &input_cases);

    for(i = 0; i < input_cases; i++){
        scanf("%d", &games_to_complete); //number of games to complete

        //allocates memory for number of houses + 1 (for home base)
        house = malloc(sizeof(house) * games_to_complete + 1);
        //allocates memory for number of distances to and from houses(including home base)
        distance_handler = malloc(sizeof(distance_handler) * games_to_complete + 1);


        int **travel_times = malloc(sizeof(int*) * games_to_complete + 1);
        int n;
        for(n = 0; n < games_to_complete + 1; n++){
            travel_times[n] = malloc(sizeof(int) * games_to_complete + 1);
        }
        int l, m;


        for(j = 0; j < games_to_complete; j++){

            //collection of travel time.
            scanf("%d %d", &starting_time, &ending_time);
            //from here we have p(i) and the starting time and ending time for said values. introduce struct

            /*sets house variables within the struct, designates the start and end times for each house. sets them to
             * j + 1 because there is no start or end time for home_base house. So start and end times are in house 1
             * ans house 2*/
            house[j + 1].open_time = starting_time;
            house[j + 1].close_time = ending_time;

        }
//        house[0].open_time = 0;
//        house[0].close_time = 0;
//        for(j = 0; j < games_to_complete + 1; j++){
//            printf("house[%d] open: %d\n", j, house[j].open_time);
//            printf("house[%d] close: %d\n", j, house[j].close_time);
//        }


        //nested loop to collect travel times...
        for(l = 0; l < games_to_complete + 1; l++){
            //distance_handler[l].distance_to = malloc(sizeof(int) * games_to_complete);
            //distance_handler[l].distance_from = malloc(sizeof(int) * games_to_complete);
            for(m = 0; m < games_to_complete + 1; m++){
                scanf("%d", &travel_times[m][l]);
                //printf("%d ", travel_times[m][l]);
                printf("%d ", travel_times[l][m]);

                distance_handler[l].distance_to = travel_times[m][l];
                distance_handler[l].distance_from = travel_times[l][m];
                //printf("\ndis to: %d ", distance_handler[l].distance_to);
                //printf("\ndis from: %d ", distance_handler[l].distance_from);
            }
            printf("\n");
        }


        printf("\n");

    }
    free(house);



    return 0;
}



