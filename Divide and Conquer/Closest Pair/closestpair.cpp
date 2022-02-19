#include <iostream>
#include <cmath>
using namespace std;

class Point {
  /* Kelas Point */
  public:
    Point() {
      this->_x = 0;
      this->_y = 0;
    }
    Point(int x, int y) {
      this->_x = x;
      this->_y = y;
    }
    int x() const {
      return this->_x;
    }

    int y() const {
      return this->_y;
    }
  private:
    int _x;
    int _y;
};

double dist(Point p1, Point p2) {
  /* Euclidean distance */
  int xDiff = p1.x() - p2.x();
  int yDiff = p1.y() - p2.y();
  return sqrt(xDiff*xDiff + yDiff*yDiff);
}

double getClosestPair(Point* arr, int len) {
  if (len == 1) {
    /* Set ke suatu value yang sangat besar */
    return 9999999999;
  }
  if (len == 2) {
    return dist(arr[0], arr[1]);
  } else {
    /* Partisi menjadi dua bagian */
    int midPoint = len / 2;
    Point* leftPoints = new Point[midPoint];
    Point* rightPoints = new Point[len - midPoint];
    /* Isi leftPoints dan rightPoints */
    for (int i = 0; i < midPoint; i ++) {
      leftPoints[i] = arr[i];
    }
    for (int i = 0; i < len - midPoint; i ++) {
      rightPoints[i] = arr[i + midPoint];
    }
    /* Panggil secara rekursif ke leftPoints dan rightPoints */
    double leftDist = getClosestPair(leftPoints, midPoint);
    double rightDist = getClosestPair(rightPoints, len - midPoint);
    /* Clean-up karena memakai pointer */
    delete[] leftPoints;
    delete[] rightPoints;
    double d = min(leftDist, rightDist);
    /* Mengecek section tiga, yaitu section dengan titik-titik berabsis arr[midPoint].x() +- dist */
    /* Cari titik mulainya. */
    int start = 0;
    while (arr[start].x() < arr[midPoint].x() - d) {
      start ++;
    }
    /* Cari titik akhirnya. */
    int end = start;
    while (arr[end].x() <= arr[midPoint].x() + d && end < len) {
      end ++;
    }
    /* end kelebihan satu (sekarang >), kurangi. */
    end --;
    /* Cek semua kombinasi titik dari start sampai end */
    for (int i = start; i < end; i ++) {
      for (int j = i + 1; j <= end; j ++) {
        double distCheck = dist(arr[i], arr[j]);
        d = min(d, distCheck);
      }
    }
    /* Menggunakan min dari cmath */
    return d;
  }
}

int main() {
  /* Inisialisasi list of points, sudah terurut berdasarkan absis */
  Point p1(2, 3);
  Point p2(3, 4);
  Point p3(5, 1);
  Point p4(12, 10);
  Point p5(12, 30);
  Point p6(40, 50);
  int len = 6;
  Point arr[] = {p1, p2, p3, p4, p5, p6};
  /* Cari closest pair distance */
  double dist = getClosestPair(arr, len);
  cout << "Closest pair distance is: " << dist << endl;
  return 0;
}