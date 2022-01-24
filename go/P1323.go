package leetcode

import (
	"fmt"
	"math"
)

func maximum69Number(num int) int {
	// find index of the first 6
	// and the index of the last 9
	idx6 := -1
	n := num
	idx := 0
	for ok := true; ok; ok = n > 0 {
		digit := n % 10
		if 6 == digit {
			idx6 = idx
		}
		n /= 10
		idx += 1
	}
	if -1 == idx6 {
		return num
	}
	return num + 3 * int(math.Pow10(idx6))
}

func P1323()  {
	fmt.Println(maximum69Number(9669))
	fmt.Println(maximum69Number(9996))
	fmt.Println(maximum69Number(9999))
	fmt.Println(maximum69Number(6666))
}
