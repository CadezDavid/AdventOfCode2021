#include <fstream>

using namespace std;

const char in[] {"in/day1.in"};
const char out[] {"out/day1.out"};


int part1() {
    ifstream ifs(in);
    int curr;
    int prev;
    int count {0};
    ifs >> prev;
    while (ifs >> curr) {
        if (prev < curr) {
            count++;
        }
        prev = curr;
    }
    return count;
}

int part2() {
    ifstream ifs(in);
    int window[3];
    int count {0};
    int curr;
    ifs >> window[0];
    ifs >> window[1];
    ifs >> window[2];
    while (ifs >> curr) {
        if (window[0] < curr) {
            count++;
        }
        window[0] = window[1];
        window[1] = window[2];
        window[2] = curr;
    }
    return count;
}

int main() {
    ifstream ifs(in);

    ofstream ofs(out);
    ofs << "part 1: " << part1() << endl;
    ofs << "part 2: " << part2() << endl;

    return 0;
}
