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
    a[fish]++;
    ifs >> _;
  }
  ifs.close();

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
  ofs << "part 1: " << breed(80) << endl;
  ofs << "part 2: " << breed(256) << endl;
  ofs.close();

  return 0;
}
