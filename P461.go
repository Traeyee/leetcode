package leetcode

func hammingDistance(x int, y int) int {
	z := x ^ y
	cnt := 0
	for z > 0 {
		if 1 == z%2 {
			cnt++
		}
		z /= 2
	}
	return cnt
}

func P461() {
	println(hammingDistance(1, 4))
}
