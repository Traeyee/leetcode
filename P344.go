package leetcode

func reverseString(s []byte) {
	for i := 0; i < len(s)>>1; i++ {
		tmp := s[i]
		s[i] = s[len(s)-1-i]
		s[len(s)-1-i] = tmp
	}
}
