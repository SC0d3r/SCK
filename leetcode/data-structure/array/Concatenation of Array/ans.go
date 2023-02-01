package main

import "fmt"

func getConcatenation(nums []int) []int {
	return append(nums, nums...)
}

func main() {
	arr := []int{1, 2, 3}
	fmt.Println("ans is", getConcatenation(arr))
}
