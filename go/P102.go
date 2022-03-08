/**
 * @author cuiyiwork@foxmail.com
 * @time   24 January 2022 23:17
 * @brief  问题汇总：
1. go test 用法
2. struct基础知识
3. append底层原理
 */

package leetcode

import "fmt"

type P22Node struct {
	Node  *TreeNode
	Depth int
}

func makeP22Node(node *TreeNode, depth int) P22Node {
	obj := new(P22Node)
	obj.Node = node
	obj.Depth = depth
	return *obj
}

func levelOrder(root *TreeNode) [][]int {
	if nil == root {
		return [][]int{}
	}
	res := make([][]int, 0)
	lastDepth := 0
	curLayer := make([]int, 0)

	rootNode := P22Node{root, 0}
	queue := []P22Node{rootNode}

	for ; len(queue) > 0; {
		curNode := queue[0]
		queue = queue[1:]
		if nil == curNode.Node {
			continue
		}
		lNode := P22Node{curNode.Node.Left, curNode.Depth + 1}
		rNode := P22Node{curNode.Node.Right, curNode.Depth + 1}
		queue = append(queue, lNode)
		queue = append(queue, rNode)

		if curNode.Depth != lastDepth {
			res = append(res, curLayer)
			curLayer = []int{curNode.Node.Val}
			lastDepth = curNode.Depth
		} else {
			curLayer = append(curLayer, curNode.Node.Val)
		}
	}
	if len(curLayer) > 0 {
		res = append(res, curLayer)
	}

	return res
}

func P102() {
	valList := []interface{}{3, 9, 20, nil, nil, 15, 7}
	root := valList2Tree(valList)
	res := levelOrder(root)

	fmt.Print("[")
	for _, layer := range res {
		fmt.Print("[")
		for _, ele := range layer {
			fmt.Printf("%d, ", ele)
		}
		fmt.Print("]")
	}
	fmt.Println("]")
}
