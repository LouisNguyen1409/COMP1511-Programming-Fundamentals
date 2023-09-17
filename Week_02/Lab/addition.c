// addition
// addition.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 19/02/2023
//
// Add together the number of students and tutors in a class

#include <stdio.h>

int main (void){
    int students = 0;
    int tutors = 0;

    printf("Please enter the number of students and tutors: ");
    scanf("%d %d", &students, &tutors);
    int total = students + tutors;

    printf("%d + %d = %d\n", students, tutors, total);

    return 0;
}