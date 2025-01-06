#include <iostream>
#include <string>
using std::string;

void sort(std::string& a, std::string& b, std::string& c) {
    string temp;
    int change = 2;
    while (change > 0) {
        change = 0;
        if (b < a) {
            temp = a;
            a = b;
            b = temp;
            change += 1;
        }
        if (c < b) {
            temp = b;
            b = c;
            c = temp;
            change += 1;
        }
    }
}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
