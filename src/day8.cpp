#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

const char in[]{"in/day8.in"};
const char out[]{"out/day8.out"};

string characters = "abcdefg";
unordered_map<int, set<char>> numbers = {
    {0, {'a', 'b', 'c', 'e', 'f', 'g'}},
    {1, {'c', 'f'}},
    {2, {'a', 'c', 'd', 'e', 'g'}},
    {3, {'a', 'c', 'd', 'f', 'g'}},
    {4, {'b', 'c', 'f', 'd'}},
    {5, {'a', 'b', 'd', 'f', 'g'}},
    {6, {'a', 'b', 'd', 'e', 'f', 'g'}},
    {7, {'a', 'c', 'f'}},
    {8, {'a', 'b', 'c', 'd', 'e', 'f', 'g'}},
    {9, {'a', 'b', 'c', 'd', 'f', 'g'}}};

int part1() {
  ifstream ifs(in);
  int count = 0;
  for (string digit; ifs >> digit;) {
    if (digit == "|") {
      int i = 4;
      while (i-- > 0) {
        ifs >> digit;
        (digit.length() == 2) && count++;
        (digit.length() == 3) && count++;
        (digit.length() == 4) && count++;
        (digit.length() == 7) && count++;
      }
    }
  }
  ifs.close();
  return count;
}

int count(string arr[], char c) {
  int count = 0;
  for (int i = 0; i < 10; i++)
    (arr[i].find(c) == string::npos) || count++;
  return count;
}

int get_num(unordered_map<char, char> dict, string str) {
  cout << str << endl;
  set<char> s{};
  for (char a : str) {
    s.insert(dict[a]);
  }
  for (int i = 0; i < 10; i++) {
    if (s == numbers[i]) {
      return i;
    }
  }
  return 0;
}

unordered_map<char, char> decode(string nums[]) {
  unordered_map<char, char> dict{};
  int n1, n4, n7, n8;
  for (int i = 0; i < 10; i++) {
    nums[i].size() == 2 && (n1 = i);
    nums[i].size() == 3 && (n7 = i);
    nums[i].size() == 4 && (n4 = i);
    nums[i].size() == 7 && (n8 = i);
  }
  for (char c : characters) {
    if (nums[n7].find(c) != string::npos) {
      if (nums[n1].find(c) == string::npos)
        dict[c] = 'a';
      else if (count(nums, c) == 8)
        dict[c] = 'c';
      else if (count(nums, c) == 9)
        dict[c] = 'f';
    }
    if (nums[n4].find(c) != string::npos) {
      if (nums[n7].find(c) == string::npos) {
        if (count(nums, c) == 6)
          dict[c] = 'b';
        else if (count(nums, c) == 7)
          dict[c] = 'd';
      }
    }
    if (nums[n8].find(c) != string::npos) {
      if (nums[n4].find(c) == string::npos &&
          nums[n7].find(c) == string::npos) {
        if (count(nums, c) == 4)
          dict[c] = 'e';
        else if (count(nums, c) == 7)
          dict[c] = 'g';
      }
    }
  }
  return dict;
}

int part2() {
  ifstream ifs(in);
  int sum = 0;
  string nums[10]{};
  string digit{};
  for (int i = 0; ifs >> digit;) {
    if (digit == "|") {
      unordered_map<char, char> dict = decode(nums);
      int j = 4;
      while (j-- > 0) {
        ifs >> digit;
        sum += get_num(dict, digit) * pow(10, j);
      }
      i = 0;
    } else {
      cout << digit << endl;
      nums[i] = digit;
      i++;
    }
  }
  ifs.close();
  return sum;
}

int main() {

  ofstream ofs(out);
  ofs << "part 1: " << part1() << endl;
  ofs << "part 2: " << part2() << endl;
  ofs.close();

  return 0;
}
