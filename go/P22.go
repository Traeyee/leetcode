/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   14 May 2020 14:05
 * @brief   Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

 */
package leetcode

import "fmt"

func generateParenthesis(n int) []string {
	if n <= 0 {
		return []string{}
	}
	if 1 == n {
		return []string{"()"}
	}
	retSet := make(map[string]bool)
	ret := make([]string, 0)
	for _, s0 := range generateParenthesis(n - 1) {
		retSet["(" + s0 + ")"] = true
	}
	for i := 1; i < n; i++ {
		j := n - i
		leftParts := generateParenthesis(i)
		rightParts := generateParenthesis(j)
		for _, s1 := range leftParts {
			for _, s2 := range rightParts {
				retSet[s1 + s2] = true
			}
		}
	}
	for key := range retSet {
		ret = append(ret, key)
	}
	return ret
}

func P22()  {
	for _, p := range generateParenthesis(3) {
		fmt.Println(p)
	}
}