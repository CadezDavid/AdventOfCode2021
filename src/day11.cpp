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
vector<vector<int>> directions{{1, 0},  {0, 1},  {-1, 0}, {0, -1},
                               {1, -1}, {-1, 1}, {1, 1},  {-1, -1}};

bool is_valid(int x, int y) { return (0 <= y && x < X && 0 <= y && y < Y); }


int part1() {
  ifstream ifs(in);
  int cavern[X][Y];
  int flashes{0};
  char oct;
  for (int i = 0; ifs >> oct; i++) {
    cavern[i % X][i / X] = (int)oct - '0';
  }
  ifs.close();
  stack<vector<int>> stack{};
  int n = DAYS;
  while (n-- > 0) {
    for (int i = 0; i < X * Y; i++)
      cavern[i % X][i / X]++;
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        int curr{0};
        stack = {};
        if (cavern[x][y] > 9)
          stack.push({x, y});
        while (!stack.empty()) {
          vector<int> c = stack.top();
          stack.pop();
          for (vector<int> d : directions)
            if (is_valid(c[0] + d[0], c[1] + d[1]))
              if (++cavern[c[0] + d[0]][c[1] + d[1]] > 9)
                stack.push({c[0] + d[0], c[1] + d[1]});
          cavern[c[0]][c[1]] = 0;
          flashes++;
        }
      }
    }
  }
  return flashes;
}

int part2() {
  ifstream ifs(in);
  int cavern[X][Y];
  int flashes{0};
  char oct;
  for (int i = 0; ifs >> oct; i++) {
    cavern[i % X][i / X] = (int)oct - '0';
  }
  ifs.close();
  stack<vector<int>> stack{};
  int n = DAYS;
  while (n-- > 0) {
    for (int i = 0; i < X * Y; i++)
      cavern[i % X][i / X]++;
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        int curr{0};
        stack = {};
        if (cavern[x][y] > 9)
          stack.push({x, y});
        while (!stack.empty()) {
          vector<int> c = stack.top();
          stack.pop();
          for (vector<int> d : directions)
            if (is_valid(c[0] + d[0], c[1] + d[1]))
              if (++cavern[c[0] + d[0]][c[1] + d[1]] > 9)
                stack.push({c[0] + d[0], c[1] + d[1]});
          cavern[c[0]][c[1]] = 0;
          flashes++;
        }
        if (curr == X * Y)
          return n;
      }
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
