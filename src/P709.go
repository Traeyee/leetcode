package leetcode

func toLowerCase(str string) string {
	asciiCodes := make([]int32, len(str))
	for i, c := range str {
		if 65 <= c && c <= 90 {
			asciiCodes[i] = c + 32
		} else {
			asciiCodes[i] = c
		}
	}
	return string(asciiCodes[:])
}

func P709() {
	println(toLowerCase("Hello"))
}
