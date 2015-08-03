#include <iostream>
#include <time.h>
#include <stdint.h>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    time_t result = time(NULL);
    if (result != -1){
        printf("the current time is %s(%ju seconds since the last epoch)\n",
            asctime((gmtime(&result))), (uintmax_t)result);
    }
    return 0;
}