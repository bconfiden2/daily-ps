package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	for i := N ; i > 0 ; i-- {
		fmt.Print(strings.Repeat(" ", N-i))
		fmt.Println(strings.Repeat("*", 2*i-1))
	}
}