/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   03 March 2020 15:58
 * @brief  
 */
package leetcode

import (
	"fmt"
	"math"
)

// vanilla
func findDuplicates1(nums []int) []int {
	hashSet := make(map[int]bool)
	ret := make([]int, 0)
	for _, num := range nums {
		if _, ok := hashSet[num]; ok {
			ret = append(ret, num)
		} else {
			hashSet[num] = true
		}
	}
	return ret
}

func findDuplicates(nums []int) []int {
	ret := make([]int, 0)
	for i := 0; i < len(nums); i++ {
		if nums[int(math.Abs(float64(nums[i])))-1] < 0 {
			ret = append(ret, int(math.Abs(float64(nums[i]))))
		} else {
			nums[int(math.Abs(float64(nums[i])))-1] *= -1
		}
	}
	return ret
}

func P442() {
	nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
	ret := findDuplicates(nums)
	fmt.Println(ret)
}
