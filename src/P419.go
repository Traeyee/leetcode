package leetcode

func countBattleships(board [][]byte) int {
	if 0 == len(board) {
		return 0
	}
	if 0 == len(board[0]) {
		return 0
	}
	cnt := 0
	if 'X' == board[0][0] {
		cnt++
	}
	for j := 1; j < len(board[0]); j++ {
		if 'X' == board[0][j] && '.' == board[0][j-1] {
			cnt++
		}
	}
	for i := 1; i < len(board); i++ {
		if 'X' == board[i][0] && '.' == board[i-1][0] {
			cnt++
		}
	}
	for i := 1; i < len(board); i++ {
		for j := 1; j < len(board[0]); j++ {
			if 'X' == board[i][j] && '.' == board[i][j-1] && '.' == board[i-1][j] {
				cnt++
			}
		}
	}
	return cnt
}

func P419() {
	input := [][]byte{{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}}
	println(countBattleships(input))
}
