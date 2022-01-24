package leetcode

import "fmt"

func countBits(num int) []int {
	output := make([]int, num+1)
	output[0] = 0
	if 0 == num {
		return output
	}
	output[1] = 1
	for i := 1; i <= num; i++ {
		m1 := i << 1
		if m1 > num {
			break
		}
		output[m1] = output[i]
		m2 := m1 + 1
		if m2 > num {
			break
		}
		output[m2] = output[i] + 1
	}
	return output
}

func P338() {
	fmt.Println(countBits(5))
}
