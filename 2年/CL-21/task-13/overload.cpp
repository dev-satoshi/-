#include <iostream>
using namespace std;

class Overload {
public:
    void display(int a) {
        cout << "Displaying integer: " << a << endl;
    }

    void display(double a) {
        cout << "Displaying double: " << a << endl;
    }

    void display(const char* a) {
        cout << "Displaying character: " << a << endl;
    }
};

int main() {
    Overload ol;

    ol.display(5);
    ol.display(3.14);
    ol.display("Hello, world!");

    return 0;
}
