## 課題１２（評価）クラスの継承

## 内容
課題１０で作成したプログラムにクラスの継承を適用して、３科目のテスト得点の個人ごとの「合計点欄」と「合否欄」を求めるプログラム「K12.cpp」を作成した。
このプログラムの動作を１行毎にコメントを付けてレポートとしてまとめよ。

【プログラム】
添付ファイル「k12.cpp」参照

k12.cpp
```
//
// CL21 kadai12 sample program
//
#include    <stdio.h>

//---------------------------------------------------- Score
class Score {
protected:
    int p1;
    int p2;
    int p3;
    double avg;

public:
    Score(int, int, int);
    int getP1(void);
    int getP2(void);
    int getP3(void);
    double getAvg(void);
};

Score::Score(int n1, int n2, int n3) {
    p1 = n1;
    p2 = n2;
    p3 = n3;
    avg = (double)(n1 + n2 + n3) / 3.0;
}

int Score::getP1(void) {
    return p1;
}

int Score::getP2(void) {
    return p2;
}

int Score::getP3(void) {
    return p3;
}

double Score::getAvg(void) {
    return avg;
}

//---------------------------------------------------- Score2
class Score2 : public Score {
private:
    int sum;
    int flg;
public:
    Score2(int, int, int);
    int getSum(void);
    int getJudge(void);
};

Score2::Score2(int n1, int n2, int n3) : Score(n1, n2, n3) {
    sum = n1 + n2 + n3;
    flg = (sum >= 220) ? 1 : 0;
}

int Score2::getSum(void) {
    return sum;
}

int Score2::getJudge(void) {
    return flg;
}

//---------------------------------------------------- main
int main(void) {
    const char *str[] = {"Failure", "Passed "};
    Score2 p[] = {
        Score2( 80,100, 58), // 出席番号1の得点
        Score2( 55, 95, 55), // 出席番号2の得点
        Score2( 60, 78, 60), // 出席番号3の得点
        Score2( 74, 88, 90), // 出席番号4の得点
        Score2( 84, 90, 62)  // 出席番号5の得点
    };

    printf("+-----+-----+-----+-----+-------+-------+---------+\n");
    printf("| SNO |  P1 |  P2 |  P3 |  AVG  |  SUM  |JUDGEMENT|\n");
    printf("+-----+-----+-----+-----+-------+-------+---------+\n");
    for (int i = 0; i < 5; i++) {
        printf("| %3d | %3d | %3d | %3d | %5.1f | %5d | %s |\n", (i + 1), p[i].getP1(), p[i].getP2(), p[i].getP3(), p[i].getAvg(), p[i].getSum(), str[p[i].getJudge()]);
    }
    printf("+-----+-----+-----+-----+-------+-------+---------+\n");
    return 0;
}
```