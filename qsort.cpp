#include <iostream>

void print_array(int *arr, int start, int end) {
    for (int i = start; i < end; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[end] << std::endl;
}

void sort_array(int *arr, int start, int end) {
    if (start >= end)
        return;
    if (end - start == 1) {
        if (arr[end] < arr[start]) {
            int aux = arr[start];
            arr[start] = arr[end];
            arr[end] = aux;
        }
        return;
    }

    int pivot = arr[(start + end)/2];

    int i = start;
    int j = end;

    while (i < j) {
        int aux;
        if (arr[i] >= pivot and i < j) {
            if (arr[j] <= pivot and i < j) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                j--;
                i++;
            } else
                j--;
        } else
            i++;
    }

    if (arr[i] <= pivot)
        i++;
    if (arr[j] >= pivot)
        j--;

    //std::cout << "(" << start << ", " << end << ") " << pivot << " = ";
    //print_array(arr, start, end);

    //std::cout << start << " " << j << " " << i << " " << end << std::endl;

    sort_array(arr, start, j);
    sort_array(arr, i, end);
}

int main() {
    int arr[50] = { 34, 40, 44, 27, 37, 9, 29, 6, 46, 1, 17, 13, 12, 48, 7, 45, 42, 32, 4, 28, 30, 41, 23, 18, 14, 31, 43, 3, 2, 25, 15, 22, 35, 26, 5, 8, 24, 39, 21, 20, 10, 38, 47, 33, 19, 16, 49, 11, 36 };
    //int arr[50] = { 16, 12, 12, 18, 7, 7, 7, 0, 0, 0, 0, 15, 3, 3, 3, 3, 9, 9, 9, 14, 14, 10, 10, 11, 11, 17, 6, 6, 6, 1, 1, 1, 1, 4, 4, 4, 4, 19, 5, 5, 5, 2, 2, 2, 2, 13, 13, 8, 8, 8 };

    print_array(arr, 0, 49);
    sort_array(arr, 0, 49);
    print_array(arr, 0, 49);

    return 0;
}
