#include <fstream>
#include <iostream>

using namespace std;

const char in[]{"in/day6.in"};
const char out[]{"out/day6.out"};

#define MIN(x, y) ((x < y) ? x : y)
#define MAX(x, y) ((x < y) ? y : x)
#define COMP(x, y) ((x < y) ? 1 : ((x == y) ? 0 : -1))

int part1() {
  ifstream ifs(in);

  int a[9]{};
  char _;
  int fish = 0;
  while (ifs >> fish) {
    a[fish]++;
    ifs >> _;
  }

  int days = 80;
  while (days-- > 0) {
    int tmp = a[0];
    for (int i = 0; i < 8; i++)
      a[i] = a[i + 1];
    a[6] += tmp;
    a[8] = tmp;
  }

  int sum;
  for (int i = 0; i < 9; i++)
    sum += a[i];
  return sum;
}

int64_t part2() {
  ifstream ifs(in);

  int64_t a[9]{};
  char _;
  int fish = 0;
  while (ifs >> fish) {
    a[fish]++;
    ifs >> _;
  }

  int days = 256;
  while (days-- > 0) {
    int64_t tmp = a[0];
    for (int i = 0; i < 8; i++)
      a[i] = a[i + 1];
    a[6] += tmp;
    a[8] = tmp;
  }

  int64_t sum;
  for (int i = 0; i < 9; i++)
    sum += a[i];
  return sum;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;

  return 0;
}
