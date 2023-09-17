#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct passenger {
    double height;
    int num_bags;
};

int main(void) {

    struct passenger my_array[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        printf("Enter height & number of bags: ");
        scanf("%lf %d", &my_array[i].height, &my_array[i].num_bags);
    }
    printf("Select height: ");
    double selected;
    scanf("%lf", &selected);
    int bags = 0;
    for (int i = 0; i < SIZE; i++) {
        if (my_array[i].height >= selected) {
            bags += my_array[i].num_bags;
        }
    }
    printf("Total of %d bags from people over %lf\n", bags, selected);

    return 0;
}