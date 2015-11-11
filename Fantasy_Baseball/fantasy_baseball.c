#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_SEASONS 100
#define MAX_PLAYERS 1000

struct Player_stats{
    char *last_name;
    char *first_name;
    int at_bat;
    char* at_bat_stats;

};

void input(struct Player_stats *pStats);
void logic();
void output();

int get_int(int *pInt);
struct Player_stats load_struct(struct Player_stats stats);
char ** str_split(char *buff, const char delim);

int main() {
    struct Player_stats *player = malloc((sizeof(struct Player_stats) * MAX_PLAYERS) * MAX_SEASONS);

    input(player);
    logic();
    output();

    return 0;
}

void output() {

}

void logic() {

}

void input(struct Player_stats *pStats) {
    int i, j;

    int seasons = 0; //n(n < 100)
    int players = 0; //p(p < 1000)

    seasons = get_int(&seasons);

    for(i = 0; i < seasons; i++){
        //for loop to rotate through the seasons
        players = get_int(&players);
        for(j = 0; j <= players; j++){
            pStats[j] = load_struct(pStats[j]);
        }

    }

}

struct Player_stats load_struct(struct Player_stats stats) {
    struct Player_stats result;

    int i = 0;
    char *buff = malloc(sizeof(char) * 1024);
    char *player_stats = malloc(sizeof(char) * 20);
    char last_name[20], first_name[20];
    int at_bat;
    char **tokens;


    buff = fgets(buff, 1024, stdin);
    sscanf(buff, "%s %s %d %[^\n]s", last_name, first_name, &at_bat, player_stats);
    printf("%s %s %d -- %s\n", first_name, last_name, at_bat, player_stats);




//    printf("%s", buff); // at this point we have one line for the struct
//
//    tokens = str_split(buff, ' ');
//
//    if(tokens){
//        int i;
//        for(i = 0; *(tokens + i); i++){
//            printf("%s\n", *(tokens + i));
//
//        }
//        printf("\n");
//
//    }

    //stats.last_name = tokens[0];
    //stats.first_name = tokens[1];



    //free(tokens);
    return result;
}

char ** str_split(char *buff, const char delim) {
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = buff;
    char* last_comma = 0;
    char string[2];
    string[0] = delim;
    string[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (buff + strlen(buff) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(buff, string);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, string);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int get_int(int *pInt) {
    scanf("%d", pInt);
    return *pInt;
}