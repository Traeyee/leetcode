/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   19 March 2020 00:44
 * @brief  
 */
package leetcode

import "fmt"

func inorderRecursive(node *TreeNode, ret *[]int) {
	if nil == node {
		return
	}
	inorderRecursive(node.Left, ret)
	*ret = append(*ret, node.Val)
	inorderRecursive(node.Right, ret)
}

func inorderTraversal(root *TreeNode) []int {
	ret := make([]int, 0)
	inorderRecursive(root, &ret)
	return ret
}

func P94() {
	tree := valList2Tree([]interface{}{1, nil, 2, 3})
	ret := inorderTraversal(tree)
	fmt.Println(ret)
}