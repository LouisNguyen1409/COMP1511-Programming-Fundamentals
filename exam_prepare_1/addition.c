// z5428797
#include <stdio.h>

int main(void) {
    printf("Please enter the number of students and tutors: ");
    int students, tutors;
    scanf("%d %d", &students, &tutors);
    int total = students + tutors;
    printf("%d + %d = %d\n", students, tutors, total);
    return 0;
}