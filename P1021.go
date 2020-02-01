package leetcode

func removeOuterParentheses(S string) string {
	ret := ""
	currentPart := ""
	parenthesesDiff := 0
	for i := 0; i < len(S); i++ {
		c := S[i : i+1]
		if "(" == c {
			if 0 != parenthesesDiff {
				currentPart += c
			}
			parenthesesDiff++
		} else {
			parenthesesDiff--
			if 0 != parenthesesDiff {
				currentPart += c
			} else {
				ret += currentPart
				currentPart = ""
			}
		}
	}
	return ret
}

func P1021() {
	println(removeOuterParentheses("(()())(())(()(()))"))
}
