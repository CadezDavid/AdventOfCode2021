#include <fstream>

using namespace std;

const char in[]{"in/day5_test.in"};
const char out[]{"out/day5.out"};

#define MIN(x, y) ((x < y) ? x : y)
#define MAX(x, y) ((x < y) ? y : x)
#define COMP(x, y) ((x < y) ? 1 : ((x == y) ? 0 : -1))

int part1() {
  ifstream ifs(in);

  int ocean_floor[1000][1000]{};
  int x1, y1, x2, y2;
  char _;
  int doubled = 0;
  while (ifs >> x1 >> _ >> y1 >> _ >> _ >> x2 >> _ >> y2) {
    if (x1 == x2) {
      for (int i = MIN(y1, y2); i <= MAX(y1, y2); i++) {
        if (ocean_floor[x1][i] == 1)
          doubled++;
        ocean_floor[x1][i]++;
      }
    } else if (y1 == y2) {
      for (int i = MIN(x1, x2); i <= MAX(x1, x2); i++) {
        if (ocean_floor[i][y1] == 1)
          doubled++;
        ocean_floor[i][y1]++;
      }
    }
  }

  return doubled;
}

int part2() {
  ifstream ifs(in);
  int ocean_floor[1000][1000]{};
  int x1, y1, x2, y2;
  char _;
  int doubled = 0;
  while (ifs >> x1 >> _ >> y1 >> _ >> _ >> x2 >> _ >> y2) {
    int dx = COMP(x1, x2), dy = COMP(y1, y2);
    for (int i = 0; i <= MAX(abs(x1 - x2), abs(y1 - y2)); i++) {
      if (ocean_floor[x1 + dx * i][y1 + dy * i] == 1) {
        doubled++;
      }
      ocean_floor[x1 + dx * i][y1 + dy * i]++;
    }
  }
  return doubled;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;

  return 0;
}
