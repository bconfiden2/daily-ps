package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

var (
	R, C int
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

func dfs(r, c int, graph [][]int, visited [][]bool) (int) {
	visited[r][c] = true
	cnt := 1
	nr, nc := 0, 0
	for i := 0 ; i < 4 ; i++ {
		nr, nc = r + dir[i], c + dir[3-i]
		if 0 <= nr && nr < R && 0 <= nc && nc < C {
			if !visited[nr][nc] {
				cnt += dfs(nr, nc, graph, visited)
			}
		}
	}
	
	return cnt
}

func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()

	R = nextInt()
	C = nextInt()
	graph := make([][]int, R)
	visited := make([][]bool, R)
	for r := 0 ; r < R ; r++ {
		graph[r] = make([]int, C)
		visited[r] = make([]bool, C)
		for c := 0 ; c < C ; c++ {
			graph[r][c] = nextInt();
			if graph[r][c] == 1 {
				visited[r][c] = false
			} else {
				visited[r][c] = true
			}
			
		}
	}
	
	maxi := 0
	cnt := 0
	for r := 0 ; r < R ; r++ {
		for c := 0 ; c < C ; c++ {
			if !visited[r][c] {
				tmp := dfs(r, c, graph, visited)
				if tmp > maxi {
					maxi = tmp
				}
				cnt++
			}
		}
	}
	fmt.Printf("%d\n%d\n", cnt, maxi)
}