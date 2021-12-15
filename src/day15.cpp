#include <fstream>
#include <queue>
#include <vector>

using namespace std;

const char in[]{"in/day15.in"};
const char out[]{"out/day15.out"};

const int X{100};
const int Y{100};
const vector<int> directions[]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
#define MIN(x, y) (x > y ? y : x)

bool is_valid(int x, int y) { return (0 <= x && x < X && 0 <= y && y < Y); }
bool is_valid_2(int x, int y) {
  return (0 <= x && x < 5 * X && 0 <= y && y < 5 * Y);
}

int part1() {
  ifstream ifs(in);
  int cave[X][Y];
  int total_risk[X][Y];
  bool visited[X][Y];
  char risk;
  for (int i = 0; ifs >> risk; i++) {
    cave[i % X][i / X] = risk - '0';
    total_risk[i % X][i / X] = INT16_MAX;
    visited[i % X][i / X] = false;
  }
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> queue;
  queue.push({0, 0, 0});
  total_risk[0][0] = 0;
  while (!queue.empty()) {
    vector<int> curr = queue.top();
    queue.pop();
    if (!visited[curr[1]][curr[2]]) {
      for (vector<int> move : directions) {
        int x = curr[1] + move[0];
        int y = curr[2] + move[1];
        if (is_valid(x, y)) {
          if (!visited[x][y])
            queue.push({cave[x][y] + curr[0], x, y});
          total_risk[x][y] = MIN(cave[x][y] + curr[0], total_risk[x][y]);
        }
      }
    }
    visited[curr[1]][curr[2]] = true;
  }
  return total_risk[X - 1][Y - 1];
}

int part2() {
  ifstream ifs(in);
  int cave[5 * X][5 * Y];
  int total_risk[5 * X][5 * Y];
  bool visited[5 * X][5 * Y];
  char risk;
  for (int i = 0; ifs >> risk; i++) {
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        cave[x * X + (i % X)][y * Y + (i / X)] =
            (x + y + (risk - '0')) % 10 + (x + y + (risk - '0')) / 10;
        total_risk[x * X + (i % X)][y * Y + (i / X)] = INT16_MAX;
        visited[x * X + (i % X)][y * Y + (i / X)] = false;
      }
    }
  }
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> queue;
  queue.push({0, 0, 0});
  total_risk[0][0] = 0;
  while (!queue.empty()) {
    vector<int> curr = queue.top();
    queue.pop();
    if (!visited[curr[1]][curr[2]]) {
      for (vector<int> move : directions) {
        int x = curr[1] + move[0];
        int y = curr[2] + move[1];
        if (is_valid_2(x, y)) {
          if (!visited[x][y])
            queue.push({cave[x][y] + curr[0], x, y});
          total_risk[x][y] = MIN(total_risk[x][y], cave[x][y] + curr[0]);
        }
      }
    }
    visited[curr[1]][curr[2]] = true;
  }
  return total_risk[5 * X - 1][5 * Y - 1];
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
