package leetcode

func sumZero(n int) []int {
	ret := make([]int, 0)
	if 0 == n%2 {
		for i := 1; i <= n/2; i++ {
			ret = append(ret, i)
			ret = append(ret, -i)
		}
	} else {
		for i := 1; i <= (n-1)/2; i++ {
			ret = append(ret, i)
			ret = append(ret, -i)
		}
		ret = append(ret, 0)
	}
	return ret
}
