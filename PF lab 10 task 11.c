#include <stdio.h>

#define METERS_TO_KILOMETERS 0.001

double convertMetersToKilometers(double meters);

int main() {
    double meters, kilometers;
    int choice;

    do {
        printf("\nMeter to Kilometer Converter\n");
        printf("1. Convert meters to kilometers\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the distance in meters: ");
                scanf("%lf", &meters);
                kilometers = convertMetersToKilometers(meters);
                printf("Distance in kilometers: %.2f\n", kilometers);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 
	while (choice != 2);
    return 0;
}

double convertMetersToKilometers(double meters) {
    static int callCount = 0; 
    callCount++;
    printf("This function has been called %d times.\n", callCount);
    return meters * METERS_TO_KILOMETERS;
}
