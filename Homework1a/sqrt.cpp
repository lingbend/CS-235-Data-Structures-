#include <cstdlib>  // atof
#include <string>
#include <iostream>
using std::abs, std::string, std::cout, std::endl;  

const double EPSILON = 0.0001;

double square(double num) {
    return num * num;
}

string estimate_accuracy(double estimate, double initial_value) {
    if (square(estimate) < initial_value - EPSILON) {
        // cout << square(estimate) << " " << square(initial_value) - EPSILON;
        return "too low";
    }
    else if (square(estimate) > initial_value + EPSILON) {
        return "too high";
    }
    else {
        return "accurate";
    }
    
}


int main(int argc, char *argv[]) {
    double initial_value = atof(argv[1]);
    double upper_bound = atof(argv[1]);
    double lower_bound = 0.0;
    double estimate = 0.0;
    string accuracy = "";
    if (initial_value < 0) {
        cout << "Input must be greater than 0";
        return 1;
    }
    else {
        while (accuracy != "accurate") {
            estimate = (lower_bound + upper_bound) / 2;
            cout << estimate << " (" << square(estimate) << ")" << endl;
            accuracy = estimate_accuracy(estimate, initial_value);
            if (accuracy == "too low") {
                lower_bound = estimate;
            }
            else if (accuracy == "too high") {
                upper_bound = estimate;
            }
        }
        return 0;
    }
}