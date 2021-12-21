#include <fstream>
#include <map>
#include <vector>

using namespace std;

const int start1{7};
const int start2{3};
const char out[]{"out/day21.out"};

#define MAX(x, y) (x < y ? y : x)

vector<int> representations() {
  vector<int> r(10);
  for (int a = 1; a < 4; a++)
    for (int b = 1; b < 4; b++)
      for (int c = 1; c < 4; c++)
        r[a + b + c]++;
  return r;
}
vector<int> r = representations();

int part1() {
  int pos1 = start1;
  int pos2 = start2;
  int score1 = 0, score2 = 0, dice = 0, i = 0;
  while (score1 < 1000 && score2 < 1000) {
    if (i++ % 2 == 0) {
      for (int k = 0; k < 3; k++) {
        dice == 100 ? dice = 1 : dice++;
        pos1 += (dice % 10);
      }
      pos1 > 10 ? pos1 %= 10 : true;
      score1 += pos1;
    } else {
      for (int k = 0; k < 3; k++) {
        dice == 100 ? dice = 1 : dice++;
        pos2 += (dice % 10);
      }
      pos2 > 10 ? pos2 %= 10 : true;
      score2 += pos2;
    }
  }
  if (score1 < 1000)
    return score1 * 3 * i;
  else
    return score2 * 3 * i;
}

map<vector<int>, vector<long long>> memo = {};

vector<long long> dirac_dice(int pos1, int pos2, int score1, int score2) {
  if (score2 > 100)
    return {0, 1};
  vector<int> state = {pos1, pos2, score1, score2};
  if (memo.find(state) == memo.end()) {
    long long p1_wins = 0, p2_wins = 0;
    for (int t = 3; t < 10; t++) {
      int p = (pos1 + t) > 10 ? (pos1 + t) % 10 : pos1 + t;
      vector<long long> curr = dirac_dice(pos2, p, score2, score1 + p);
      p1_wins += r[t] * curr[1];
      p2_wins += r[t] * curr[0];
    }
    memo.insert({state, {p1_wins, p2_wins}});
  }
  return memo[state];
}

long long part2() {
  vector<long long> result = dirac_dice(start1, start2, 0, 0);
  return MAX(result[0], result[1]);
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
