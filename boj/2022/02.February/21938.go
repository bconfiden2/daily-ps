package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	R, C, T int
	graph [][]int
	dir [4]int = [4]int{1,-1,0,0}
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

	R = nextInt()
	C = nextInt()
	graph = make([][]int, R)
	for i := 0 ; i < R ; i++ {
		graph[i] = make([]int, C)
	}

	var tmp int
	for r := 0 ; r < R ; r++ {
		for c := 0 ; c < 3*C ; c++ {
			tmp = nextInt()
			graph[r][c/3] += tmp
		}
	}
	
	T = nextInt()
	T *= 3
	for r := 0 ; r < R ; r++ {
		for c := 0 ; c < C ; c++ {
			if graph[r][c] >= T {
				graph[r][c] = 1
			} else {
				graph[r][c] = 0
			}
		}
	}

	ans := 0
	for r := 0 ; r < R ; r++ {
		for c := 0 ; c < C ; c++ {
			if graph[r][c] == 1 {
				dfs(graph, r, c)
				ans++
			}
		}
	}
	fmt.Println(ans)
}

func dfs(graph [][]int, r, c int) {
	graph[r][c] = 0
	for i := 0 ; i < 4 ; i++ {
		nr, nc := r + dir[i], c + dir[3-i]
		if 0 <= nr && nr < R && 0 <= nc && nc < C {
			if graph[nr][nc] == 1 {
				dfs(graph, nr, nc)
			}
		}
	}
}