#include <fstream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const char in[]{"in/day13.in"};
const char out[]{"out/day13.out"};

#define MAX(x, y) (x < y ? y : x)

int part1() {
  ifstream ifs(in);
  int x, y;
  char _;
  string point;
  set<vector<int>> paper;
  while (ifs >> point) {
    if (point == "fold")
      break;
    x = stoi(point.substr(0, point.find(',')));
    y = stoi(point.substr(point.find(',') + 1, point.size()));
    paper.insert({x, y});
  }
  string fold, __;
  ifs >> __ >> fold;
  int line = stoi(fold.substr(2, fold.size()));
  set<vector<int>> folded_paper;
  if (fold[0] == 'x')
    for (vector<int> p : paper)
      folded_paper.insert({p[0] - 2 * MAX(0, p[0] - line), p[1]});
  else
    for (vector<int> p : paper)
      folded_paper.insert({p[0], p[1] - 2 * MAX(0, p[1] - line)});
  return folded_paper.size();
}

string part2() {
  ifstream ifs(in);
  int x, y;
  string fold, __, point;
  set<vector<int>> paper;
  vector<vector<int>> folds;
  while (ifs >> point) {
    if (point == "fold") {
      ifs >> __ >> fold;
      int line = stoi(fold.substr(2, fold.size()));
      if (fold[0] == 'x') {
        folds.push_back({line, INT32_MAX});
      } else {
        folds.push_back({INT32_MAX, line});
      }
    } else {
      x = stoi(point.substr(0, point.find(',')));
      y = stoi(point.substr(point.find(',') + 1, point.size()));
      paper.insert({x, y});
    }
  }
  set<vector<int>> folded_paper;
  for (vector<int> p : paper) {
    for (vector<int> f : folds)
      p = {p[0] - 2 * MAX(0, p[0] - f[0]), p[1] - 2 * MAX(0, p[1] - f[1])};
    folded_paper.insert(p);
  }
  string code;
  for (int x = 0; x < 6; x++) {
    code += "\n";
    for (int y = 0; y < 40; y++)
      if (folded_paper.find({y, x}) != folded_paper.end())
        code += "##";
      else
        code += "  ";
  }
  return code;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2:" << part2() << endl;
  ofs.close();

  return 0;
}
