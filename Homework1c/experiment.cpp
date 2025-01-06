#include <string>
#include <iostream>
using std::cin, std::cout, std::string, std::stoi;

int main() {
    string var;
    cin >> var;
    int num(stoi(var));
    cout << num;
    return 0;
}