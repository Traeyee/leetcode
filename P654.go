package leetcode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructMaximumBinaryTree(nums []int) *TreeNode {
	if 0 == len(nums) {
		return nil
	}
	maxNum := -0x3f3f
	maxNumIdx := -1
	for i, num := range nums {
		if num > maxNum {
			maxNum = num
			maxNumIdx = i
		}
	}
	root := &TreeNode{maxNum, nil, nil}
	root.Left = constructMaximumBinaryTree(nums[:maxNumIdx])
	root.Right = constructMaximumBinaryTree(nums[maxNumIdx+1:])
	return root
}

func P654() {
	input := []int{3, 2, 1, 6, 0, 5}
	tree := constructMaximumBinaryTree(input)
	printTree(tree)
}
