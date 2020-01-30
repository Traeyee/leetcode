package leetcode

func oddCells(n int, m int, indices [][]int) int {
	matrix := make([][]int, 0)
	for i := 0; i < n; i++ {
		row := make([]int, m)
		for j := 0; j < m; j++ {
			row[j] = 0
		}
		matrix = append(matrix, row)
	}
	for _, index := range indices {
		for i := 0; i < m; i++ {
			matrix[index[0]][i]++
		}
		for i := 0; i < n; i++ {
			matrix[i][index[1]]++
		}
	}
	cnt := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if 1 == matrix[i][j]%2 {
				cnt++
			}
		}
	}
	return cnt
}

func P1252() {
	println(oddCells(2, 3, [][]int{{0, 1}, {1, 1}}))
}
