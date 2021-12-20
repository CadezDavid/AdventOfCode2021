#include <fstream>
#include <iostream>

using namespace std;

const int xl{128};
const int xu{160};
const int yl{-142};
const int yu{-88};
const char out[]{"out/day17.out"};

#define MAX(x, y) (x < y ? y : x)

int max_height(int y) {
  if (y < 0) {
    return 0;
  }
  return y + max_height(y - 1);
}

int part1() {
  int max = 0;
  for (int y = 0; y < 500; y++) {
    for (int x = 0; x < xu; x++) {
      int i = 0;
      int curr[]{0, 0};
      while (curr[0] <= xu && yl <= curr[1]) {
        if (xl <= curr[0] && curr[1] <= yu) {
          max = MAX(max, max_height(y));
          break;
        }
        curr[0] += MAX(0, x - i);
        curr[1] += y - i;
        i++;
      }
    }
  }
  return max;
}

int part2() {
  int count = 0;
  for (int y = yl; y < -yl; y++) {
    for (int x = 0; x <= xu; x++) {
      int i = 0;
      int curr[]{0, 0};
      while (curr[0] <= xu && yl <= curr[1]) {
        if (xl <= curr[0] && curr[1] <= yu) {
          count++;
          break;
        }
        curr[0] += MAX(0, x - i);
        curr[1] += y - i;
        i++;
      }
    }
  }
  return count;
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
