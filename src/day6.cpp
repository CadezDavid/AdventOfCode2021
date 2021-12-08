#include <fstream>

using namespace std;

const char in[]{"in/day6.in"};
const char out[]{"out/day6.out"};

int64_t breed(int days) {
  int64_t a[9]{};
  char _;
  int fish = 0;

  ifstream ifs(in);
  while (ifs >> fish) {
    a[(days - fish - 1) % 9]++;
    ifs >> _;
  }
  ifs.close();

  while (days-- > 0)
    a[(days + 2) % 9] += a[days % 9];

  int64_t sum = 0;
  for (int i = 0; i < 9; i++)
    sum += a[i];
  return sum;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << breed(80) << endl;
  ofs << "part 2: " << breed(256) << endl;
  ofs.close();

  return 0;
}
