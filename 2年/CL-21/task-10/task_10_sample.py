class Score:
    def __init__(self, n1, n2, n3):
        self.p1 = n1
        self.p2 = n2
        self.p3 = n3
        self.avg  = (n1 + n2 + n3) / 3.0

    def getP1(self):
        return self.p1

    def getP2(self):
        return self.p2

    def getP3(self):
        return self.p3

    def getAvg(self):
        return self.avg

if __name__ == '__main__':
    p = [
        Score( 80,100, 58),
        Score( 55, 95, 55),
        Score( 60, 78, 60),
        Score( 74, 88, 90),
        Score( 84, 90, 62),
    ]

    print("+-----+-----+-----+-----+-------+")
    print("| SNO |  P1 |  P2 |  P3 |  AVG  |")
    print("+-----+-----+-----+-----+-------+")
    for i in range(5):
        print("| {:3d} | {:3d} | {:3d} | {:3d} | {:5.1f} |".format((i + 1), p[i].getP1(), p[i].getP2(), p[i].getP3(), p[i].getAvg()))
    print("+-----+-----+-----+-----+-------+")