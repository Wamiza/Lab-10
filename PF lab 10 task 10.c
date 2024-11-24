#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100
#define MAX_NAME_LEN 50

struct TravelPackage {
    char packageName[MAX_NAME_LEN];
    char destination[MAX_NAME_LEN];
    int duration;        
    int cost;          
    int seatsAvailable;  
};

void displayPackages(struct TravelPackage packages[], int count);
void bookPackage(struct TravelPackage packages[], int count);

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

    printf("Enter the number of travel packages: ");
    scanf("%d", &packageCount);
    getchar(); 
    
    for (int i = 0; i < packageCount; i++) {
        printf("\nEnter details for package %d:\n", i + 1);
        printf("Package Name: ");
        fgets(packages[i].packageName, MAX_NAME_LEN, stdin);
        packages[i].packageName[strcspn(packages[i].packageName, "\n")] = '\0';

        printf("Destination: ");
        fgets(packages[i].destination, MAX_NAME_LEN, stdin);
        packages[i].destination[strcspn(packages[i].destination, "\n")] = '\0';

        printf("Duration (in days): ");
        scanf("%d", &packages[i].duration);

        printf("Cost: ");
        scanf("%d", &packages[i].cost);

        printf("Number of Seats Available: ");
        scanf("%d", &packages[i].seatsAvailable);
        getchar(); 
    }

    do {
        printf("\nTravel Package Management\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Travel Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
	while (choice != 3);

    return 0;
}

void displayPackages(struct TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-8d | %-10d | %-10d |\n", "Package Name", "Destination", "Duration", "Cost", "Seats");
    printf("-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-15s | %-8d | %-10d | %-10d |\n",
               packages[i].packageName, packages[i].destination, packages[i].duration, packages[i].cost, packages[i].seatsAvailable);
    }
    printf("-----------------------------------------------------------------------------------\n");
}

void bookPackage(struct TravelPackage packages[], int count) {
    char packageName[MAX_NAME_LEN];
    int found = 0;

    if (count == 0) {
        printf("No travel packages available to book.\n");
        return;
    }

    printf("Enter the name of the package you want to book: ");
    fgets(packageName, MAX_NAME_LEN, stdin);
    packageName[strcspn(packageName, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
        if (strcmp(packages[i].packageName, packageName) == 0) {
            found = 1;
            if (packages[i].seatsAvailable > 0) {
                packages[i].seatsAvailable--;
                printf("Booking successful! Seats remaining: %d\n", packages[i].seatsAvailable);
            } else {
                printf("Sorry, no seats available for this package.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Package not found.\n");
    }
}
