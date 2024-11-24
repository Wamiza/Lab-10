#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_STR_LEN 50

struct car {
    char make[MAX_STR_LEN];
    char model[MAX_STR_LEN];
    int year;
    int price;
    int mileage;
};

void addCar(struct car cars[], int *count);
void displayCars(struct car cars[], int count);
void searchCars(struct car cars[], int count);

int main() {
    struct car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        printf("\nCar Dealership Management\n");
        printf("1. Add a New Car\n");
        printf("2. Display Available Cars\n");
        printf("3. Search for Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addCar(cars, &carCount);
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addCar(struct car cars[], int *count) {
    if (*count >= MAX_CARS) {
        printf("Inventory full! Cannot add more cars.\n");
        return;
    }
    struct car newCar;
    printf("Enter Car Make: ");
    fgets(newCar.make, MAX_STR_LEN, stdin);
    newCar.make[strcspn(newCar.make, "\n")] = '\0'; 

    printf("Enter Car Model: ");
    fgets(newCar.model, MAX_STR_LEN, stdin);
    newCar.model[strcspn(newCar.model, "\n")] = '\0'; 

    printf("Enter Year: ");
    scanf("%d", &newCar.year);

    printf("Enter Price: ");
    scanf("%d", &newCar.price);

    printf("Enter Mileage: ");
    scanf("%d", &newCar.mileage);
    getchar();

    cars[*count] = newCar;
    (*count)++;
    printf("Car added successfully!\n");
}

void displayCars(struct car cars[], int count) {
    if (count == 0) {
        printf("No cars available in the inventory.\n");
        return;
    }
    printf("\nAvailable Cars:\n");
    printf("--------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-4s | %-10s | %-7s |\n", "Make", "Model", "Year", "Price", "Mileage");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %-15s | %-15s | %-4d | %-10d | %-7d |\n",
               cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
    printf("--------------------------------------------------------\n");
}

void searchCars(struct car cars[], int count) {
    if (count == 0) {
        printf("No cars available to search.\n");
        return;
    }

    char query[MAX_STR_LEN];
    printf("Enter make or model to search: ");
    fgets(query, MAX_STR_LEN, stdin);
    query[strcspn(query, "\n")] = '\0'; 

    printf("\nSearch Results:\n");
    printf("--------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-4s | %-10s | %-7s |\n", "Make", "Model", "Year", "Price", "Mileage");
    printf("--------------------------------------------------------\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(cars[i].make, query) || strstr(cars[i].model, query)) {
            printf("| %-15s | %-15s | %-4d | %-10d | %-7d |\n",
                   cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching the search query.\n");
    }
    printf("--------------------------------------------------------\n");
}

