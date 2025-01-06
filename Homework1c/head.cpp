#include <iostream>
#include <string>
#include <fstream>
using std::string, std::cin, std::cout, std::ifstream, std::getline, std::endl, std::stoi;

bool is_numeric(char const* text) {
    string converted_text = text;
    for (int i = 0; i < converted_text.size(); i++) {
        if (converted_text[i] != '-' && converted_text[i] != '.' && !isdigit(converted_text[i])) {
            return false;
        }
    }
    return true;
}

void parse_input(int argc, char const* argv[], int& num_lines, std::string& file_name) {
    if (argc == 1) {
        num_lines = 10;
        file_name = "";
    }
    else if (argc == 2 && is_numeric(argv[1])) {
        string temp = argv[1];
        num_lines = stoi(temp.substr(1));
        file_name = "";
    }
    else if (argc == 2) {
        num_lines = 10;
        file_name = argv[1];
    }
    else if (argc == 3 && is_numeric(argv[1])) {
        string temp = argv[1];
        num_lines = stoi(temp.substr(1));
        file_name = argv[2];
    }
    else if (argc == 3) {
        string temp = argv[2];
        num_lines = stoi(temp.substr(1));
        file_name = argv[1];
    }
}


int main(int argc, char const* argv[]) {
    int num_lines;
    string input_text;
    std::string file_name;
    string print_line;
    parse_input(argc, argv, num_lines, file_name);
    if (file_name == "") {
        for (int i = 0; i != num_lines; i++) {
            cin >> input_text;
            cout << input_text << endl;
        }
    }
    else {
        ifstream infile(file_name);
        if (infile) {
            for (int i = 0; i != num_lines && getline(infile, print_line); i++) {
                cout << print_line << endl;
            }
        }
        else {
            cout << 6;
            cout << "ERROR: can't open " << file_name;
            exit(1);
        }
        infile.close();
    }
    return 0;
}
