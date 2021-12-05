#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char in[]{"in/day4.in"};
const char out[]{"out/day4.out"};

vector<int> eval_board(int board[], int nums[], int size) {
  for (int i = 0; i < size; i++) {
    bool win = false;
    for (int j = 0; j < 25; j++) {
      if (board[j] == nums[i]) {
        board[j] = -1;
        bool row = true;
        bool col = true;
        for (int k = 0; k < 5; k++) {
          board[5 * k + (j % 5)] == -1 || (row = false);
          board[(j / 5) * 5 + k] == -1 || (col = false);
        }
        if (row || col)
          win = true;
      }
    }
    vector<int> score{i, 0};
    if (win) {
      for (int j = 0; j < 25; j++) {
        (board[j] == -1) || (score[1] += board[j]);
      }
      score[1] *= nums[i];
      return score;
    }
  }
  return {1000, 1000};
}

vector<int> part() {
  ifstream ifs(in);

  int nums[100];
  string s;
  ifs >> s;
  int pos = 0;
  string token;
  int i = 0;
  while ((pos = s.find(",")) != string::npos) {
    nums[i] = stoi(s.substr(0, pos));
    i++;
    s.erase(0, pos + 1);
  }
  nums[i] = stoi(s);

  vector<int> best1{1000, 0};
  vector<int> best2{0, 0};
  while (ifs.good()) {
    int board[25];
    int i = 25;
    while (i-- > 0) {
      ifs >> board[i];
    }
    vector<int> curr;
    curr = eval_board(board, nums, 100);
    if (1 < curr[0] && curr[0] < best1[0]) {
      best1 = curr;
    }
    if (1 < curr[0] && curr[0] > best2[0]) {
      best2 = curr;
    }
  }

  return {best1[1], best2[1]};
}

int main() {
  ofstream ofs(out);
  vector<int> solution = part();
  int part1 = solution[0];
  int part2 = solution[1];
  ofs << "part 1: " << part1 << endl;
  ofs << "part 2: " << part2 << endl;

  return 0;
}
