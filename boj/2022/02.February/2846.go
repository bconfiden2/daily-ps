package main

import (
	"fmt"
	"os"
	"bufio"
)

var (
	N, v int
	arr []int
	bef, sz, answer int
)

func main() {
	r := bufio.NewReader(os.Stdin)
	fmt.Fscan(r, &N)
	for i:=0 ; i < N ; i++ {
		fmt.Fscan(r, &v)
		arr = append(arr, v)
	}
	
	bef = arr[0]
	for _, v := range arr[1:] {
		if v > bef {
			sz += v-bef
			if sz > answer {
				answer = sz
			}
		} else {
			sz = 0
		}
		bef = v
	}
	fmt.Println(answer)
}