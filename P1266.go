package leetcode

import "math"

func twoPointDistance(point1 []int, point2 []int) int {
	distX := math.Abs(float64(point1[0] - point2[0]))
	distY := math.Abs(float64(point1[1] - point2[1]))
	return map[bool]int{true: int(distX), false: int(distY)}[distX > distY]
}

func minTimeToVisitAllPoints(points [][]int) int {
	dist := 0
	for i := 0; i < len(points) - 1; i++ {
		dist += twoPointDistance(points[i], points[i+1])
	}
	return dist
}

func P1266()  {
	points := [][]int{{1, 1}, {3, 4}, {-1, 0}}
	println(minTimeToVisitAllPoints(points))
}
