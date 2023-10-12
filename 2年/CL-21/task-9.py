#!/usr/bin/python3
#
import time


def checkPrime(num):
    for i in range(3, num, 2):
        if num % i == 0:
            return False

    return True


if __name__ == "__main__":
    st = time.time()
    MaxNum = 10000
    print("2 ", end="")
    for j in range(3, MaxNum + 1, 2):
        if checkPrime(j):
            print("{} ".format(j), end="")

    print()
    en = time.time()
    print(en - st)
