// 改成后序更简洁

package leetcode

func dfs(node *TreeNode, vals *[]int) {
	if nil == node {
		return
	}
	dfs(node.Left, vals)
	*vals = append(*vals, node.Val)
	dfs(node.Right, vals)
}

func dfsModify(node *TreeNode, vals *[]int, idx *int) {
	if nil == node {
		return
	}
	dfsModify(node.Left, vals, idx)
	node.Val = (*vals)[*idx]
	println(*idx)
	*idx++
	dfsModify(node.Right, vals, idx)
}

func bstToGst(root *TreeNode) *TreeNode {
	vals := make([]int, 0)
	dfs(root, &vals)
	addends := make([]int, len(vals))
	addends[len(addends)-1] = 0
	newVals := make([]int, len(vals))
	for i := len(vals); i > 0; i-- {
		newVals[i-1] = vals[i-1] + addends[i-1]
		if i >= 2 {
			addends[i-2] = newVals[i-1]
		}
	}
	var idx *int
	idxTmp := 0
	idx = &idxTmp
	dfsModify(root, &newVals, idx)
	vals = make([]int, 0)
	dfs(root, &vals)
	return root
}

func P1038() {
	input := []interface{}{4, 1, 6, 0, 2, 5, 7, nil, nil, nil, 3, nil, nil, nil, 8}
	tree := valList2Tree(input)
	bstToGst(tree)
}
