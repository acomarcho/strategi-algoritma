#include <iostream>
using namespace std;

int pow(int num, int power) {
  /* Ide: sebuah perpangkatan a^n bisa dibagi menjadi perkalian a^(n/2) * a^(n/2) (genap) atau a^(n/2) * a^(n/2) * a (ganjil) */
  if (power == 0) {
    return 1;
  } else if (power == 1) {
    return num;
  } else {
    /* Kalkulasi nilai dari a^(n/2) */
    int halfPow = pow(num, power / 2);
    if (power % 2 == 0) {
      /* Jika genap, */
      return halfPow * halfPow;
    } else {
      /* Ganjil */
      return halfPow * halfPow * num;
    }
  }
}

int main() {
  int x = pow(2, 8);
  cout << "Nilai dari 2^8 adalah " << x << endl;
  x = pow(3, 3);
  cout << "Nilai dari 3^3 adalah " << x << endl;
  return 0;
}