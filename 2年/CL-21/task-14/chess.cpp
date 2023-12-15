#include <iostream>
#include <vector>
#include <string>

class Knight {
private:
    int x, y;
    std::vector<std::string> moves = {"c2", "c4", "d1", "d5", "f1", "f5", "g2", "g4"};

public:
    void setKnight(std::string position) {
        x = position[0] - 'a';
        y = position[1] - '1';
    }

    std::vector<std::string> getKnight() {
        std::vector<std::string> possible_moves;
        for (auto move : moves) {
            int dx = move[0] - 'a';
            int dy = move[1] - '1';
            if (isValidMove(dx, dy)) {
                possible_moves.push_back(move);
            }
        }
        return possible_moves;
    }

private:
    bool isValidMove(int dx, int dy) {
        return dx >= 0 && dx < 8 && dy >= 0 && dy < 8;
    }
};

int main() {
    // クラスのインスタンスを作成
    Knight knight;

    // ナイトの初期位置を設定
    knight.setKnight("e3");

    // ナイトの移動可能位置を取得
    std::vector<std::string> possibleMoves = knight.getKnight();

    // 結果を表示
    std::cout << "Knight's current position: e3\n";
    std::cout << "Possible moves:\n";
    for (const auto& move : possibleMoves) {
        std::cout << move << "\n";
    }

    return 0;
}