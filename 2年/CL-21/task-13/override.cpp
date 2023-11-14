#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "This is Base class." << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "This is Derived class." << std::endl;
    }
};

int main() {
    Base* base = new Base();
    Base* derived = new Derived();

    base->print();      // This is Base class.
    derived->print();   // This is Derived class.

    delete base;
    delete derived;

    return 0;
}
