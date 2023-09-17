#include <stdio.h>


void find_factorial(int num, int *factorial);


int main(void){
    int factorial;
    int number;
		
	printf("Please enter a number to find factorial of: ");
	scanf("%d",&number);		 

    find_factorial(number, &factorial);
    printf("%d! = %d\n", number, factorial);

    return 0;
}

// This function finds the factorial of a number using pointers
void find_factorial(int number, int *factorial){
    *factorial = 1;
    for (int i = 1; i <= number; i++) {
        *factorial *= number;
    }

}