#include <fstream>
#include <iostream>

using namespace std;

const char in[] {"in/day1.in"};
const char out[] {"out/day1.out"};

int main() {
    ifstream ifs(in);

    int curr;
    int prev;
    
    int count {0};

    ifs >> prev;

    while (ifs) {
        ifs >> curr;
        if (prev < curr) {
            count++;
            cout << prev << " -> " << curr << "\n";
            cout << count << "\n\n";
        }
        prev = curr;
    }

    ofstream ofs(out);
    ofs << count;

    return 0;
}
