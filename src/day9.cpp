#include <fstream>
#include <stack>
#include <vector>

using namespace std;

const char in[]{"in/day9.in"};
const char out[]{"out/day9.out"};

#define MIN(x, y, z) (x < y ? (x < z ? x : z) : ((y < z) ? y : z));

bool is_valid(int x, int y) { return 0 <= x && x < 100 && 0 <= y && y < 100; }

int part1() {
  ifstream ifs(in);
  int heightmap[100][100]{};
  int i = 0;
  for (char digit; ifs >> digit; i++)
    heightmap[i / 100][i % 100] = digit - '0';
  ifs.close();
  int sum = 0;
  vector<int> directions[4]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (int x = 0; x < 100; x++) {
    for (int y = 0; y < 100; y++) {
      bool islow = true;
      for (vector<int> adj : directions) {
        int dx = adj[0], dy = adj[1];
        if (is_valid(x + dx, y + dy) &&
            heightmap[x][y] >= heightmap[x + dx][y + dy])
          islow = false;
      }
      if (islow)
        sum += 1 + heightmap[x][y];
    }
  }
  return sum;
}

int part2() {
  ifstream ifs(in);
  bool heightmap[100][100]{};
  int i = 0;
  for (char digit; ifs >> digit; i++)
    heightmap[i / 100][i % 100] = (digit - '0' == 9 ? false : true);
  ifs.close();
  int sum = 0;
  vector<int> basins{};
  vector<vector<int>> lowpoints{};
  vector<int> directions[4]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (int x = 0; x < 100; x++) {
    for (int y = 0; y < 100; y++) {
      int curr_basin = 0;
      stack<vector<int>> stack{};
      if (heightmap[x][y])
        stack.push({x, y});
      while (!stack.empty()) {
        vector<int> curr = stack.top();
        stack.pop();
        int x = curr[0], y = curr[1];
        if (heightmap[x][y]) {
          for (vector<int> adj : directions) {
            int dx = adj[0], dy = adj[1];
            if (is_valid(x + dx, y + dy) && heightmap[x + dx][y + dy])
              stack.push({x + dx, y + dy});
          }
          heightmap[x][y] = false;
          curr_basin++;
        }
      }
      if (curr_basin > 0)
        basins.push_back(curr_basin);
    }
  }
  int max[3]{};
  for (int basin : basins) {
    if (basin > max[0]) {
      max[2] = max[1];
      max[1] = max[0];
      max[0] = basin;
    } else if (basin > max[1]) {
      max[2] = max[1];
      max[1] = basin;
    } else if (basin > max[2])
      max[2] = basin;
  }
  return max[0] * max[1] * max[2];
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
