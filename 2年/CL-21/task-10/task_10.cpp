#include <iostream>
#include <iomanip>

struct Score {
    int p1;
    int p2;
    int p3;
    double avg;

    Score(int n1, int n2, int n3) : p1(n1), p2(n2), p3(n3) {
        avg = (n1 + n2 + n3) / 3.0;
    }
};

int main() {
    Score p[] = {
        Score(80, 100, 58),
        Score(55, 95, 55),
        Score(60, 78, 60),
        Score(74, 88, 90),
        Score(84, 90, 62)
    };

    std::cout << "+-----+-----+-----+-----+------+" << std::endl;
    std::cout << "| SNO | P1  | P2  | P3  | AVG  |" << std::endl;
    std::cout << "+-----+-----+-----+-----+------+" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "| " << std::setw(3) << i + 1 << " | " << std::setw(3) << p[i].p1 << " | " << std::setw(3) << p[i].p2 << " | " << std::setw(3) << p[i].p3 << " | " << std::fixed << std::setprecision(1) << p[i].avg << " |" << std::endl;
    }

    std::cout << "+-----+-----+-----+-----+------+" << std::endl;

    return 0;
}