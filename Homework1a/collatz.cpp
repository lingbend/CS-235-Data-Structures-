#include <iostream>
using std::cout, std::endl;

int main(int argc, char *argv[]) {
    int starting_num = atof(argv[1]);
    int current_num = starting_num;
    cout << starting_num << endl;
    while (current_num != 1) {
        if (current_num % 2 == 0) {
            current_num /= 2;
            cout << current_num << endl;
        }
        else {
            current_num = (current_num * 3) + 1;
            cout << current_num << endl;
        }
    }
    return 0;
}