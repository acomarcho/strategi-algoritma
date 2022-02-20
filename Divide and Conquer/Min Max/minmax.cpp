#include <iostream>
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

void minMax(int* array, int start, int end, int& min, int& max) {
  /* Base cases */
  if (start == end) {
    /* Satu elemen saja */
    min = array[start]; max = array[start];
  } else if (end - start == 1) {
    /* Dua elemen saja */
    if (array[start] < array[end]) {
      min = array[start]; max = array[end];
    } else {
      min = array[end]; max = array[start];
    }
  } else {
    /* Divide menjadi dua subproblem */
    int mid = (start + end) / 2;
    /* Problem pertama dari start ... mid */
    int min1; int max1;
    minMax(array, start, mid, min1, max1);
    /* Problem kedua dari mid + 1 ... end */
    int min2; int max2;
    minMax(array, mid + 1, end, min2, max2);
    /* Bandingkan min1, max1, min2, max2 */
    if (min1 < min2) {
      min = min1;
    } else {
      min = min2;
    }
    if (max1 > max2) {
      max = max1;
    } else {
      max = max2;
    }
  }
}

int main() {
  int arr_size = 9;
  int arr[] = {8, 1, 4, 6, -4, 9, 3, 5, 7};
  printArray(arr, arr_size);

  int min; int max;
  minMax(arr, 0, arr_size - 1, min, max);

  cout << "Minimum value: " << min << endl;
  cout << "Maximum value: " << max << endl;
  return 0;
}