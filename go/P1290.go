package leetcode

import "fmt"

func getDecimalValue(head *ListNode) int {
	ret := 0
	stk := make([]int, 0)
	var ptr *ListNode
	ptr = head
	for ok := true; ok; ok = ptr != nil {
		stk = append(stk, ptr.Val)
		ptr = ptr.Next
	}
	var base uint
	base = 0
	for i := len(stk); i > 0; i-- {
		ret += stk[i - 1] * 1 << base
		base++
	}
	return ret
}

func P1290() {
	listVals := []int{1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}
	var head, ptr *ListNode
	head = nil
	ptr = head
	for i := 0; i < len(listVals); i++ {
		listNode := ListNode{listVals[i], nil}
		if nil == ptr {
			head = &listNode
			ptr = head
		} else {
			ptr.Next = &listNode
			ptr = ptr.Next
		}
	}
	fmt.Println(getDecimalValue(head))
}
