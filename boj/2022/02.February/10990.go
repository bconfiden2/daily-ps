package main

import (
	"fmt"
	"bytes"
	"os"
)

var (
	w *bytes.Buffer
	N int
)

func main() {
	w = new(bytes.Buffer)
	fmt.Scanf("%d", &N)
	tmp := (2*N-1)/2
	for i := 0 ; i < N ; i++ {
		w.Reset()
		for j := 0 ; j < 2*N-1 ; j++ {
			if j == tmp-i {
				w.WriteByte('*')
				if i == 0 {
					break
				}
			} else if j == tmp+i {
				w.WriteByte('*')
				break
			} else {
				w.WriteByte(' ')
			}
		}
		w.WriteByte('\n')
		w.WriteTo(os.Stdout)
	}
}