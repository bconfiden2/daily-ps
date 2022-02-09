package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)
	if N % 2 == 0 {
		fmt.Println("SK")
	} else {
		fmt.Println("CY")
	}
}