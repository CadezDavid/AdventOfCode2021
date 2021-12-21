#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const char in[]{"in/day19.in"};
const char out[]{"out/day19.out"};



int part1() {
  ifstream ifs(in);
  vector<vector<vector<int>>> beacons;
  string s;
  int x, y, z;
  for (int i = -1; ifs >> s;) {
    beacons.push_back({});
    if (s.find(',') == string::npos) {
      ifs >> s >> s >> s;
      i++;
    } else {
      x = stoi(s.substr(0, s.find(',')));
      s.erase(0, s.find(',') + 1);
      y = stoi(s.substr(0, s.find(',')));
      s.erase(0, s.find(',') + 1);
      z = stoi(s.substr(0, s.length()));
      beacons[i].push_back({x, y, z});
    }
  }

  return 1;
}

int part2() {
  ifstream ifs(in);
  return 2;
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
