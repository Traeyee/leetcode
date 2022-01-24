/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   04 March 2020 15:20
 * @brief  
 */
package leetcode

import (
	"fmt"
)

func findWords(words []string) []string {
	lineMap := make([]map[int32]bool, 0)
	{
		line := make(map[int32]bool)
		for _, asciiCode := range "qwertyuiop" {
			line[asciiCode] = true
		}
		lineMap = append(lineMap, line)
	}
	{
		line := make(map[int32]bool)
		for _, asciiCode := range "asdfghjkl" {
			line[asciiCode] = true
		}
		lineMap = append(lineMap, line)
	}
	{
		line := make(map[int32]bool)
		for _, asciiCode := range "zxcvbnm" {
			line[asciiCode] = true
		}
		lineMap = append(lineMap, line)
	}

	ret := make([]string, 0)
	for _, word := range words {
		notWanted := false
		hitIdx := -1
		for _, asciiCode := range word {
			code1 := asciiCode
			if !(97 <= code1 && code1 <= 122) {
				code1 += 32
			}
			for i, line := range lineMap {
				if _, ok := line[code1]; ok {
					if -1 == hitIdx {
						hitIdx = i
					} else if hitIdx != i {
						notWanted = true
						break
					}
				}
			}
			if notWanted {
				break
			}
		}
		if !notWanted {
			ret = append(ret, word)
		}
	}
	return ret
}

func P500() {
	fmt.Println(findWords([]string{"Hello", "Alaska", "Dad", "Peace"}))
}
