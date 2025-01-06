#include <iostream>
#include <string>
#include <queue>
using std::string, std::priority_queue, std::cout, std::cin, std::getline;

void add(priority_queue<string>& p_queue) {
    string name;
    string priority;
    cout << "Name: ";
    getline(cin, name);
    cout << "Priority: ";
    getline(cin, priority);
    string data(priority + " - " + name);
    if (stoi(priority) < 10) {
        data = "0" + data;
    }
    p_queue.push(data);
}

void take(priority_queue<string>& p_queue) {
    if (!p_queue.empty()) {
        string front = p_queue.top();
        cout << p_queue.top() << std::endl;
        p_queue.pop();
    }
    else {
        cout << "There are no more people in line" << std::endl;
    }
}



int main(int argc, char const* argv[]) {
    priority_queue<string> p_queue;
    while (true) {
        string command;
        cout << "What do you want to do? ";
        getline(cin, command);
        if (command == "add") {
            add(p_queue);
        }
        else if (command == "take") {
            take(p_queue);
        }
        else if (command == "") {
            break;
        }
        else {
            cout << command << " isn't a valid operation" << std::endl;
        }
    }
    return 0;
}
