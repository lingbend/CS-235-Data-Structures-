#include <iostream>
using std::endl, std::cout;

int main(int argc, char *argv[]) {
    double start = atof(argv[1]);
    double end = atof(argv[2]);
    double divisor = atof(argv[3]);
    int count = static_cast<int>(start);
    if (end > start) {
        while (count <= static_cast<int>(end)) {
            if ((count / divisor) == static_cast<double>((count / static_cast<int>(divisor)))) {
                cout << count << endl;
            }
            count += 1;
        }
    }
    else if (start > end) {
        while (count >= static_cast<int>(end)) {
            if ((count / divisor) == static_cast<double>((count / static_cast<int>(divisor)))) {
                cout << count << endl;
            }
            count -= 1;
        }
    }
    else {
        exit(1);
    }
    return 0;
}