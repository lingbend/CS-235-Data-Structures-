#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <iostream>
using std::string, std::vector, std::unordered_map, std::istream, std::ostream, std::getline, std::ifstream, std::stoi, std::cout;

unordered_map<string, vector<string>> train(istream& stream) {
    string first_word = "";
    string second_word;
    unordered_map<string, vector<string>> word_map;
    while (true) {
        if (stream >> second_word) {
            word_map[first_word].push_back(second_word);
            first_word = second_word;
        }
        else {
            break;
        }
    }
    return word_map;
}

void generate (unordered_map<string, vector<string>> model, int num_words, ostream& stream, string first_word="") {
    vector<string> current_bucket;
    string next_word;
    if (first_word != "") {
        stream << first_word;
        num_words--;
    }
    for (int i = 0; i < num_words; i++) {
        current_bucket = model[first_word];
        next_word = current_bucket.at(rand() % current_bucket.size());
        stream << next_word << " ";
        first_word = next_word;
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
    int num_words = stoi(argv[2]);
    unordered_map<string, vector<string>> net = train(infile);
    // print_map(net);
    generate(net, num_words, cout);
    infile.close();
    return 0;
}