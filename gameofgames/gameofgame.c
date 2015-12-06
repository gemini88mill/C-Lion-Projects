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
    int *distance_from;
    int *distance_to;
};

struct Game_Time_Handler{
    int current_game_time;
    int number_of_houses;
    int houses_visited;
};


void logic(struct House_data *house_data, struct Distance_Handler *distance_handler,
           struct Game_Time_Handler time_handler, int location);

int check_if_open(int game_time, struct House_data house_data);

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
        game_time.number_of_houses = games_to_complete;
        //allocates memory for number of houses + 1 (for home base)
        house = malloc(sizeof(struct House_data) * games_to_complete + 1);
        //allocates memory for number of distances to and from houses(including home base)
        distance_handler = malloc(sizeof(struct Distance_Handler) * games_to_complete + 1);

        int **travel_times = malloc(sizeof(int*) * games_to_complete + 1);
        int n;
        for(n = 0; n < games_to_complete + 1; n++){
            travel_times[n] = malloc(sizeof(int) * games_to_complete + 1);
        }
        int l, m;

        int gg = games_to_complete;
        for(j = 0; j < gg; j++){

            //collection of travel time.
            scanf("%d %d", &house[j + 1].open_time, &house[j + 1].close_time);
            //from here we have p(i) and the starting time and ending time for said values. introduce struct

            /*sets house variables within the struct, designates the start and end times for each house. sets them to
             * j + 1 because there is no start or end time for home_base house. So start and end times are in house 1
             * ans house 2*/
//            house[j + 1].open_time = starting_time;
//            house[j + 1].close_time = ending_time;

        }
        house[0].open_time = 0;
        house[0].close_time = 0;
//        for(j = 0; j < games_to_complete + 1; j++){
//            printf("house[%d] open: %d\n", j, house[j].open_time);
//            printf("house[%d] close: %d\n", j, house[j].close_time);
//        }


        //nested loop to collect travel times...
        for(l = 0; l < games_to_complete + 1; l++){
            distance_handler[l].distance_to = malloc(sizeof(int) * games_to_complete + 1);
            for(m = 0; m < games_to_complete + 1; m++){
                scanf("%d", &travel_times[m][l]);
                distance_handler[l].distance_to[m] = travel_times[m][l];
                //printf("\ndis to: %d ", distance_handler[l].distance_to);
            }
            //printf("\n");
        }

        for(l = 0; l < games_to_complete + 1; l++){
            distance_handler[l].distance_from = malloc(sizeof(int) * games_to_complete + 1);
            for(m = 0; m < games_to_complete + 1; m++){
                distance_handler[l].distance_from[l] = travel_times[l][m];
                //printf("dis from: %d \n", distance_handler[l].distance_from);
            }
        }


        printf("\n");

        int current_location = 0;
        game_time.houses_visited = 0;
        //todo place logic function here
        logic(house, distance_handler, game_time, current_location);
        if(game_time.houses_visited == game_time.number_of_houses)
            printf("all houses visited");

        printf("\n");

    } // end of big loop
    //free(house);



    return 0;
}

void logic(struct House_data *house_data, struct Distance_Handler *distance_handler,
           struct Game_Time_Handler time_handler, int location) {
    if(time_handler.houses_visited == time_handler.number_of_houses)
        return;

    //logic...
    int i;


    /*for loop to check houses for opening, if open do more stuff...*/
    for(i = 0; i < time_handler.number_of_houses + 1; i++) {
            house_data[i].is_open = check_if_open(distance_handler[location].distance_to[i], house_data[i]);
        if(house_data[i].is_open == 1){
            house_data->is_visited = 1; //marks house for visited
            location = i;
            time_handler.houses_visited++;
            logic(house_data, distance_handler, time_handler, location);
        }
    }

}

int check_if_open(int game_time, struct House_data house_data) {
    //function to return if particular house is open, if house is open, return 1, if not, return 0
    if (game_time > house_data.open_time && game_time < house_data.close_time){
        printf("house is open\n");
        return 1;
    }
    printf("house is closed\n");
    return 0;
}



//todo logic function: requiring system for keeping track of time, distance, and visiting of houses



