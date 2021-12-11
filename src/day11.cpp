#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const char in[]{"in/day11.in"};
const char out[]{"out/day11.out"};

const int X{10};
const int Y{10};
const int DAYS{100};
int directions[8]{1, -1, 10, -10, 11, -11, 9, -9};

int x(int i, int di) {
  if (di == 9)
    return i % X - 1;
  else if (di == -9)
    return i % X + 1;
  return i % X + di % X;
}
int y(int i, int di) {
  if (di == 9)
    return i / Y + 1;
  else if (di == -9)
    return i / Y - 1;
  return i / Y + di / Y;
}
bool is_valid(int i, int di) {
  return (0 <= x(i, di) && x(i, di) < X && 0 <= y(i, di) && y(i, di) < Y);
}

int part1() {
  ifstream ifs(in);
  int cavern[X * Y];
  int flashes{0};
  char oct;
  for (int i = 0; ifs >> oct; i++) {
    cavern[i] = (int)oct - '0';
  }
  ifs.close();
  stack<int> stack{};
  int n = DAYS;
  while (n-- > 0) {
    for (int i = 0; i < X * Y; i++)
      cavern[i]++;
    for (int i = 0; i < X * Y; i++) {
      int curr{0};
      stack = {};
      if (cavern[i] > 9)
        stack.push(i);
      while (!stack.empty()) {
        int c = stack.top();
        stack.pop();
        if (cavern[c] > 9) {
          for (int di : directions)
            if (is_valid(c, di) && cavern[c + di])
              if (++cavern[c + di] > 9)
                stack.push(c + di);
          cavern[c] = 0;
          flashes++;
        }
      }
      if (curr == X * Y)
        return n;
    }
  }
  return flashes;
}

int part2() {
  ifstream ifs(in);
  int cavern[X * Y];
  char oct;
  for (int i = 0; ifs >> oct; i++) {
    cavern[i] = (int)oct - '0';
  }
  ifs.close();
  stack<int> stack{};
  int n = 0;
  while (++n) {
    for (int i = 0; i < X * Y; i++)
      cavern[i]++;
    for (int i = 0; i < X * Y; i++) {
      int curr{0};
      stack = {};
      if (cavern[i] > 9)
        stack.push(i);
      while (!stack.empty()) {
        int c = stack.top();
        stack.pop();
        if (cavern[c] > 9) {
          for (int di : directions)
            if (is_valid(c, di) && cavern[c + di])
              if (++cavern[c + di] > 9)
                stack.push(c + di);
          cavern[c] = 0;
          curr++;
        }
      }
      if (curr == X * Y)
        return n;
    }
  }
  return INT32_MAX;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
