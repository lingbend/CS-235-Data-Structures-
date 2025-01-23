#include "QS.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> array = {3, 7, -5, 10, 1};

    sort(array);

    for (const auto& item : array) {
        std::cout << item << " ";
    }

    return 0;
}