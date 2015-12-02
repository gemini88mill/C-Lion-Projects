#include <stdio.h>
#include <stdlib.h>



int main() {
    int stock_scenario, i;
    int scenario_days, d;
    double transaction_fee;
    int investment;

    double stock_one;
    double stock_two;

    scanf("%d", &stock_scenario);

    for(i = 0; i < stock_scenario; i++){
        scanf("%d %lf %d", &scenario_days, &transaction_fee, &investment);  //line 1
        for(d = 0; d < scenario_days; d++){
            scanf("%lf", &stock_one);
        }
        for(d = 0; d < scenario_days; d++){
            scanf("%lf", &stock_two);
        }
    }
    return 0;
}