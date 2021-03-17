#include <stdio.h>
#include <stdlib.h>

void retrieve(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}


// time complexsity O(n2), space O(1)
void insertSort(int *a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j+1] < a[j]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void shellSort(int array[], int size) {
    int number = size / 2;
    int i;
    int j;
    int temp;
    while (number >= 1) {
        for (i = number; i < size; i++) {
            temp = array[i];
            j = i - number;
            while (j >= 0 && array[j] < temp) {
                array[j + number] = array[j];
                j = j - number;
            }
            array[j + number] = temp;
        }
        number = number / 2;
    }
}

void selectionSort(int a[], int size) {
    if (size == 0) return;
    int j, k;
    j = 0;
    k = j;
    while(j < size) {
        for (int i = j; i < size; i++) {
            // choose min number
            if (a[k] > a[i]) {
                k = i;
            }
        }

        if (k != j) {
            a[k] = a[k] + a[j];
            a[j] = a[k] - a[j];
            a[k] = a[k] - a[j];
        }
        j++;
    }
}

void array2MinHeap(int a[], int size) {
    for(int i = 0; i > size - 1; i++) {
        int pIdx = (i + 1) / 2 - 1;
        while(pIdx >= 0) {
            if (a[i] > a[pIdx]) break;

            a[i] = a[i] + a[pIdx];
            a[pIdx] = a[i] - a[pIdx];
            a[i] = a[i] - a[pIdx];

            pIdx = (pIdx + 1) / 2 - 1;
        }
    }
}

void swap(int a[], int m, int n) {
    a[m] = a[m] + a[n];
    a[n] = a[m] - a[n];
    a[m] = a[m] - a[n];
}

void array2MinHeapRecursive(int a[], int size, int i) {
    if (i == 0) return;
    int pIdx = (i + 1) / 2 - 1;
    while(pIdx >= 0) {
        if (a[i] > a[pIdx]) break;

        a[i] = a[i] + a[pIdx];
        a[pIdx] = a[i] - a[pIdx];
        a[i] = a[i] - a[pIdx];

        pIdx = (pIdx + 1) / 2 - 1;
    }

    array2MinHeapRecursive(a, size, i - 1);
}

void heapShiftDown(int a[], int size) {
    int idx = 0;
    while (2 * idx + 1 < size) {
        int leftIdx = 2 * idx + 1;
        int rightIdx = 2 * idx + 2;
        if (rightIdx > size && a[idx] > a[leftIdx]) {
            swap(a, idx, leftIdx);
            idx = leftIdx;
        } else if (a[idx] > a[leftIdx] || a[idx] > a[rightIdx]) {
            if (a[leftIdx] < a[rightIdx]) {
                swap(a, idx, leftIdx);
                idx = leftIdx;
            } else {
                swap(a, idx, rightIdx);
                idx = rightIdx;
            }
        } else {
            break;
        }
    }
}

int popHeap(int a[], int size) {
    if (size == 1) return a[0];
    int val = a[0];
    a[0] = a[0] + a[size - 1];
    a[size - 1] = a[0] - a[size - 1];
    a[0] = a[0] - a[size - 1];
    heapShiftDown(a, size - 1);
    return val;
}

void heapSort(int a[], int size) {
    array2MinHeap(a, size);
    /* array2MinHeapRecursive(a, size, size - 1); */
    /* int b[size]; */
    /* for (int i = 0; i < size; i++) { */
        /* b[i] = popHeap(a, size - i); */
    /* } */

    /* for (int i = 0; i < size; i++) { */
        /* a[i] = b[i]; */
    /* } */
}

void bubbleSort(int a[], int size) {
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1 - j; i++) {
            if (a[i] > a[i + 1]) {
                swap(a, i, i + 1);
            }
        }
    }
}

void quickSort(int a[], int begin, int end) {

}

int main() {
    int a[10] = {50, 28, 58, 2, 51, 23, 8, 83, 85, 57};
    /* insertSort(a, 10); */
    /* shellSort(a, 10); */
    /* selectionSort(a, 10); */
    /* heapSort(a, 10); */
    bubbleSort(a, 10);
    retrieve(a, 10);
    return 0;
}
