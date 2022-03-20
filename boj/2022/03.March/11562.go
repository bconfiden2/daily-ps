package main

import (
	"bufio"
	"os"
	"strconv"
)

var (
	n, m int
	u, v, b int
	k, s, e int
	graph [][]int
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

func nextInt() int {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()

	n, m = nextInt(), nextInt()
	graph = make([][]int, n+1)
	for i := 0 ; i < n+1 ; i++ {
		graph[i] = make([]int, n+1)
	}
	for r := 1 ; r <= n ; r++ {
		for c := 1 ; c <= n ; c++ {
			graph[r][c] = 1000000
		}
	}

	for i := 0 ; i < m ; i++ {
		u, v, b = nextInt(), nextInt(), nextInt()
		if b == 1 {
			graph[v][u] = 0
		} else {
			graph[v][u] = 1
		}
		graph[u][v] = 0
	}

	for x := 1 ; x <= n ; x++ {
		graph[x][x] = 0
		for r := 1 ; r <= n ; r++ {
			for c := 1 ; c <= n ; c++ {
				if graph[r][c] > graph[r][x] + graph[x][c] {
					graph[r][c] = graph[r][x] + graph[x][c]
				}
			}
		}
	}

	k = nextInt()
	for i := 0 ; i < k ; i++ {
		s, e = nextInt(), nextInt()
		wr.WriteString(strconv.Itoa(graph[s][e]) + "\n")
	}
}