#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[][2], int low, int high) {
    int pivot = arr[high][1];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j][1] < pivot) {
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    return i + 1;
}

void quickSort(int arr[][2], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[][2], int size) {
    for (int i = 0; i < size; i++) {
        printf("{%d,%d} ", arr[i][0], arr[i][1]);
    }
    printf("\n");
}

void activitySelection(int arr[][2], int n) {
    int i = 0;
    printf("Selected activities:\n{%d,%d} ", arr[i][0], arr[i][1]);
    for (int j = 1; j < n; j++) {
        if (arr[j][0] >= arr[i][1]) {
            printf("{%d,%d} ", arr[j][0], arr[j][1]);
            i = j;
        }
    }
    printf("\n");
}

int main() {
    int jobs[100][2], n;
    printf("Enter the total number of activities: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the start time for activity %d: ", i + 1);
        scanf("%d", &jobs[i][0]);
        printf("Enter the end time for activity %d: ", i + 1);
        scanf("%d", &jobs[i][1]);
    }
    printf("Activities before sorting:\n");
    printArray(jobs, n);
    quickSort(jobs, 0, n - 1);
    printf("Activities after sorting:\n");
    printArray(jobs, n);
    activitySelection(jobs, n);
    return 0;
}
