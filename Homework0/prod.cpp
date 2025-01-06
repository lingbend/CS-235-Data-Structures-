#include <iostream>
#include <cstdlib>
#include <string>

using std::cout, std::string;

bool check_for_floats(string num_input) { //checks if a string is a float
    if (num_input.find('.')) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc == 3) { //checks for 3 arguments
        string num1 = argv[1]; //converts arguments to strings
        string num2 = argv[2];
        if (check_for_floats(num1) || check_for_floats(num2)) { //if float, change strings to doubles
            double num1 = atof(argv[1]);
            double num2 = atof(argv[2]);
            double product = num1 * num2; //store product
            cout << num1 << " * " << num2 << " = " << product; //print product
        }
        else { //if int change strings to integers
            int num1 = atoi(argv[1]);
            int num2 = atoi(argv[2]);
            int product = num1 * num2; //store product
            cout << num1 << " * " << num2 << " = " << product; //print equation
        }
    }
    else {
        cout << "prod requires 2 arguments"; //error message if wrong number of arguments
        return 1;
    }
    return 0;
}