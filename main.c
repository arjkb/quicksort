#include <stdio.h>

#define TOTAL_SIZE 10

void print_array(int array[], const int SIZE);
void quicksort(int array[], const int START, const int END);
int partition(int array[], const int START, const int END);
void swap(int array[], const int index1, const int index2);

int main() {
    int A[TOTAL_SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    print_array(A, TOTAL_SIZE);
    quicksort(A, 0, TOTAL_SIZE-1);
    print_array(A, TOTAL_SIZE);

    return 0;
}

/*** Function definitions ***/
void print_array(int array[], const int SIZE)  {
    int i;
    printf("\n");
    for(i=0; i < SIZE; i++)   {
        printf(" %d", array[i]);
    }
}

void quicksort(int array[], const int START, const int END)    {
    if (START < END)   {
        int pivot_index = partition(array, START, END);

        quicksort(array, START, pivot_index-1);
        quicksort(array, pivot_index+1, END-1);
    }
}

int partition(int array[], const int START, const int END)   {
    const int PIVOT_VALUE = array[END];
    int i=START-1;

    for(int j=START; j < END; j++) {
        if (array[j] <= PIVOT_VALUE)   {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i+1, END);
    return (i + 1);
}

void swap(int array[], const int index1, const int index2)   {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}