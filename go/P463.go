/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   08 March 2020 11:31
 * @brief  
 */
package leetcode

func islandPerimeter(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	rows := len(grid)
	cols := len(grid[0])
	perimeter := 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if 0 == i {
				if 1 == grid[i][j] {
					perimeter++
				}
			} else {
				if 1 == grid[i-1][j] ^ grid[i][j] {
					perimeter++
				}
			}
			if rows-1 == i {
				if 1 == grid[i][j] {
					perimeter++
				}
			}
			if 0 == j {
				if 1 == grid[i][j] {
					perimeter++
				}
			} else {
				if 1 == grid[i][j-1] ^ grid[i][j] {
					perimeter++
				}
			}
			if cols-1 == j {
				if 1 == grid[i][j] {
					perimeter++
				}
			}
		}
	}
	return perimeter
}
