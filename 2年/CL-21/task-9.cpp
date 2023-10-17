#include <iostream>
#include <ctime>

bool checkPrime(int num) {
    for (int i = 3; i < num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    double st = static_cast<double>(clock()) / CLOCKS_PER_SEC;

    int MaxNum = 100000;
    std::cout << "2 ";
    for (int j = 3; j <= MaxNum; j += 2) {
        if (checkPrime(j)) {
            std::cout << j << " ";
        }
    }
    std::cout << std::endl;

    double en = static_cast<double>(clock()) / CLOCKS_PER_SEC;
    std::cout << "time : " << en - st << " [s]" << std::endl;

    return 0;
}
