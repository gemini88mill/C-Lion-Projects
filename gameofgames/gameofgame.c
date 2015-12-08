/*created by Raphael Miller
 * NID: ra677877
 * December 7th 2015*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct House_data {
    int is_visited;
    int open_time;
    int close_time;
};

struct Distance_Handler{
    int *distance_from;
    int *distance_to;
};

struct Game_Time_Handler{
    int travel_time;
    int number_of_houses;
    int houses_visited;
    int accu_game_time;
};


int logic(struct House_data *house_data, struct Distance_Handler *distance_handler,
          struct Game_Time_Handler time_handler, int location, int i);

int check_if_open(int game_time, struct House_data house_data, int current_time);

void logistics(struct House_data *house_data, struct Distance_Handler *distance_handler,
               struct Game_Time_Handler game_time);

int travel_to_houses(struct House_data *current_house, struct House_data *house_data, int house_number, int num_houses,
                     struct Game_Time_Handler *game_time, struct Distance_Handler *distances);

int is_house_open(int open, int close, int current);

int get_max(struct House_data *house_data, int num_houses);

int main() {

    //number of input cases for problem
    int input_cases, i;

    //number of games to complete, second value collected
    int games_to_complete, j = 0;

    //structs for collection of data
    struct House_data *house;
    struct Distance_Handler *distance_handler;
    struct Game_Time_Handler game_time;



    //take input cases
    scanf("%d", &input_cases);

    //start for loop for number of input cases
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

        }
        house[0].open_time = 0;
        house[0].close_time = 0;

        //nested loop to collect travel times...
        for(l = 0; l < games_to_complete + 1; l++){
            distance_handler[l].distance_to = malloc(sizeof(int) * games_to_complete + 1);
            for(m = 0; m < games_to_complete + 1; m++){
                scanf("%d", &travel_times[m][l]);
                distance_handler[l].distance_to[m] = travel_times[m][l];
            }
            //printf("\n");
        }

        for(l = 0; l < games_to_complete + 1; l++){
            distance_handler[l].distance_from = malloc(sizeof(int) * games_to_complete + 1);
            for(m = 0; m < games_to_complete + 1; m++){
                distance_handler[l].distance_from[l] = travel_times[l][m];
            }
        }


        printf("\n");


        game_time.houses_visited = 0;
        game_time.travel_time = 0;

        logistics(house, distance_handler, game_time);

    } // end of big loop

    return 0;
}

void logistics(struct House_data *house_data, struct Distance_Handler *distance_handler,
struct Game_Time_Handler game_time) {
    /*function starts from starting house, house_data[0] and gets into every house in every possible way, returns the
     * shortest distance. */
    int house_number = 0;

    travel_to_houses(&house_data[0], house_data, house_number, game_time.number_of_houses, &game_time,
                                       distance_handler);
    printf("%d", game_time.accu_game_time + distance_handler[1].distance_to[0]);

}

int travel_to_houses(struct House_data *current_house, struct House_data *house_data, int house_number, int num_houses,
                     struct Game_Time_Handler *game_time, struct Distance_Handler *distances) {
    int maximum_game_time = get_max(house_data, game_time->number_of_houses);
    //marks the current house as being visited
    if(current_house->is_visited == TRUE){
        int game = game_time->accu_game_time + distances[house_number].distance_to[0];
        //how long can i stay
        //int stay = current_house->close_time - game;

        //printf("current game time: %d\n", game);
        //printf("exit %d\n", house_number);
        return game;
    }
    //printf("house %d\n", house_number);

    int i;
    for(i = 1; i < num_houses + 1; i++) {
        current_house->is_visited = TRUE;

        //if statement to verify we aren't trying to re-enter house currently in. therefore, for loop will skip at the
        //iteration that the player is currently at.

        //sets the current house to TRUE in order to mark

            //increments the time for the game to progress based on the "distance traveled"
            game_time->travel_time = game_time->travel_time + distances[house_number].distance_to[i];
            //printf("time before check: %d\n", game_time->travel_time);

            //checks availibility of house, if open enters if statement under true condition
            int open = is_house_open(house_data[i].open_time, house_data[i].close_time, game_time->travel_time);
            if (open == TRUE) {
                //game_time->travel_time = game_time->travel_time + distances[house_number].distance_to[i];
                //printf("house open ");
                //printf("game_time %d\n", game_time->travel_time);
                game_time->travel_time++;
                game_time->accu_game_time += (game_time->travel_time - house_data[i].open_time);
                //printf("accu_time %d\n", game_time->accu_game_time);
                //re-enter function with given perams
                travel_to_houses(&house_data[i], house_data, i, num_houses, game_time, distances);

            } else {
                //false condition, adds the time nessesary to enter the house. essentially waiting for the challenge house to open
                //current_house->is_visited = FALSE;
                game_time->travel_time = 0;

                //printf("waiting ");
                //printf("game_time %d\n", game_time->travel_time);

            }
        //travel_to_houses(&house_data[house_number], house_data, house_number, num_houses, game_time, distances);

    }
}

int get_max(struct House_data *house_data, int num_houses) {
    int i;
    int close_add = 0, open_add = 0;
    for(i = 1; i <= num_houses; i++){
        close_add += house_data[i].close_time;
        open_add += house_data[i].open_time;
    }

    return 30;
}

int is_house_open(int open, int close, int current) {
    if(current > open && current < close){
        return TRUE;
    }
    return FALSE;
}












