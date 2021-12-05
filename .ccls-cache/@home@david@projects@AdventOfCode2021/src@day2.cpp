#include <fstream>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

const char in[] {"in/day2.in"};
const char out[] {"out/day2.out"};

int part1() {
    ifstream ifs(in);
    vector<int> position{0, 0};

    string dir;
    int val;

    while (ifs >> dir) {
        ifs >> val;
        if (dir == "forward") {
            position[0] += val;
        }
        else if (dir == "up") {
            position[1] -= val;
        }
        else if (dir == "down") {
            position[1] += val;
        }
    }
    return position[0] * position[1];
}

int part2() {
    ifstream ifs(in);
    vector<int> position{0, 0};

    string dir;
    int val;
    int aim {0};

    while (ifs >> dir) {
        ifs >> val;
        if (dir == "forward") {
            position[0] += val;
            position[1] += val * aim;
        }
        else if (dir == "up") {
            aim -= val;
        }
        else if (dir == "down") {
            aim += val;
        }
    }
    return position[0] * position[1];
}

int main() {
    ifstream ifs(in);

    ofstream ofs(out);
    ofs << "part 1: " << part1() << endl;
    ofs << "part 2: " << part2() << endl;

    return 0;
}
