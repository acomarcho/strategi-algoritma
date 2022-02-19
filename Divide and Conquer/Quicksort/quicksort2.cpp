#include <iostream>
#include <Windows.h>
using namespace std;

void printArray(int* array, int array_size) {
  cout << "[";
  for (int i = 0; i < array_size; i ++) {
    cout << array[i];
    if (i != array_size - 1) {
      cout << ",";
    }
  }
  cout << "]" << endl;
}

void partition(int* arr, int start, int end, int& pivot) {
  /* Pivot adalah elemen pertama */
  int pivotElmt = arr[start];
  /* Inisialisasi p dan q */
  int p = start + 1;
  int q = end;
  while (true) {
    /* Cari lokasi p yang benar */
    while (arr[p] < pivotElmt) {
      p ++;
    }
    /* Cari lokasi q yang benar */
    while (arr[q] > pivotElmt) {
      q --;
    }
    if (p >= q) {
      break;
    }
    /* Lakukan swap */
    int tmp = arr[p];
    arr[p] = arr[q];
    arr[q] = tmp;
    p ++;
    q --;
  }
  /* Swap arr[q] dengan arr[start] */
  arr[start] = arr[q];
  arr[q] = pivotElmt;
  pivot = q;
}

void quicksort(int* arr, int start, int end) {
  /* Cek apakah array tidak satu elemen saja */
  if (end > start) {
    int pivot;
    /* Lakukan partisi arr dari start sampai end, menghasilkan indeks pivot */
    partition(arr, start, end, pivot);
    /* Setelah dipartisi, quicksort start ... pivot - 1 dan pivot + 1 ... end */
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
  }
}

void sort(int* arr, int size) {
  quicksort(arr, 0, size - 1);
}

int main() {
  int arr_size = 9;
  int arr[] = {8, 1, 4, 6, -4, 9, 3, 5, 7};
  printArray(arr, arr_size);
  sort(arr, arr_size);
  printArray(arr, arr_size);
  return 0;
}