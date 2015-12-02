/*created by Raphael Miller
 * NID: ra677877
 * December 7th 2015*/

#include <stdio.h>
#include <stdlib.h>

struct Game_House {
    int *house_name;
    int **game_time;
};

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
        int travel_times[games_to_complete + 1][ games_to_complete + 1];
        int l, m;

        for(j = 0; j < games_to_complete; j++){
            scanf("%d %d", &starting_time, &ending_time);
            //from here we have p(i) and the starting time and ending time for said values. introduce struct
            house.game_time[j][0] = starting_time;
            house.game_time[j][1] = ending_time;
            house.house_name[j] = j;

            printf("start: %d\n", house.game_time[j][0]);
            printf("end: %d\n", house.game_time[j][1]);
            printf("housename: %d\n", house.house_name[j]);
        }

        for(l = 0; l < games_to_complete + 1; l++){
            for(m = 0; m < games_to_complete + 1; m++){
                scanf("%d", &travel_times[m][l]);
                printf("t[%d][%d]: %d ", m, l, travel_times[m][l]);
            }
        }
        printf("\n");
        free(house.game_time);
        free(house.house_name);
    }


    return 0;
}