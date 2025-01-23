#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
using std::string, std::vector, std::unordered_map, std::istream, std::ostream, std::getline, std::ifstream, std::stoi, std::cout;

/* Added another word to the grouping. Used King James Bible to train. Allowed a custom word to be the first word*/

/*Input formatting: program name, kjv file name, number of words, first word (optional)*/

unordered_map<string, vector<string>> train(istream& stream, vector<string>& valid_sets, string starting_word) {
    string first_word = "";
    string second_word = "";
    string third_word;
    unordered_map<string, vector<string>> word_map;
    while (true) {
        if (stream >> third_word) {
            word_map[first_word + " " + second_word].push_back(third_word);
            if ((second_word == starting_word)) {
                valid_sets.push_back(first_word + " " + second_word);
            }
            first_word = second_word;
            second_word = third_word;
        }
        else {
            break;
        }
    }
    return word_map;
}

void generate (unordered_map<string, vector<string>> model, int num_words, ostream& stream,  vector<string> valid_sets, string second_word="") {
    vector<string> current_bucket;
    string next_word;
    string first_word = "";
    if (second_word != "") {
        stream << second_word << " ";
        num_words--;
    }
    if ((first_word == "") & (second_word != "")) {
    current_bucket = model[valid_sets.at(rand() % valid_sets.size())];
    }
    else {
        current_bucket = model[first_word + " " + second_word];
    }
    for (int i = 0; i < num_words; i++) {
        next_word = current_bucket.at(rand() % current_bucket.size());
        stream << next_word << " ";
        first_word = second_word;
        second_word = next_word;
        current_bucket = model[first_word + " " + second_word];
    }
}

void print_map(unordered_map<string, vector<string>> model) {
    for (auto model_vector : model) {
        cout << model_vector.first << " : ";
        for (auto entry : model_vector.second) {
            cout << entry << ", ";
        }
        cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    ifstream infile(argv[1]);
    vector<string> valid_starting_sets;
    int num_words = stoi(argv[2]);
    string starting_word = "";
    if (argv[3]) {
        starting_word = argv[3];
    }
    unordered_map<string, vector<string>> net = train(infile, valid_starting_sets, starting_word);
    generate(net, num_words, cout, valid_starting_sets, starting_word);
    infile.close();
    return 0;
}
