#pragma once

static class Sorts
{
    void selectionSort(int a[], int size) {
        int outer, inner, min;
        for (outer = 0; outer < size - 1; outer++) {
            min = outer;
            for (inner = outer + 1; inner < size; inner++) {
                if (a[inner] < a[min]) {
                    min = inner;
                }
            }
            int temp = a[outer];
            a[outer] = a[min];
            a[min] = temp;
        }
    }
    ///////////////////////////////////////////////
    void insertionSort(int nums[], int numSize) {
        int i, j = 0;
        int temp = 0;

        for (int i = 1; i < numSize; i++) {
            j = i;
            while (j > 0 && nums[j] < nums[j - 1]) {
                temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
                --j;
            }
        }
    }
    ///////////////////////////////////////////////
    void BubbleSort(int arr[], int size) {

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }






};

