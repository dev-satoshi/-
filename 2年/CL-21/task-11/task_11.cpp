#include <iostream>
#include <vector>
#include <iomanip>
#include <string> // 追加

class Student {
public:
    std::string name;
    std::vector<int> scores;

    Student(std::string name, std::vector<int> scores) : name(name), scores(scores) {}

    double getAverage() {
        int sum = 0;
        for(int i = 0; i < scores.size(); i++) {
            sum += scores[i];
        }
        return static_cast<double>(sum) / scores.size();
    }

    int getSum() {
        int sum = 0;
        for(int i = 0; i < scores.size(); i++) {
            sum += scores[i];
        }
        return sum;
    }

    std::string getJudgement() {
        return getSum() >= 220 ? "合格" : "不合格";
    }
};

int main() {
    std::vector<Student> students;
    students.push_back(Student("1", {80, 100, 58}));
    students.push_back(Student("2", {55, 95, 55}));
    students.push_back(Student("3", {60, 78, 60}));
    students.push_back(Student("4", {74, 88, 90}));
    students.push_back(Student("5", {84, 90, 62}));

    std::cout << std::left << std::setw(10) << "出席番号"
              << std::setw(15) << "第1回目"
              << std::setw(15) << "第2回目"
              << std::setw(15) << "第3回目"
              << std::setw(15) << "平均点"
              << std::setw(15) << "合計点"
              << std::setw(10) << "判定" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    for(int i = 0; i < students.size(); i++) {
        std::cout << std::left << std::setw(10) << students[i].name;
        for(int j = 0; j < students[i].scores.size(); j++) {
            std::cout << std::setw(15) << students[i].scores[j];
        }
        std::cout << std::setw(15) << students[i].getAverage();
        std::cout << std::setw(15) << students[i].getSum();
        std::cout << std::setw(10) << students[i].getJudgement() << std::endl;
    }

    return 0;
}
