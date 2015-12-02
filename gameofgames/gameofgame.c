/*created by Raphael Miller
 * NID: ra677877
 * December 7th 2015*/

#include <stdio.h>
#include <stdlib.h>

struct Game_House {
    int *house_name;
    int **game_time;
};

void logic(struct Game_House house, int **travel_times, int game_houses);

int open_house(int current_game_time, struct Game_House house, int house_number);

int main() {
    int input_cases, i;
    int games_to_complete, j;
    int starting_time, ending_time, k;


    struct Game_House house;





    scanf("%d", &input_cases);

    for(i = 0; i < input_cases; i++){
        house.game_time = malloc(sizeof(int*) * 8);
        for(k = 0; k < 8; k++) {
            house.game_time[k] = malloc(sizeof(int) * k);
        }
        house.house_name = malloc(sizeof(int) * 8);


        scanf("%d", &games_to_complete); //number of games to complete
        int **travel_times = malloc(sizeof(int*) * games_to_complete + 1);
        int n;
        for(n = 0; n < games_to_complete + 1; n++){
            travel_times[n] = malloc(sizeof(int) * games_to_complete + 1);
        }
        int l, m;

        for(j = 0; j < games_to_complete; j++){
            scanf("%d %d", &starting_time, &ending_time);
            //from here we have p(i) and the starting time and ending time for said values. introduce struct
            house.game_time[j][0] = starting_time;
            house.game_time[j][1] = ending_time;
            house.house_name[j] = j;

//            printf("start: %d\n", house.game_time[j][0]);
//            printf("end: %d\n", house.game_time[j][1]);
//            printf("housename: %d\n", house.house_name[j]);
        }

        for(l = 0; l < games_to_complete + 1; l++){
            for(m = 0; m < games_to_complete + 1; m++){
                scanf("%d", &travel_times[m][l]);

            }

        }

        logic(house, travel_times, games_to_complete);
        printf("\n");
        free(house.game_time);
        free(house.house_name);
    }


    return 0;
}

void logic(struct Game_House house, int **travel_times, int game_houses) {
    //printf("\nin logic\n\n");
    int i, j;

    //debug travel times check
    for(i = 0; i < game_houses + 1; i++){
        for(j = 0; j < game_houses + 1; j++){
            printf("t[%d][%d]: %d \t\t", j, i, travel_times[j][i]);
        }
        printf("\n");
    }

    /*pseudo code:
     *
     *  Start at home base. p(0)
     *  based on how many "challenge houses" there are, find which house is the quickest to get to
     *  from p(0) (first line in travel_times) travel_times[n][0], find quickest travel time
     *
     *      first sample - 0 5 10
     *      if travel_time != 0
     *          compare remaining travel times
     *          if travel_time[n1][0] < travel_time[n2][0]
     *              (go to n1 associate) new function.
     *          else if (...)
     *              (go to nX associate) new function.
     *
     *
     *  should go to new function either way if function reaches here produce error handler*/

    //travel from travel_house
    int game_time = 0;
    int n;

    for(n = 0; n < game_houses + 1; n++) {
        if (travel_times[n][0] != 0) {
            //goto new function
            /*function requirements: compares game time with house challenge time.*/
            open_house((game_time + travel_times[n][0]), house, n);
        }
    }

}

int open_house(int current_game_time, struct Game_House house, int house_number) {
    if(current_game_time > house.game_time[house_number - 1][0]){
        printf("house open");
    }

    return 0;
}