#include <iostream>

// インターフェース
class Shape {
public:
  virtual void draw() = 0;
};

// 抽象クラス
class Circle : public Shape {
public:
  Circle(int radius) : radius_(radius) {}

  void draw() override {
    std::cout << "円を描きます。半径は" << radius_ << "です。" << std::endl;
  }

private:
  int radius_;
};

// 抽象クラスの派生クラス
class Rectangle : public Shape {
public:
  Rectangle(int width, int height) : width_(width), height_(height) {}

  void draw() override {
    std::cout << "矩形を描きます。幅は" << width_ << "、高さは" << height_ << "です。" << std::endl;
  }

private:
  int width_;
  int height_;
};

int main() {
  // インターフェースを実装したオブジェクトを生成
  Shape* circle = new Circle(10);
  Shape* rectangle = new Rectangle(20, 30);

  // オブジェクトのdraw()メソッドを呼び出して、図形を描画
  circle->draw();
  rectangle->draw();

  return 0;
}