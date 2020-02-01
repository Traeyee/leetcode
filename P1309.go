package leetcode

import (
	"strconv"
)

func freqAlphabets(s string) string {
	strStack := make([]string, 0)
	i := len(s) - 1
	for i >= 0 {
		c := string(s[i])
		var offset uint8
		if "#" == c {
			offsetTmp, _ := strconv.Atoi(s[i-2 : i])
			offset = uint8(offsetTmp)
			i -= 3
		} else {
			offsetTmp, _ := strconv.Atoi(s[i : i+1])
			offset = uint8(offsetTmp)
			i--
		}
		c2 := string(96 + offset)
		strStack = append(strStack, c2)
	}
	ret := ""
	for i := 0; i < len(strStack); i++ {
		ret += strStack[len(strStack)-1-i]
	}
	return ret
}

func P1309() {
	println(freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"))
}
