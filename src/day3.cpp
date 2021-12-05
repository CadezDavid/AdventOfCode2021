#include <fstream>
#include <vector>

using namespace std;

const char in[]{"in/day3.in"};
const char out[]{"out/day3.out"};

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

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

struct Node {
  int zero, one;
  Node *left, *right;
};

Node *new_node() {
  Node *newNode = new Node();
  newNode->one = newNode->zero = 0;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *add(Node *root, int num, int bit) {
  if (bit < 0)
    return root;
  if (root == NULL)
    root = new_node();
  if (CHECK_BIT(num, bit)) {
    root->one++;
    root->right = add(root->right, num, bit - 1);
  } else {
    root->zero++;
    root->left = add(root->left, num, bit - 1);
  }
  return root;
}

long get_oxy(Node *root, int bit) {
  if (bit < 0)
    return 0;
  if (root->one < root->zero && 0 < root->one)
    return get_oxy(root->left, bit - 1);
  return (1 << bit) + get_oxy(root->right, bit - 1);
}

long get_co2(Node *root, int bit) {
  if (bit < 0)
    return 0;
  if (root->one < root->zero && 0 < root->one)
    return (1 << bit) + get_co2(root->right, bit - 1);
  return get_co2(root->left, bit - 1);
}

int part2() {
  ifstream ifs(in);
  Node *root = NULL;
  string line;
  long num;
  while (ifs >> line) {
    num = bintodec(stol(line));
    root = add(root, num, 11);
  }
  ifs.close();
  return get_oxy(root, 11) * get_co2(root, 11);
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
