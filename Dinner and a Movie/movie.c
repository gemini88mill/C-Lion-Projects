#include <stdlib.h>
#include <stdio.h>

#define TICKET_COST 10
#define PIZZA_COST 2

int main() {
    int testcases = 0, i, tickets = 0, pizza = 0, total_cost = 0;

    scanf("%d", &testcases); //collects the number of test cases

    for(i = 0; i < testcases; i++){
        scanf("%d %d", &tickets, &pizza);

        if(tickets < 10){
            total_cost = (tickets * TICKET_COST) + (pizza * PIZZA_COST);

        }else{
            total_cost = (tickets * TICKET_COST) + pizza;
        }
        printf("%d\n", total_cost);
    }
    return 0;
}