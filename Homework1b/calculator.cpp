#include <iostream>
#include <string>
using std::cin, std::cout, std::string, std::endl;

bool check_valid_operator(string operation) {
    if (operation == "add" | operation == "subtract" | operation == "multiply" | operation == "divide" | operation == "mod") {
        return true;
    }
    return false;
}

string get_operator() {
    while (true) {
        cout << "operation: ";
        string output;
        getline(cin,output);
        if (check_valid_operator(output)) {
            return output;
        }
        else if (output == "") {
            exit(0);
        }
        else {
            cout << output << " isn't a valid operation" << endl;
        }
    }
}

double get_operand(string position) {
    cout << position << " operand: ";
    double operand;
    string output;
    getline(cin, output);
    operand = stod(output);
    return operand;

}

double do_math(string operation, double left_num, double right_num) {
    if (operation == "add") {
        return left_num + right_num;
    }
    else if (operation == "subtract") {
        return left_num - right_num;
    }
    else if (operation == "multiply") {
        return left_num * right_num;
    }
    else if (operation == "divide") {
        return left_num / right_num;
    }
    else { //mod
        return static_cast<double>((static_cast<int>(left_num) % static_cast<int>(right_num)));
    }

}

int main(int argc, char *argv[]) {
    while (true) {
        string operation(get_operator());
        double num1(get_operand("left"));
        double num2(get_operand("right"));
        double answer = do_math(operation, num1, num2);
        cout << answer << endl;
    }
}