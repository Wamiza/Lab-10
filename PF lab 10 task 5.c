#include <stdio.h>

void function(int arr[], int size, int index);

int main() {
    int size, arr[100];

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid array size.\n");
        return 1;
    }
    
    function(arr, size, 0);

    printf("The elements of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void function(int arr[], int size, int index) {
    if (index == size) {
     return;
    }

    printf("Enter element : ");
    scanf("%d", &arr[index]);

    function(arr, size, index + 1);
}
