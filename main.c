#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool shouldSwap(int arr[], int start, int current) {
    for (int i = start; i < current; i++) {
        if (arr[i] == arr[current]) {
            return false;
        }
    }
    return true;
}

void generatePermutations(int arr[], int left, int right) {
    if (left == right) {
        printArray(arr, right + 1);
        return;
    }

    for (int i = left; i <= right; i++) {
        if (shouldSwap(arr, left, i)) {
            swap(&arr[left], &arr[i]);
            generatePermutations(arr, left + 1, right);
            swap(&arr[left], &arr[i]); // backtrack
        }
    }
}

int main(void) {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    printf("\nPermutations:\n");
    generatePermutations(arr, 0, n - 1);

    free(arr);
    return 0;
}