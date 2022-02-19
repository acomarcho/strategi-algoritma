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

void merge(int* array, int start, int mid, int end) {
  /* Array pertama dimulai dari start...mid */
  /* Array kedua dimulai dari mid + 1...end */
  /* Buat array sementara yang bisa mencakup dari start sampai dengan end */
  int* copyArr = new int[end - start + 1];
  /* copyArr akan diisi menggunakan algoritma merge */
  int leftPtr = start; /* Penunjuk untuk array sebelah kiri */
  int rightPtr = mid + 1; /* Penunjuk array untuk sebelah kanan */
  int currIndex = 0; /* Index copyArr sekarang */
  /* Apabila keduanya masih ada, */
  while (leftPtr <= mid && rightPtr <= end) {
    if (array[leftPtr] <= array[rightPtr]) {
      copyArr[currIndex ++] = array[leftPtr ++];
    } else {
      copyArr[currIndex ++] = array[rightPtr ++];
    }
  }
  /* Apabila tinggal left array, */
  while (leftPtr <= mid) {
    copyArr[currIndex ++] = array[leftPtr ++];
  }
  /* Apabila tinggal right array, */
  while (rightPtr <= end) {
    copyArr[currIndex ++] = array[rightPtr ++];
  }
  /* Copy isi copyArr ke dalam array */
  for (int i = 0; i < currIndex; i ++) {
    array[start + i] = copyArr[i];
  }
  delete[] copyArr;
}

void mergesort(int* array, int start, int end) {
  /* Definisi sebuah array memiliki > 1 elemen adalah end > start */
  if (end > start) {
    /* Divide array menjadi 2 bagian */
    int mid = (start + end) / 2;
    /* Conquer dengan cara mergesort bagian kiri dan mergesort bagian kanan */
    mergesort(array, start, mid);
    mergesort(array, mid + 1, end);
    /* Gabung partisi start...mid dengan partisi mid + 1...end */
    merge(array, start, mid, end);
  }
}

void sort(int* array, int size) {
  mergesort(array, 0, size - 1);
}

int main() {
  int arr_size = 9;
  int arr[] = {8, 1, 4, 6, -4, 9, 3, 5, 7};
  printArray(arr, arr_size);
  sort(arr, arr_size);
  printArray(arr, arr_size);
  return 0;
}