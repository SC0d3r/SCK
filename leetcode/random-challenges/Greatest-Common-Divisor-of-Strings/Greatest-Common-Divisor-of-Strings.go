package main

import (
	"fmt"
	"time"
)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}

	return gcd(b, a%b)
}

func gcdOfStrings(str1 string, str2 string) string {
	defer perf("gcdOfStrings")()

	if str1+str2 == str2+str1 {
		return str1[:gcd(len(str1), len(str2))]
	}

	return ""
}

func main() {
	// fmt.Println("gcd(54, 30) is", gcd(54, 30))
	a := "ABABAB"
	b := "AB"
	fmt.Println("result", gcdOfStrings(a, b))
}

func perf(label string) func() {
	start := time.Now()
	return func() {
		fmt.Printf("%s execution time is %v\n", label, time.Since(start))
	}
}
