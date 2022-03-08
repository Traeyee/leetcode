/**
 * @author cuiyiwork@foxmail.com
 * @time   03 February 2022 23:18
 * @brief  
 */
package leetcode

import "fmt"

func merge(nums1 []int, m int, nums2 []int, n int) {
	for i := 0; i < m; i++ {
		nums1[m+n-1-i] = nums1[m-1-i]
	}
	//fmt.Println(nums1)
	p, i, j := 0, n, 0
	for i < m+n && j < n {
		//fmt.Println("#here", p, i, nums1[i], j, nums2[j])
		if nums1[i] < nums2[j] {
			nums1[p] = nums1[i]
			i++
		} else {
			nums1[p] = nums2[j]
			j++
		}
		p++
	}
	for j < n {
		//fmt.Println(p, j, n)
		nums1[p] = nums2[j]
		j++
		p++
	}
}

func P88() {
	var nums1, nums2 []int
	var m, n int

	nums1 = []int{1, 2, 3, 0, 0, 0}
	m = 3
	nums2 = []int{2, 5, 6}
	n = 3
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)

	nums1 = []int{1}
	m = 1
	nums2 = []int{}
	n = 0
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)

	nums1 = []int{0}
	m = 0
	nums2 = []int{1}
	n = 1
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)

	nums1 = []int{4, 0, 0, 0, 0, 0}
	m = 1
	nums2 = []int{1, 2, 3, 5, 6}
	n = 5
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)
}
