package leetcode

import (
	"fmt"
)

func maxIncreaseKeepingSkyline(grid [][]int) int {
	sum := 0
	frontView := make([]int, len(grid[0]))
	endView := make([]int, len(grid))
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] > frontView[j] {
				frontView[j] = grid[i][j]
			}
			if grid[i][j] > endView[i] {
				endView[i] = grid[i][j]
			}
		}
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			limit := map[bool]int{true: endView[i], false: frontView[j]}[endView[i] < frontView[j]]
			sum += limit - grid[i][j]
		}
	}
	return sum
}

func P807() {
	inputs := [][]int{{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}}
	fmt.Println(maxIncreaseKeepingSkyline(inputs))
}
