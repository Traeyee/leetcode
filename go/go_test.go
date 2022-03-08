/**
 * @author cuiyiwork@foxmail.com
 * @time   28 January 2022 17:19
 * @brief  命名文件时需要让文件必须以_test结尾
 */
package leetcode

import (
	"fmt"
	"reflect"
	"testing"
)

type Type1 struct {
	val int
}

func foo1() {
	fmt.Println(`foo1`)
}

func (t Type1) foo2() {
	fmt.Println(`foo2`)
}

func testMethod() {
	foo1()
	t := new(Type1)
	t.foo2()
}

func Sum(nums ...int) int {
	res := 0
	for _, n := range nums {
		res += n
	}
	return res
}

func testIterChn() {
	s := "he 也 is 一个超级大肥仔"
	for _, unc := range s {
		fmt.Println(string(unc))
	}
}

func testThreePoints() {
	fmt.Println(Sum(1, 2, 3))

	primes := []int{2, 3, 5, 7}
	fmt.Println(Sum(primes...))

	// 创建的是数组
	stooges := [...]string{"Moe", "Larry", "Curly"}
	fmt.Println(reflect.TypeOf(stooges))
	fmt.Println(stooges)
	fmt.Println(len(stooges))

	// 创建的是slice
	stooges1 := []string{"Moe", "Larry", "Curly"}
	fmt.Println(reflect.TypeOf(stooges1))
	fmt.Println(stooges1)
	fmt.Println(len(stooges1))

	// Go命令行中的通配符
	// 描述包文件的通配符。
	// 在这个例子中，会单元测试当前目录和所有子目录的所有包：
	// go test ./...

}

func TestGo(t *testing.T) {
	testThreePoints()
}
