/**
 * @author cuiyi@zuoshouyisheng.com
 * @time   05 March 2020 09:15
 * @brief  
 */
package leetcode

func findComplement(num int) int {
	higherBound := 1
	for higherBound <= num {
		higherBound <<= 1
	}
	return higherBound - 1 - num
}

func P476() {
	println(findComplement(1))
}
