#include <iostream>

using namespace std;

int main() {
    //program counts how many numbers are prime numbers and displays them.

    int top_range = 10;
    bool check_prime = false;

    cout << "Enter range: " << endl;
    //cin >> top_range;

    //program then takes the number and counts up to see if it is prime, prime being if it only can be divided by 1 and
    //itself evenly




    for(int x = 1; x < top_range; x++){
        for (int y = 2; y <= x; y++){
            if ((y % x) == 0){
                check_prime = true;
                cout << y << " " <<  check_prime << endl;
            } else {
                check_prime = false;
                cout << y << " " <<  check_prime << endl;
            }
        }
    }



    return 0;
}