package main

import (
	"fmt"
	"bufio"
	"os"
)

var (
	N, v int
	cmd string
	q []int
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)

	fmt.Fscan(r, &N)
	for i := 0 ; i < N ; i++ {
		fmt.Fscan(r, &cmd)
		switch cmd {
		case "push":
			fmt.Fscan(r, &v)
			q = append(q, v)
		case "pop":
			if len(q) == 0 {
				w.WriteString("-1\n")
			} else {
				fmt.Fprintln(w, q[0])
				q = q[1:]
			}
		case "size":
			fmt.Fprintln(w, len(q))
		case "empty":
			if len(q) == 0 {
				w.WriteString("1\n")
			} else {
				w.WriteString("0\n")
			}
		case "front":
			if len(q) == 0 {
				w.WriteString("-1\n")
			} else {
				fmt.Fprintln(w, q[0])
			}
		default:
			if len(q) == 0 {
				w.WriteString("-1\n")
			} else {
				fmt.Fprintln(w, q[len(q)-1])
			}
		}
	}
	w.Flush()
}