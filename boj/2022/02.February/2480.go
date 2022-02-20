package main

import (
	"fmt"
)

func Max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)
	if a==b && b==c {
		fmt.Println(10000 + a*1000)
	} else if a==b {
		fmt.Println(1000 + a*100)
	} else if b==c {
		fmt.Println(1000 + b*100)
	} else if c==a {
		fmt.Println(1000 + c*100)
	} else {
		fmt.Println(Max(Max(a,b),c)*100)
	}
}