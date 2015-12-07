/*created by Raphael Miller
 * NID: ra677877
 * December 7th 2015*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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


int logic(struct House_data *house_data, struct Distance_Handler *distance_handler,
          struct Game_Time_Handler time_handler, int location, int i);

int check_if_open(int game_time, struct House_data house_data, int current_time);

void logistics(struct House_data *house_data, struct Distance_Handler *distance_handler,
               struct Game_Time_Handler game_time);

int travel_to_houses(struct House_data *current_house, struct House_data *house_data, int house_number, int num_houses,
                     struct Game_Time_Handler *game_time, struct Distance_Handler *distances);

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
        game_time.current_game_time = 0;

        logistics(house, distance_handler, game_time);
//        int last_house_time_marker = logic(house, distance_handler, game_time, current_location,
//                                           game_time.current_game_time);
       // printf("visited last house at: %d\n", last_house_time_marker);

        printf("\n");

    } // end of big loop
    //free(house);



    return 0;
}

void logistics(struct House_data *house_data, struct Distance_Handler *distance_handler,
struct Game_Time_Handler game_time) {
    /*function starts from starting house, house_data[0] and gets into every house in every possible way, returns the
     * shortest distance. */

    int num_visited = travel_to_houses(&house_data[0], house_data, 0, game_time.number_of_houses, &game_time,
                                       distance_handler);
    printf("num_visited: %d", num_visited);

}

int travel_to_houses(struct House_data *current_house, struct House_data *house_data, int house_number, int num_houses,
                     struct Game_Time_Handler *game_time, struct Distance_Handler *distances) {
    //marks the current house as being visited
    if(current_house->is_visited == TRUE){
        printf("house num %d\n", house_number);
        return 1;
    }


    int i;
    for(i = 0; i < num_houses + 1; i++) {
        current_house->is_visited = TRUE;
        game_time->current_game_time = game_time->current_game_time + distances[house_number].distance_to[i];
        printf("game_time %d\n", game_time->current_game_time);
        travel_to_houses(&house_data[i], house_data, i, num_houses, game_time, distances);
    }
}


int logic(struct House_data *house_data, struct Distance_Handler *distance_handler,
          struct Game_Time_Handler time_handler, int location, int game_time) {


    //logic...
    int i = 2;

    //from location 0(homebase) to challenge house number.

    //for loop cycles through houses、明日仕事やすみじゃない

    for(i = 0; i < time_handler.number_of_houses + 1; i++) {
        if(house_data[i].is_visited != TRUE) {
            if (check_if_open(distance_handler[location].distance_to[i], house_data[i],
                              time_handler.current_game_time) == TRUE) {

                //mark for house visited, therefore gametime must be updated
                house_data[i].is_visited = TRUE;
                game_time = game_time + distance_handler[location].distance_to[i];
                printf("gametime: %d", time_handler.current_game_time);

                //re-enter logic using new perameters
                //current song: Adventure Time(Original Mix) - SirensCeol
                logic(house_data, distance_handler, time_handler, i, game_time);
            }
        }
        //check house visitation
        int k;
        for(k = 1; k < time_handler.number_of_houses + 1; k++){
            if(house_data[k].is_visited == TRUE) {
                time_handler.houses_visited++;
                if(time_handler.houses_visited == time_handler.number_of_houses){
                    return game_time;
                }
            }
        }
    }
    return 0;
}

int check_if_open(int game_time, struct House_data house_data, int current_time) {
    //function to return if particular house is open, if house is open, return 1, if not, return 0
    game_time += current_time;

    if (game_time > house_data.open_time && game_time < house_data.close_time){
        //printf("house is open\n");
        return TRUE;
    }
    //printf("house is closed\n");
    return FALSE;
}





//todo logic function: requiring system for keeping track of time, distance, and visiting of houses



