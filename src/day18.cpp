#include <fstream>
#include <vector>

using namespace std;

const char in[]{"in/day18.in"};
const char out[]{"out/day18.out"};

#define MAX(x, y) (x < y ? y : x)

struct Node {
  Node *parent;
  int val;
  Node *left, *right;
};

Node *new_node(int val, Node *parent) {
  Node *newNode = new Node();
  newNode->parent = parent;
  newNode->val = val;
  return newNode;
}
Node *new_node(Node *left, Node *right) {
  Node *newNode = new Node();
  newNode->val = -1;
  newNode->left = left;
  newNode->right = right;
  left->parent = newNode;
  right->parent = newNode;
  return newNode;
}
int split(Node *node) {
  if (node->val > 9) {
    node->left = new_node(node->val / 2, node);
    node->right = new_node(node->val / 2 + node->val % 2, node);
    node->val = -1;
    return 1;
  } else if (node->val == -1) {
    return split(node->left) || split(node->right);
  }
  return 0;
}
void add_left(Node *node, int val) {
  if (node->parent != nullptr) {
    if (node->parent->right == node) {
      Node *tmp = node->parent->left;
      while (tmp->val == -1)
        tmp = tmp->right;
      tmp->val += val;
    } else {
      add_left(node->parent, val);
    }
  }
}
void add_right(Node *node, int val) {
  if (node->parent != nullptr) {
    if (node->parent->left == node) {
      Node *tmp = node->parent->right;
      while (tmp->val == -1)
        tmp = tmp->left;
      tmp->val += val;
    } else
      add_right(node->parent, val);
  }
}
int explode(Node *node, int depth) {
  if (node->val != -1)
    return 0;
  else if (depth == 4 && node->val == -1) {
    add_left(node, node->left->val);
    add_right(node, node->right->val);
    node->val = 0;
    return 1;
  } else
    return explode(node->left, depth + 1) || explode(node->right, depth + 1);
}
Node *parse(string s) {
  if (s.size() == 1)
    return new_node(s[0] - '0', new Node());
  int i = 0;
  for (int depth = 0; i < s.length(); i++) {
    if (s[i] == '[')
      depth++;
    else if (s[i] == ']')
      depth--;
    if (s[i] == ',' && depth == 1)
      break;
  }
  Node *left = parse(s.substr(1, i - 1));
  Node *right = parse(s.substr(i + 1, s.size() - i - 2));
  Node *node = new_node(left, right);
  left->parent = node;
  right->parent = node;
  return node;
}

int magnitude(Node *node) {
  if (node->val == -1)
    return 3 * magnitude(node->left) + 2 * magnitude(node->right);
  return node->val;
}

int part1() {
  ifstream ifs(in);
  string s;
  getline(ifs, s);
  Node *node = parse(s);
  while (getline(ifs, s)) {
    if (s.length() == 0)
      break;
    node = new_node(node, parse(s));
    while (explode(node, 0) || split(node)) {
    }
  }
  return magnitude(node);
}

int part2() {
  ifstream ifs(in);
  string s;
  vector<string> snail{};
  while (getline(ifs, s))
    if (s.length())
      snail.push_back(s);
  Node *node;
  int max = 0;
  for (int i = 0; i < snail.size(); i++) {
    for (int j = 0; j < snail.size(); j++) {
      if (i != j) {
        Node *node1 = parse(snail[i]);
        Node *node2 = parse(snail[j]);
        node = new_node(node1, node2);
        while (explode(node, 0) || split(node)) {
        }
        max = MAX(max, magnitude(node));
      }
    }
  }
  return max;
}

int main() {
  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
