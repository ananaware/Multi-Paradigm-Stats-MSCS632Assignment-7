#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
double calculate_mean(int *arr, int n);
double calculate_median(int *arr, int n);
void calculate_modes(int *arr, int n);

/* Helper for sorting (simple bubble sort to keep it explicit) */
void bubble_sort(int *arr, int n);

int main(void) {
    /* Use the same dataset everywhere for consistency */
    int data[] = {5, 3, 9, 3, 8, 3, 1, 9};
    int n = sizeof(data) / sizeof(data[0]);

    /* Make a copy for median/mode because we will sort in-place */
    int *sorted = (int *)malloc(n * sizeof(int));
    if (sorted == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Copy data into sorted array */
    for (int i = 0; i < n; i++) {
        sorted[i] = data[i];
    }

    bubble_sort(sorted, n);

    double mean = calculate_mean(data, n);
    double median = calculate_median(sorted, n);

    printf("Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Mean: %.3f\n", mean);
    printf("Median: %.3f\n", median);
    printf("Mode(s): ");
    calculate_modes(sorted, n);  /* prints modes and newline inside */

    free(sorted);
    return 0;
}

void bubble_sort(int *arr, int n) {
    int temp;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

double calculate_mean(int *arr, int n) {
    long sum = 0;  /* use long to avoid overflow for larger arrays */
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / (double)n;
}

double calculate_median(int *arr, int n) {
    if (n % 2 == 1) {
        /* Odd length: middle element */
        return (double)arr[n / 2];
    } else {
        /* Even length: average of two middle elements */
        int mid1 = arr[(n / 2) - 1];
        int mid2 = arr[n / 2];
        return ((double)mid1 + (double)mid2) / 2.0;
    }
}

void calculate_modes(int *arr, int n) {
    /* arr is sorted */
    int current_value = arr[0];
    int current_count = 1;
    int max_count = 1;

    /* First pass: find max frequency */
    for (int i = 1; i < n; i++) {
        if (arr[i] == current_value) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
            }
            current_value = arr[i];
            current_count = 1;
        }
    }
    if (current_count > max_count) {
        max_count = current_count;
    }

    /* Second pass: print all values with frequency == max_count */
    current_value = arr[0];
    current_count = 1;
    int first_printed = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == current_value) {
            current_count++;
        } else {
            if (current_count == max_count) {
                if (first_printed) {
                    printf(", ");
                }
                printf("%d", current_value);
                first_printed = 1;
            }
            current_value = arr[i];
            current_count = 1;
        }
    }
    /* Check last run */
    if (current_count == max_count) {
        if (first_printed) {
            printf(", ");
        }
        printf("%d", current_value);
    }
    printf("\n");
}
