#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const char in[]{"in/day3.in"};
const char out[]{"out/day3.out"};

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

struct tree {
  int zero;
  int one;
  struct tree *right, *left;
};

struct tree *newTree() {
  tree *tmp = new tree;
  tmp->zero = tmp->one = 0;
  tmp->right = tmp->left = NULL;
  return tmp;
}

struct tree *add_to_tree(tree *t, long num) {
  if (t == NULL) {
    tree t{};
  }
  struct tree *tmp;
  if (num > 0) {
    tree *tmp = new tree;
    if (num % 2) {
      tmp->one = t->one + 1;
      tmp->zero = t->zero;
      tmp->left = t->left;
      tmp->right = add_to_tree(t->right, num / 2);
    } else {
      tmp->zero = t->zero + 1;
      tmp->one = t->one;
      tmp->right = t->right;
      tmp->left = add_to_tree(t->left, num / 2);
    }
  }
  return tmp;
}

long bintodec(long bin) {
  long dec = 0;
  int i = 0;
  while (bin) {
    if (bin % 10)
      dec += (1 << i);
    bin /= 10;
    i++;
  }
  return dec;
}

int part1() {
  ifstream ifs(in);
  vector<int> commons{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  string line;
  long num;
  while (ifs >> line) {
    num = bintodec(stol(line));
    for (int i = 0; i < 12; i++) {
      if (CHECK_BIT(num, i)) {
        commons[i] += 1;
      } else {
        commons[i] -= 1;
      }
    }
  }
  ifs.close();
  int result = 0;
  for (int i = 0; i < 12; i++) {
    if (commons[i] > 0) {
      result += (1 << i);
    }
  }
  return result * ((1 << 12) - 1 - result);
}

long get_oxy(tree *t, int mul) {
  if (mul < 0)
    return 0;
  else if (t->zero < t->one)
    return (1 << mul) + get_oxy(t->right, mul - 1);
  else
    return get_oxy(t->left, mul - 1);
}

long get_co2(tree *t, int mul) {
  if (mul < 0)
    return 0;
  else if (t->zero < t->one)
    return get_co2(t->left, mul - 1);
  else
    return (1 << mul) + get_co2(t->right, mul - 1);
}

int part2() {
  ifstream ifs(in);
  tree *t{};
  string line;
  long num;
  while (ifs >> line) {
    num = bintodec(stol(line));
    t = add_to_tree(t, num);
  }
  ifs.close();
  return get_oxy(t, 12) * get_co2(t, 12);
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
