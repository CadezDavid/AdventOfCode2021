#include <fstream>

using namespace std;

const char in[]{"in/day20.in"};
const char out[]{"out/day20.out"};

const int X{100};
const int Y{100};

int part1() {
  ifstream ifs(in);
  const int iterations{2};
  int inc{0};
  int outside{0};
  int picture[Y + 2 * iterations][X + 2 * iterations]{};
  int enh_alg[512]{};
  char c;
  for (int i = 0; i < 512; i++) {
    ifs >> c;
    enh_alg[i] = (c == '#' ? 1 : 0);
  }

  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      ifs >> c;
      picture[y][x] = (c == '#' ? 1 : 0);
    }
  }
  for (int iter = 0; iter < iterations; iter++) {
    inc++;
    int tmp[Y + 2 * inc][X + 2 * inc];
    for (int y = 0; y < Y + 2 * inc; y++) {
      for (int x = 0; x < X + 2 * inc; x++) {
        int val = 0;
        for (int pos = 0; pos < 9; pos++)
          if (y + pos / 3 - 2 < 0 || Y + 2 * inc <= y + pos / 3 ||
              x + pos % 3 - 2 < 0 || X + 2 * inc <= x + pos % 3) {
            val += outside * (1 << (8 - pos));
          } else if (picture[y + pos / 3 - 2][x + pos % 3 - 2])
            val += (1 << (8 - pos));
        tmp[y][x] = enh_alg[val];
      }
    }
    outside = (outside == 0 ? enh_alg[0] : enh_alg[511]);

    for (int y = 0; y < Y + 2 * inc; y++)
      for (int x = 0; x < X + 2 * inc; x++)
        picture[y][x] = tmp[y][x];
  }

  int sum{0};
  for (int y = 0; y < Y + 2 * inc; y++)
    for (int x = 0; x < X + 2 * inc; x++)
      if (picture[y][x])
        sum++;
  return sum;
}

int part2() {
  ifstream ifs(in);
  const int iterations{50};
  int inc{0};
  int outside{0};
  int picture[Y + 2 * iterations][X + 2 * iterations]{};
  int enh_alg[512]{};
  char c;
  for (int i = 0; i < 512; i++) {
    ifs >> c;
    enh_alg[i] = (c == '#' ? 1 : 0);
  }

  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      ifs >> c;
      picture[y][x] = (c == '#' ? 1 : 0);
    }
  }
  for (int iter = 0; iter < iterations; iter++) {
    inc++;
    int tmp[Y + 2 * inc][X + 2 * inc];
    for (int y = 0; y < Y + 2 * inc; y++) {
      for (int x = 0; x < X + 2 * inc; x++) {
        int val = 0;
        for (int pos = 0; pos < 9; pos++)
          if (y + pos / 3 - 2 < 0 || Y + 2 * inc <= y + pos / 3 ||
              x + pos % 3 - 2 < 0 || X + 2 * inc <= x + pos % 3) {
            val += outside * (1 << (8 - pos));
          } else if (picture[y + pos / 3 - 2][x + pos % 3 - 2])
            val += (1 << (8 - pos));
        tmp[y][x] = enh_alg[val];
      }
    }
    outside = (outside == 0 ? enh_alg[0] : enh_alg[511]);

    for (int y = 0; y < Y + 2 * inc; y++)
      for (int x = 0; x < X + 2 * inc; x++)
        picture[y][x] = tmp[y][x];
  }

  int sum{0};
  for (int y = 0; y < Y + 2 * inc; y++)
    for (int x = 0; x < X + 2 * inc; x++)
      if (picture[y][x])
        sum++;
  return sum;
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
