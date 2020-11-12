/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   19 March 2020 01:06
 * @brief  
 */
package leetcode

import "fmt"

type P46Node struct {
	val int
	previous, next *P46Node
}

func permuteDfs(retTmp *[]int, ret *[][]int, head *P46Node) {
	if nil == head {
		retCopy := make([]int, len(*retTmp))
		copy(retCopy, *retTmp)
		*ret = append(*ret, retCopy)
		return
	}
	tmpPtr := head
	for nil != tmpPtr {
		*retTmp = append(*retTmp, tmpPtr.val)
		if nil != tmpPtr.previous {
			tmpPtr.previous.next = tmpPtr.next
		}
		if nil != tmpPtr.next {
			tmpPtr.next.previous = tmpPtr.previous
		}
		if tmpPtr == head {
			permuteDfs(retTmp, ret, tmpPtr.next)
		} else {
			permuteDfs(retTmp, ret, head)
		}
		if nil != tmpPtr.next {
			tmpPtr.next.previous = tmpPtr
		}
		if nil != tmpPtr.previous {
			tmpPtr.previous.next = tmpPtr
		}
		*retTmp = (*retTmp)[:len(*retTmp)-1]
		tmpPtr = tmpPtr.next
	}
}

func permute(nums []int) [][]int {
	var head, tail *P46Node
	head = nil
	tail = nil
	// build the linklist
	for _, num := range nums {
		node := P46Node{num, nil, nil}
		if nil == head {
			head = &node
		}
		if nil != tail {
			tail.next = &node
			node.previous = tail
		}
		tail = &node
	}
	ret := make([][]int, 0)
	retTmp := make([]int, 0)
	permuteDfs(&retTmp, &ret, head)
	return ret
}

func P46() {
	ret := permute([]int{1, 2, 3})
	fmt.Println(ret)
}

/* neat solution
func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	ans := make([][]int, 0)
	backtrack(nums, nil, &ans)

	return ans
}

func backtrack(nums []int, prev []int, ans *[][]int) {
	if len(nums) == 0 {
		*ans = append(*ans, append([]int{}, prev...))
		return
	}

	for i := 0; i < len(nums); i++ {
		backtrack(append(append([]int{}, nums[0:i]...), nums[i+1:]...),
			append(prev, nums[i]),
			ans)
	}
}
*/