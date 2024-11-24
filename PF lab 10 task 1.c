#include <stdio.h>

int sum(int numbers[], int size);

int main() {
    int numbers[15], i, size;

    printf("How many numbers do you want to add (max 15)? ");
    scanf("%d", &size);

    if (size > 15 || size <= 0) {
        printf("Invalid number of elements.\n");
        return 1; 
    }

    printf("Enter %d numbers: " ,size);
    for (i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("The sum of numbers: %d\n", sum(numbers, size));

    return 0;
}

int sum(int numbers[], int size) {
   
   if (size == 0) {
        return 0;
    }
    
    return numbers[size - 1] + sum(numbers, size - 1);
}
