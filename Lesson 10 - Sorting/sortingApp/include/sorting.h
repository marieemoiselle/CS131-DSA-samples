#ifndef SORTING_H
#define SORTING_H

// Display function
void display(int arr[], int n);

// Sorting algorithms
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

// Quick sort
void quickSort(int arr[], int low, int high, int size);
int partition(int arr[], int low, int high);

// Merge sort
void mergeSort(int arr[], int left, int right, int size);
void merge(int arr[], int left, int mid, int right);

#endif