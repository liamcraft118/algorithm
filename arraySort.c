#include <stdio.h>
#include <stdlib.h>

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

void shellSort(int a[], int size) {

}

void retrieve(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[10] = {50, 28, 58, 2, 51, 23, 8, 83, 85, 57};
    insertSort(a, 10);
    retrieve(a, 10);
    return 0;
}
