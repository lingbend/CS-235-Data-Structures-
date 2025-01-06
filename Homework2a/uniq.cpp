#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_set>

using std::cin, std::cout, std::string, std::ifstream, std::istream, std::list, std::getline, std::unordered_set, std::endl;

list<string> get_input(string file_name = "") {
    string line;
    unordered_set<string> dict;
    list<string> lines;
    if (file_name != "") {
        ifstream infile(file_name);
        while (getline(infile, line)) {
            if (dict.find(line) == dict.end()) {
                lines.push_back(line);
                dict.insert(line);
            }
            

        }
        infile.close();
    }
    else {
        while (getline(cin, line)) {
            if (dict.find(line) == dict.end()) {
                if (line == "") {
                    break;
                }
                lines.push_back(line);
                dict.insert(line);
            }
            
        }
    }
    return lines;
}

void print_lines(list<string> lines) {
    for (string line : lines) {
        cout << line << endl;
    }
}

int main(int argc, char const* argv[]) {
    list<string> lines;
    if (argc > 1) {
        string file_name = argv[1];
        lines = get_input(file_name);
    }
    else {
        lines = get_input();
    }
    print_lines(lines);



    return 0;
}
