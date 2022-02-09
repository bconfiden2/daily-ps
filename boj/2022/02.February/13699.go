package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	
	mem := make([]uint64, n+1)
	mem[0] = 1
	for i := 1 ; i <= n ; i++ {
		var sum uint64
		for j := 0 ; j < i ; j++ {
			sum += mem[j] * mem[i-j-1]
		}
		mem[i] = sum
	}
	fmt.Println(mem[n])
}