#include <fstream>
#include <bitset>
#include <bitset>
#include <iostream>

using namespace std;

const char in[]{"in/day16.in"};
const char out[]{"out/day16.out"};

#define MIN(x, y) (x > y ? y : x)

int part1() {
  ifstream ifs(in);
  int b;
  while (ifs >> b) {
    cout << b << " ";
  }
  return 1;
}

int part2() { return 1; }

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
