package leetcode

import (
	"fmt"
)

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	if len(nums1) == 0 {
		return []int{}
	}
	nextGreaterMap := make(map[int]int)
	stack := []int{nums2[0]}
	i := 1
	for i < len(nums2) {
		for len(stack) > 0 {
			rightMost := stack[len(stack)-1]
			if rightMost < nums2[i] {
				nextGreaterMap[rightMost] = nums2[i]
				stack = stack[0 : len(stack)-1]  // pop
			} else {
				break
			}
		}
		stack = append(stack, nums2[i])  // push
		i++
	}
	for _, num := range stack {
		nextGreaterMap[num] = -1
	}
	ret := make([]int, len(nums1))
	for i = 0; i < len(nums1); i++ {
		ret[i] = nextGreaterMap[nums1[i]]
	}
	return ret
}

func P496() {
	ret := nextGreaterElement([]int{4, 1, 2}, []int{1, 3, 4, 2})
	for _, ele := range ret {
		fmt.Println(ele)
	}
}
