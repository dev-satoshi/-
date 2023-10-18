package main

import (
	"fmt"
	"time"
)

func checkPrime(num int) bool {
	for i := 3; i < num; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	st := time.Now()

	MaxNum := 100000
	fmt.Print("2 ")
	for j := 3; j <= MaxNum; j += 2 {
		if checkPrime(j) {
			fmt.Printf("%d ", j)
		}
	}
	fmt.Println()
	en := time.Now()
	elapsed := en.Sub(st)
	fmt.Printf("time : %.3f [s]\n", elapsed.Seconds())
}
