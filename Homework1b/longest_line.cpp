#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using std::string, std::ifstream, std::ofstream, std::getline, std::istringstream, std::cout, std::endl;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    int temp_count = 0;
    int high_count = 0;
    string temp_string = "";
    string high_string = "";
    string current_line;
    while (getline(infile, current_line)) {
        istringstream stream_line(current_line);
        while (stream_line >> temp_string) {
            temp_count += 1;
        }
        if (temp_count > high_count) {
            high_count = temp_count;
            high_string = current_line;
        }
        temp_count = 0;
        temp_string = "";
    }
    cout << high_string << endl;
    infile.close();
    return 0;
}
