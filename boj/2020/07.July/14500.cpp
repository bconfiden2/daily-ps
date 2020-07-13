#include <iostream>
using namespace std;

int n, m;
int score[500][500];
int points[8][19] = {                   // 노가다성 문제는 아닐 것 같은데...
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 19가지 가능한 테트로미노 종류
    {1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1},  // 4개 점들의 x, y 좌표 배열들
    {0, 0, 2, 2, 2, 0, 0, 1, 2, 0, 1, 1, 1,-1, 1, 0, 0, 2, 2},
    {1, 0, 3, 2, 2, 1, 1, 2, 0,-1, 1, 2, 2,-1, 1, 1,-1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
    {1, 2, 0, 0, 0, 2, 2, 1, 0, 2, 1, 1,-1, 1, 1, 2, 2, 0, 0},
    {1, 3, 0, 1,-1, 0, 2, 1, 1, 2, 2, 1,-1, 2, 2, 1, 1, 1,-1}
};

int check(int r, int c)
{
    int ret = 0;
    int temp;                                       // 좌표값을 받으면
    for(int i = 0 ; i < 19 ; i++)                   // 해당 좌표값을 기준으로 하는 19가지 종류 검사
    {
        temp = 0;
        for(int k = 0 ,row,col ; k < 4 ; k++)       // 4개의 점들에 대한 합을 구함
        {
            row = r + points[k][i];                 // 해당 좌표들은 선계산해놓은 배열에서 가져옴
            col = c + points[4 + k][i];
            if(row < 0 || row >= n || col < 0 || col >= m) break;      // 인덱스 검사
            temp += score[row][col];
        }
        if(temp > ret) ret = temp;
    }
    return ret;
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < m ; c++)
        {
            cin >> score[r][c];
        }
    }
    int max = 0;
    int cur;
    for(int r = 0 ; r < n ; r++)                // 모든 좌표에 대해서 완전 탐색
    {
        for(int c = 0 ; c < m ; c++)            // 가능한 모든 테트로미노를 놔보고, 최댓값 갱신
        {
            cur = check(r, c);
            if(cur > max) max = cur;
        }
    }
    cout << max << '\n';
}