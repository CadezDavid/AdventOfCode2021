#include <fstream>
#include <map>

using namespace std;

const char in[]{"in/day14_test.in"};
const char out[]{"out/day14.out"};

#define MIN(x, y) (x > y ? y : x)
#define MAX(x, y) (x < y ? y : x)

int part1() {
  ifstream ifs(in);
  string templ;
  ifs >> templ;
  string pair, _;
  char insert;
  map<string, char> rules{};
  map<char, long> alphabet{};
  while (ifs >> pair >> _ >> insert)
    rules[pair] = insert;
  for (char letter : templ)
    alphabet[letter] = 1;
  int steps = 10;
  while (steps-- > 0) {
    string new_templ;
    for (int i = 0; i < templ.size() - 1; i++) {
      char a = templ[i];
      char b = templ[i + 1];
      string c;
      c.push_back(a);
      c.push_back(b);
      alphabet[rules[c]]++;
      new_templ += templ[i];
      new_templ += rules[c];
    }
    new_templ += templ[templ.size() - 1];
    templ = new_templ;
  }
  long min = INT64_MAX;
  long max = 0;
  for (::pair<char, long> it : alphabet) {
    min = MIN(it.second, min);
    max = MAX(it.second, max);
  }
  return max - min;
}

long part2() {
  ifstream ifs(in);
  string polymer_template{};
  ifs >> polymer_template;
  string pair, _, prev{};
  char insert{};
  map<string, char> rules{};
  while (ifs >> pair >> _ >> insert)
    rules[pair] = insert;

  map<char, long> alphabet{};
  for (char letter : polymer_template)
    alphabet[letter] = 1;

  map<string, long> templ;
  for (int i = 0; i < polymer_template.size() - 1; i++) {
    string curr{};
    curr.push_back(polymer_template[i]);
    curr.push_back(polymer_template[i + 1]);
    templ[curr]++;
  }

  map<string, long> new_templ{};
  int steps = 40;
  while (steps-- > 0) {
    new_templ = {};
    for (::pair<string, long> it : templ) {
      char c = rules[it.first];
      string a{};
      a.push_back(it.first[0]);
      a.push_back(c);
      string b{};
      b.push_back(c);
      b.push_back(it.first[1]);
      alphabet[c] += it.second;
      new_templ[a] += it.second;
      new_templ[b] += it.second;
    }
    templ = new_templ;
  }
  long min = INT64_MAX;
  long max = 0;
  for (::pair<char, long> it : alphabet) {
    min = MIN(it.second, min);
    max = MAX(it.second, max);
  }
  return max - min;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
