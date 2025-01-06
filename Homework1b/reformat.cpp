#include <fstream>
#include <string>
#include <sstream>
using std::ifstream, std::string, std::istringstream, std::ofstream, std::endl;

int main(int argc, char *argv[]) {
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    string line;
    string f_name;
    string l_name;
    string score;
    string modifier;
    while (getline(infile, line)) {
        istringstream current_line(line);
        current_line >> f_name >> l_name >> score >> modifier;
        outfile << l_name << ", " << f_name << ": " << (stof(score) * stof(modifier)) << endl;
    }
    infile.close();
    outfile.close();
    return 0;
    //get first line
    //store data
    //multiply numbers
    //record line
    //repeat
}