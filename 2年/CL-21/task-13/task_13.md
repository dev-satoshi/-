## レポート

## OverRide
オーバーライドは、基底クラスで定義されたメソッドを派生クラスで再定義することを指します。
これにより、そのメソッドの振る舞いを変更することができます。
以下に、BaseクラスのprintメソッドをDerivedクラスでオーバーライドした例を示します。
```
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
```

## OverLoad
オーバーロードは、同じ名前の関数を異なるパラメータで複数定義することを指します。
以下に、整数と浮動小数点数を表示するためのdisplay関数をオーバーロードした例を示します。
```
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
```