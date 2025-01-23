#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::vector, std::endl, std::cout, std::string, std::cin, std::ifstream;

vector<string> get_input() {
    string input_string;
    vector<string> string_list;
    while (getline(cin, input_string)) {
        if (input_string == "") {
            break;
        }
        string_list.push_back(input_string);
    }
return string_list;
}

void sort(vector<string>& string_list) {
    for (int i = 1; i < string_list.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (string_list[j + 1] < string_list[j]) {
                string temp = string_list[j];
                string_list[j] = string_list[j + 1];
                string_list[j + 1] = temp;
            }
            else {
                break;
            }
        }
    }
}


int main(int argc, char const* argv[]) {
    vector<string> string_list;
    if (argc == 1) {
        string_list = get_input();
    }
    else {
        ifstream infile(argv[1]);
        string input_string;
        while (getline(infile, input_string)) {
            string_list.push_back(input_string);
        }
    } 
    sort(string_list);
    for (int i = 0; i < string_list.size(); i++) {
        cout << string_list[i] << endl;
    }
    return 0;
}
