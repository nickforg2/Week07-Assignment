#include <iostream>
#include <time.h>
using namespace std;

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
}

///////////////////////////////////////////////
void Merge(int nums[], int i, int j, int k) {
    int mergedSize = k - i + 1;
    int mergePOS = 0;
    int leftPOS = 0;
    int rightPOS = 0;
    auto mergedNumbers = new int[mergedSize];


    leftPOS = i;
    rightPOS = j + 1;

    while (leftPOS <= j && rightPOS <= k) {
        if (nums[leftPOS] <= nums[rightPOS]) {
            mergedNumbers[mergePOS] = nums[leftPOS];
            ++leftPOS;
        }
        else {
            mergedNumbers[mergePOS] = nums[rightPOS];
            ++rightPOS;
        }
        ++mergePOS;
    }

    while (leftPOS <= j) {
        mergedNumbers[mergePOS] = nums[leftPOS];
        ++leftPOS;
        ++mergePOS;
    }

    while (rightPOS <= k) {
        mergedNumbers[mergePOS] = nums[rightPOS];
        ++rightPOS;
        ++mergePOS;
    }
    for (mergePOS = 0; mergePOS < mergedSize; ++mergePOS) {
        nums[i + mergePOS] = mergedNumbers[mergePOS];
    }
}

void mergeSort(int nums[], int i, int k) {

    int j = 0;

    if (i < k) {
        j = (i + k) / 2;
        mergeSort(nums, i, j);
        mergeSort(nums, j + 1, k);
        Merge(nums, i, j, k);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Menu() {

    cout << "0. Selection Sort\n1. Insertion Sort\n2. Bubble Sort\n3. Merge Sort\n4. Exit";
}



int main() {
    const int sizeOfArray = 10000;
    int largeArray[sizeOfArray], choice, temp[sizeOfArray];

    srand(time(NULL));
    for (int i = 0; i < sizeOfArray; i++) {
        largeArray[i] = rand() % 1000000;
        temp[i] = largeArray[i];
    }


    do {
        Menu();
        cout << "\nEnter your method of sorting please" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "\nUNSORTED" << endl;
            srand(time(NULL));
            for (int i = 0; i < sizeOfArray; i++) {
                largeArray[i] = rand() % 10000;
            }
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            selectionSort(largeArray, 10000);
            cout << "\nSORTED" << endl;
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            break;

        case 1:
            cout << "\nUNSORTED" << endl;
            srand(time(NULL));
            for (int i = 0; i < sizeOfArray; i++) {
                largeArray[i] = rand() % 10000;
            }
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            insertionSort(largeArray, 10000);
            cout << "\nSORTED" << endl;
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            break;

        case 2:
            cout << "\nUNSORTED" << endl;
            srand(time(NULL));
            for (int i = 0; i < sizeOfArray; i++) {
                largeArray[i] = rand() % 10000;
            }
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            BubbleSort(largeArray, 10000);
            cout << "\nSORTED" << endl;
            for (int i = 0; i < 50; i++)
                cout << largeArray[i] << endl;
            break;

        case 3:
            cout << "\nUNSORTED" << endl;
            srand(time(NULL));
            for (int i = 0; i < sizeOfArray; i++) {
                largeArray[i] = rand() % 10000;
            }
            for (int i = 0; i < 100; i++)
                cout << largeArray[i] << endl;
            mergeSort(largeArray, 0, 10000);
            cout << "\nSORTED" << endl;

            for (int i = 0; i < 100; i++)
                cout << largeArray[i] << endl;
            break;

        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice <= 4);
    return 0;
}
