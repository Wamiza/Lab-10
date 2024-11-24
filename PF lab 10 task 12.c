#include <stdio.h>

void linearSearch(int arr[], int size, int target, int currentIndex) {
    if (currentIndex >= size) {
        return;
    }

    if (arr[currentIndex] == target) {
        printf("Element %d found at index %d.\n", target, currentIndex);
    }
   linearSearch(arr, size, target, currentIndex + 1);
}

int main() {
    int n, target;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    printf("Searching for element %d in the array...\n", target);
    linearSearch(arr, n, target, 0);

  return 0;
}
