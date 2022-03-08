/**
 * @author cuiyiwork@foxmail.com
 * @time   25 January 2022 14:24
 * @brief  问题汇总：
go哪些是值传递，哪些是引用传递
 */
package leetcode

import "fmt"

func generate(numRows int) [][]int {
	res := make([][]int, 0)
	// rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j]
	var row []int
	for rowth := 1; rowth <= numRows; rowth++ {
		row = make([]int, rowth)
		row[0] = 1
		for j := 1; j <= (rowth-1)/2; j++ {
			// corner
			lastRow := res[len(res)-1]
			row[j] = lastRow[j-1] + lastRow[j]
			row[rowth-1-j] = row[j]
		}
		row[rowth-1] = 1
		res = append(res, row)
	}

	return res
}

func printDoubleNestedInt(res [][]int) {
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

func P118() {
	var numRows int
	var res [][]int

	numRows = 5
	res = generate(numRows)
	printDoubleNestedInt(res)

	numRows = 1
	res = generate(numRows)
	printDoubleNestedInt(res)
}
