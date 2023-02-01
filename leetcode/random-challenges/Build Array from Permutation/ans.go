package main

import (
	"fmt"
)

func buildArray(nums []int) []int {
	res := []int{}

	for _, x := range nums {
		res = append(res, nums[x])
	}

	return res
}

func main() {
	arr := []int{0, 2, 1, 5, 3, 4}
	fmt.Println("ans is", buildArray(arr))
}
