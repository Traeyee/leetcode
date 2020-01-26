package leetcode

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func valList2Tree(valList []interface{}) *TreeNode {
	if 0 == len(valList) {
		return nil
	}
	var root *TreeNode
	root = nil
	nodePtrPtrQueue := []**TreeNode{&root}
	for _, val := range valList {
		nodePtrPtr := nodePtrPtrQueue[0]
		nodePtrPtrQueue = nodePtrPtrQueue[1:]
		if nil == val {
			*nodePtrPtr = nil
			continue
		}
		intVal := val.(int)
		*nodePtrPtr = &TreeNode{intVal, nil, nil}
		nodePtrPtrQueue = append(nodePtrPtrQueue, &(*nodePtrPtr).Left)
		nodePtrPtrQueue = append(nodePtrPtrQueue, &(*nodePtrPtr).Right)
	}
	return root
}

func printTree(root *TreeNode) {
	nodeStack := []*TreeNode{root}
	depthStack := []int{0}
	labelStack := []string{"ROOT"}
	for ok := true; ok; ok = len(nodeStack) > 0 {
		length := len(nodeStack)
		node := nodeStack[length-1]
		nodeStack = nodeStack[:length-1]
		depth := depthStack[length-1]
		depthStack = depthStack[:length-1]
		label := labelStack[length-1]
		labelStack = labelStack[:length-1]
		if nil == node {
			continue
		}
		spaces := ""
		for i := 0; i < depth; i++ {
			spaces += "    "
		}
		fmt.Printf("%s(%s)├── %d\n", spaces, label, node.Val)
		nodeStack = append(nodeStack, node.Right)
		depthStack = append(depthStack, depth+1)
		labelStack = append(labelStack, "R")
		nodeStack = append(nodeStack, node.Left)
		depthStack = append(depthStack, depth+1)
		labelStack = append(labelStack, "L")
	}
}
