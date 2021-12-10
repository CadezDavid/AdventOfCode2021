#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const char in[]{"in/day10.in"};
const char out[]{"out/day10.out"};

char op[]{'(', '[', '{', '<'};
char cl[]{')', ']', '}', '>'};

char opp(char c) {
  switch (c) {
  case '(':
    return ')';
  case '[':
    return ']';
  case '{':
    return '}';
  case '<':
    return '>';
  case ')':
    return '(';
  case ']':
    return '[';
  case '}':
    return '{';
  case '>':
    return '<';
  }
  return '0';
}
int value(char c) {
  switch (c) {
  case '(':
    return 1;
  case '[':
    return 2;
  case '{':
    return 3;
  case '<':
    return 4;
  }
  return 0;
}
int illegalness(char c) {
  switch (c) {
  case ')':
    return 3;
  case ']':
    return 57;
  case '}':
    return 1197;
  case '>':
    return 25137;
  }
  return 0;
}

int part1() {
  ifstream ifs(in);
  stack<int> stack{};
  int ses = 0;
  string line;
lines:
  while (ifs.good()) {
    stack = {};
    getline(ifs, line);
    for (char c : line) {
      if (find(begin(op), end(op), c) != end(op))
        stack.push(c);
      else if (stack.empty() || stack.top() != opp(c)) {
        ses += illegalness(c);
        goto lines;
      } else
        stack.pop();
    }
  }
  return ses;
}

long part2() {
  ifstream ifs(in);
  stack<int> stack{};
  vector<long> scores{};
  string line;
lines:
  while (ifs.good()) {
    stack = {};
    getline(ifs, line);
    for (char c : line) {
      if (find(begin(op), end(op), c) != end(op))
        stack.push(c);
      else if (stack.empty() || stack.top() != opp(c))
        goto lines;
      else
        stack.pop();
    }
    long curr = 0;
    while (!stack.empty()) {
      curr = 5 * curr + value(stack.top());
      stack.pop();
    }
    scores.push_back(curr);
  }

  long arr[scores.size()];
  for (int i = 0; i < scores.size(); i++)
    arr[i] = scores[i];
  sort(arr, arr + scores.size());
  return arr[scores.size() / 2];
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
