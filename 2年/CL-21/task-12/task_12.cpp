#include <stdio.h>

// Score クラスの定義
class Score {
protected:
    int p1;
    int p2;
    int p3;
    double avg;

public:
    // コンストラクタの宣言
    Score(int, int, int);

    // 各メンバ変数のゲッターの宣言
    int getP1(void);
    int getP2(void);
    int getP3(void);
    double getAvg(void);
};

// Score クラスのメンバ関数の実装
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

// Score クラスを継承した Score2 クラスの定義
class Score2 : public Score {
private:
    int sum;
    int flg;

public:
    // コンストラクタの宣言
    Score2(int, int, int);

    // 各メンバ変数のゲッターの宣言
    int getSum(void);
    int getJudge(void);
};

// Score2 クラスのコンストラクタの実装
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

// メイン関数の実装
int main(void) {
    const char *str[] = {"Failure", "Passed "};

    // Score2 オブジェクトの配列の宣言と初期化
    Score2 p[] = {
        Score2(80, 100, 58),
        Score2(55, 95, 55),
        Score2(60, 78, 60),
        Score2(74, 88, 90),
        Score2(84, 90, 62),
    };

    // 表のヘッダーの表示
    printf("+-----+-----+-----+-----+-------+-------+---------+\n");
    printf("| SNO |  P1 |  P2 |  P3 |  AVG  |  SUM  |JUDGEMENT|\n");
    printf("+-----+-----+-----+-----+-------+-------+---------+\n");

    // 各スコア情報の表示
    for (int i = 0; i < 5; i++) {
        printf("| %3d | %3d | %3d | %3d | %5.1f | %5d | %s |\n", (i + 1), p[i].getP1(), p[i].getP2(), p[i].getP3(), p[i].getAvg(), p[i].getSum(), str[p[i].getJudge()]);
    }

    // 表のフッターの表示
    printf("+-----+-----+-----+-----+-------+-------+---------+\n");
    return 0;
}