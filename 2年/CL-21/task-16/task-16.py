from datetime import datetime


class Member:
    def __init__(self, name, birthdate, login_id, password):
        self.name = name
        self.birthdate = birthdate
        self.login_id = login_id
        self.password = password

    def getAge(self):
        today = datetime.now()
        birthdate = datetime.strptime(self.birthdate, "%Y-%m-%d")
        age = today.year - birthdate.year - ((today.month, today.day) < (birthdate.month, birthdate.day))
        return age


# メインルーチン
if __name__ == "__main__":
    # メンバーオブジェクトの作成
    member1 = Member("John Doe", "1990-05-15", "john_doe", "password123")

    # 年齢の取得と表示
    age = member1.getAge()
    print(f"{member1.name}の年齢は{age}歳です。")
