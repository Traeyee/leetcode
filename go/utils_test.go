package leetcode

import (
	"fmt"
	"testing"
)

func TestPrintTree(t *testing.T) {
	node := TreeNode{0, nil, nil}
	node1 := TreeNode{1, nil, nil}
	node.Left = &node1
	node2 := TreeNode{2, nil, nil}
	node.Right = &node2
	node3 := TreeNode{3, nil, nil}
	node2.Left = &node3
	printTree(&node)
}

func TestValList2Tree(t *testing.T) {
	valList := []interface{}{10, 5, 15, 3, 7, 13, 18, 1, nil, 6}
	tree := valList2Tree(valList)
	fmt.Println(tree)
	printTree(tree)
}
