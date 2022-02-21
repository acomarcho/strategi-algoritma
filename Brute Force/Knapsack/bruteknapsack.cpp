#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Item {
  public:
    Item() {
      this->weight = 0;
      this->profit = 0;
    }
    Item(int weight, int profit) {
      this->weight = weight;
      this->profit = profit;
    }
    int w() {
      return this->weight;
    }
    int p() {
      return this->profit;
    }
  private:
    int weight;
    int profit;
};

string intToBinaryString(int num, int digits) {
  /* Mengembalikan string biner dari suatu angka, dengan banyak bit = digits. */
  /* Contoh: 5 dengan digits 4 menjadi 0101 */
  string tmp = "";
  int len = 0;
  while (num != 0) {
    if (num % 2 == 0) {
      tmp += "0";
    } else {
      tmp += "1";
    }
    num /= 2;
    len ++;
  }
  string ret = "";
  /* Letakkan 0 sebanyak digits - len */
  for (int i = 0; i < digits - len; i ++) {
    ret += "0";
  }
  for (int i = len - 1; i >= 0; i --) {
    ret += tmp[i];
  }
  return ret;
}

int knapsack(Item* bag, int bag_size, int bag_capacity) {
  int maxProfit = 0;
  /* Algoritma knapsack */
  for (int i = 0; i < pow(2, bag_size); i ++) {
    /* Panjang bit yang perlu dibuat adalah sepanjang bag_size */
    string setCondition = intToBinaryString(i, bag_size);
    /* Contoh: 0000 artinya semua item tidak ditambahkan ke bag */
    /* 0100 artinya item kedua dimasukkan ke bag */
    /* ... dan seterusnya */
    int currCap = 0; int currProfit = 0;
    for (int j = 0; j < bag_size; j ++) {
      if (setCondition[j] == '1') {
        currProfit += bag[j].p();
        currCap += bag[j].w();
      }
    }
    /* Update harga */
    if (currCap <= bag_capacity) {
      if (currProfit > maxProfit) {
        maxProfit = currProfit;
      }
    }
  }
  return maxProfit;
}

int main() {
  int bag_size = 4;
  int bag_capacity = 16; /* Ubah sesuai keinginan */
  Item* bag = new Item[bag_size];
  bag[0] = Item(2, 20);
  bag[1] = Item(5, 30);
  bag[2] = Item(10, 50);
  bag[3] = Item(5, 10);

  cout << "Profit maksimum sebesar " << knapsack(bag, bag_size, bag_capacity) << endl;
  return 0;
}