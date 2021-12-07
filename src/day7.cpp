#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const char in[]{"in/day7.in"};
const char out[]{"out/day7.out"};

#define MIN(x, y) (x > y ? y : x)

int part1() {
  ifstream ifs(in);
  char _;
  int crab;
  int crabs[1000];
  int i = 0;
  while (ifs >> crab) {
    crabs[i] = crab;
    ifs >> _;
    i++;
  }
  ifs.close();
  sort(crabs, crabs + 1000);
  int median = crabs[500];
  int fuel;
  for (int crab : crabs) {
    fuel += abs(median - crab);
  }
  return fuel;
}

int fuel2(int crabs[], int n) {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    int dist = abs(crabs[i] - n);
    sum += dist * (dist + 1) / 2;
  }
  return sum;
}

int part2() {
  ifstream ifs(in);
  char _;
  int crab;
  int crabs[1000];
  int i = 0;
  while (ifs >> crab) {
    crabs[i] = crab;
    ifs >> _;
    i++;
  }
  ifs.close();
  int mean = 0;
  for (int crab : crabs)
    mean += crab;
  mean /= 1000;
  int min = MIN(fuel2(crabs, mean - 1), fuel2(crabs, mean));
  min = MIN(min, fuel2(crabs, mean + 1));
  return min;
}
int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
