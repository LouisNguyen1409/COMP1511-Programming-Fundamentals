// Written by Dinh Minh Nhat Nguyen (z54528797) 
// on 16/03/2023
//
// Interactive program to scan in and calculate 
// details about the weather

#define NUM_TEMPS 4
#define NUM_HUMIDITY 5

#include <stdio.h>

void print_info(void);
void read_temp(double temps[NUM_TEMPS]);
void read_hum(double humidity[NUM_HUMIDITY]);
double aver_temp(double temps[NUM_TEMPS]);
double aver_hum(double humidity[NUM_HUMIDITY]);
void print_temp_info(double average_temp);
void print_hum_info(double average_humidity);

int main(void) {

    // Intro
    print_info();

    // Read Temperatures
    double temps[NUM_TEMPS] = {0.0};
    read_temp(temps);

    // Read Humidities
    double humidity[NUM_HUMIDITY] = {0.0};
    read_hum(humidity);
    // Get average Temperature
    double average_temp = aver_temp(temps);

    // Get average humidity
    double average_humidity = aver_hum(humidity);

    // Give info about average temp
    print_temp_info(average_temp);

    // Give info about average humidity
    print_hum_info(average_humidity);

    return 0;
}

// print intro information
void print_info(void) {
    printf("Hello and welcome to CS Weather!\n");
    printf("=======================================\n");
    printf("This program will help you to analyse a given weather patten\n");
    printf("and make some predictions about the coming day\n");
}

// get in temperature
void read_temp(double temps[NUM_TEMPS]) {
    printf("Please enter the past %d day(s) worth of temperatures.\n", NUM_TEMPS);
    int counter = 0;
    while (counter < NUM_TEMPS) {
        scanf("%lf", &temps[counter]);
        counter++;
    }
}

// get in huidities
void read_hum(double humidity[NUM_HUMIDITY]) {
    printf("Please enter the last %d days(s) worth of humidities\n", NUM_HUMIDITY);
    int counter = 0;
    while (counter < NUM_HUMIDITY) {
        scanf("%lf", &humidity[counter]);
        counter++;
    }
}

// calculate average temperature
double aver_temp(double temps[NUM_TEMPS]) {
    int counter = 0;
    double sum = 0.0;
    while (counter < NUM_TEMPS)
    {
        sum += temps[counter];
        counter++;
    }
    return sum / NUM_TEMPS;
}

// calculate average humidity
double aver_hum(double humidity[NUM_HUMIDITY]) {
    int counter = 0;
    double sum = 0.0;
    while (counter < NUM_HUMIDITY)
    {
        sum += humidity[counter];
        counter++;
    }
    return sum / NUM_HUMIDITY;
}

// print information about temperature
void print_temp_info(double average_temp) {
    printf("The average temperature was: %lf\n", average_temp);
    if (average_temp >= 28.0) {
        printf("It will be hot tomorrow!");
    } else if (average_temp >= 15.0 && average_temp < 28.0 ) {
        printf("Should be a lovely temperature tomorrow.\n");
    } else {
        printf("It'll be chilly tomorrow, pack a jumper!\n");
    }
}

// print information about huidities
void print_hum_info(double average_humidity) {
    printf("The average humidity was: %lf\n", average_humidity);
    if (average_humidity > 80.0) {
        printf("It will be humid tomorrow.\n");
    } else {
        printf("Shouldn't be too humid tomorrow.\n");
    }
}