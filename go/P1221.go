package leetcode

import "fmt"

func balancedStringSplit(s string) int {
	ret := 0
	counter := 0
	for _, code := range s {
		c := string(code)
		if "L" == c {
			counter += 1
		} else {
			counter -= 1
		}
		if 0 == counter {
			ret += 1
		}
	}
	return ret
}

func P1221() {
	fmt.Println(balancedStringSplit("RLLLLRRRLR"))
}
