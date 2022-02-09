package main

import (
	"fmt"
	"os"
)

func main() {
	var N, K int
	fmt.Scanf("%d %d", &N, &K)

	
	arr := make([]bool, N+1)
	for i := 0 ; i <= N ; i++ {
		arr[i] = false
	}

	cnt := 0
	for i := 2 ; i <= N ; i++ {
		for p := i ; p <= N ; p += i {
			if arr[p] {
				continue
			}
			arr[p] = true
			cnt++
			if cnt == K {
				fmt.Println(p)
				os.Exit(0)
			}
		}
	}
}