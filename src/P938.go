package leetcode

import "fmt"

func rangeSumBST(root *TreeNode, L int, R int) int {
	nodeQ := []*TreeNode{root}
	sum := 0
	for len(nodeQ) > 0 {
		node := nodeQ[0]
		nodeQ = nodeQ[1:]
		if nil == node {
			continue
		}
		if node.Val < L {
			nodeQ = append(nodeQ, node.Right)
		} else if node.Val > R {
			nodeQ = append(nodeQ, node.Left)
		} else {
			sum += node.Val
			nodeQ = append(nodeQ, node.Left)
			nodeQ = append(nodeQ, node.Right)
		}
	}
	return sum
}

func P938() {
	valList1 := []interface{}{10, 5, 15, 3, 7, nil, 18}
	tree1 := valList2Tree(valList1)
	fmt.Println(rangeSumBST(tree1, 7, 15))
	valList2 := []interface{}{10, 5, 15, 3, 7, 13, 18, 1, nil, 6}
	tree2 := valList2Tree(valList2)
	fmt.Println(rangeSumBST(tree2, 6, 10))
}
