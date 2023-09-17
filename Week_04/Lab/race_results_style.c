// 
// Written 08/03/2023
// By Dinh Minh Nhat Nguyen z5428797
//
// scans the results of each car in a Formula One race into an array of structs.
// It should then prints out the results of all cars in the race

#include <stdio.h>


#define MAX_CARS 20

struct race_result {
    // TODO: fill this in with the details of the result of a single car in the
    // race.
    //  
    // i.e. This struct should contain:
    //      the car number (int), 
    //      and the race time (double).
    int car_number;
    double race_time;
};


// Prints the race result in the correct format.
void print_result(int car_number, double race_time);

int main(void) {

    // TODO: Declare an array of structs of size MAX_CARS
    struct race_result results[MAX_CARS];
    printf("How many cars in the race? ");
    // TODO: scan in number of cars in the race
    int number_of_cars = 0;
    scanf("%d", &number_of_cars);

    printf("Enter results:\n");
    // TODO: scan in the details of each car into the array
    for (int i = 0; i < number_of_cars; i++) {
        scanf("%d %lf", &results[i].car_number, &results[i].race_time);
    }

    printf("Results:\n");
    // TODO: print all the results
    for (int i = 0; i < number_of_cars; i++) {
        print_result(results[i].car_number, results[i].race_time);
    }

    return 0;
}


//  Prints the race result in the correct format.
//
// Parameters:
// - `car_number` -- The car number of the result
// - `race_time` -- The time the car took to finish the race.
//
// Returns: nothing.
void print_result(int car_number, double race_time) {
    
    printf("%2d: %.2lf\n", car_number, race_time);
}