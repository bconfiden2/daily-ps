package main

import (
	"bufio"
	"os"
	"strconv"
	"fmt"
)

var (
	T, tc, n, m int
	a, b int
	graph [][]int
	visited []bool
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

func nextInt() int {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func dfs(i int) {
	visited[i] = true
	for nxt := range graph[i] {
		if !visited[nxt] {
			dfs(nxt)
		}
	}
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()

	T = nextInt()
	for tc = 0 ; tc < T ; tc++ {
		n, m = nextInt(), nextInt()
		graph = make([][]int, n)
		for nn := 0 ; nn < n ; nn++ {
			graph[nn] = make([]int, 0)
		}
		for mm := 0 ; mm < m ; mm++ {
			a, b = nextInt()-1, nextInt()-1
		}
		fmt.Println(n-1)
	}
}