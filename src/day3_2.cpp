#include <iostream>
#include <fstream>
#include <deque>
#include <climits>
#include <vector>

using namespace std;
const char in[]{"in/day3.in"};
const char out[]{"out/day3.out"};
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

long bintodec(long bin) {
  long dec = 0;
  int i = 0;
  while (bin) {
    if (bin % 10) {
      dec += (1 << i);
    }
    bin /= 10;
    i++;
  }
  return dec;
}

int part1() {
  ifstream ifs(in);
  vector<int> commons{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  string line;
  long num;
  while (ifs >> line) {
    num = bintodec(stol(line));
    for (int i = 0; i < 12; i++) {
      if (CHECK_BIT(num, i)) {
        commons[i] += 1;
      } else {
        commons[i] -= 1;
      }
    }
  }
  ifs.close();
  int result = 0;
  for (int i = 0; i < 12; i++) {
    if (commons[i] > 0) {
      result += (1 << i);
    }
  }
  return result * ((1 << 12) - 1 - result);
}


int part2() {
  ifstream ifs(in);
  string line;
  long num;
  while (ifs >> line) {
    num = bintodec(stol(line));
  }
  ifs.close();
  return 42;
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
