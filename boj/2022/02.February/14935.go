package main

import (
	"fmt"
	"strconv"
)

var (
	arr [1000]bool
)

func F(x int) bool {
	tmp := strconv.Itoa(x)
	x2 := (int(tmp[0])-48) * len(tmp)
	if arr[x2] {
		return true
	} else {
		arr[x2] = true
		if F(x2){
			return true
		} else {
			return false
		}
	}
}

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if F(x) {
		fmt.Println("FA")
	} else {
		fmt.Println("NFA")
	}
}