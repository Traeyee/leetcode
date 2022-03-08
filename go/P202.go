/**
 * @author cuiyiwork@foxmail.com
 * @time   27 January 2022 20:29
 * @brief  
 */
package leetcode

import "fmt"

func isHappy(n int) bool {
	visited := map[int]bool{}
	for ; ; {
		if 1 == n {
			break
		}
		if _, ok := visited[n]; ok {
			return false
		}
		visited[n] = true

		n2 := 0
		for ; n > 0; {
			r := n % 10
			n2 += r * r
			n /= 10
		}
		n = n2
	}
	return true
}

func P202() {
	fmt.Println(isHappy(19))

	fmt.Println(isHappy(2))
}
