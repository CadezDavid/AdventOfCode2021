#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

const char in[]{"in/day12.in"};
const char out[]{"out/day12.out"};

bool is_big(string s) { return isupper(s[0]); }

int count_paths(map<string, set<string>> graph, string current,
                set<string> visited) {
  if (current == "end")
    return 1;
  int sum = 0;
  for (string next : graph[current])
    if (visited.find(next) == visited.end()) {
      if (is_big(current)) {
        sum += count_paths(graph, next, visited);
      } else {
        visited.insert(current);
        sum += count_paths(graph, next, visited);
      }
    }
  return sum;
}

int count_paths_2(map<string, set<string>> graph, string current,
                  set<string> visited, bool bonus) {
  if (current == "end")
    return 1;
  int sum = 0;
  for (string next : graph[current])
    if (next != "start" && visited.find(next) == visited.end()) {
      if (is_big(current)) {
        sum += count_paths_2(graph, next, visited, bonus);
      } else {
        visited.insert(current);
        sum += count_paths_2(graph, next, visited, bonus);
      }
    } else if (next != "start" && bonus) {
      sum += count_paths_2(graph, next, visited, false);
    }
  return sum;
}

int part1() {
  ifstream ifs(in);
  map<string, set<string>> graph;
  string s, e, c;
  while (ifs >> c) {
    s = c.substr(0, c.find('-'));
    e = c.substr(c.find('-') + 1, c.length());
    graph[s].insert(e);
    graph[e].insert(s);
  }
  return count_paths(graph, "start", {});
}

int part2() {
  ifstream ifs(in);
  map<string, set<string>> graph;
  string s, e, c;
  while (ifs >> c) {
    s = c.substr(0, c.find('-'));
    e = c.substr(c.find('-') + 1, c.length());
    graph[s].insert(e);
    graph[e].insert(s);
  }
  return count_paths_2(graph, "start", {}, true);
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
