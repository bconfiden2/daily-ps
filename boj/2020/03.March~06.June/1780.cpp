#include <iostream>
#include <vector>
using namespace std;

int paper[2187][2187];      // 입력 받은 종이 정보
int ans[3];                 // 각각 -1, 0, 1 일때의 갯수들에 대한 배열

void check(int row, int col, int size)              // 재귀호출함수
{
    bool able = true;                               
    int standard = paper[row][col];                 // 이번 종이 검사의 기준값
    for(int r = row ; r < row + size ; r++)         
    {
        for(int c = col ; c < col + size ; c++)
        {
            if(paper[r][c] != standard)             // 만약 다른 값이 하나라도 있으면
            {
                able = false;                       // 이번 종이는 잘라야한다고 표시해줌
                break;
            }
        }
        if(able == false) break;
    }
    if(able) ans[standard + 1]++;                   // 만약 값이 다 똑같으면 해당 종이에 추가
    else                                            // 잘라야 할 종이일 경우에는
    {
        int temp = size / 3;
        for(int i = 0 ; i < 3 ; i++)                // 9등분해서 각각의 첫 좌표를 기준으로 넘겨줌
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                check(row + temp * i, col + temp * j, temp);
            }
        }
    }
    return;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int row = 0, data ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            cin >> paper[row][col];
        }
    }
    check(0, 0, n);
    for(int i = 0 ; i < 3 ; i++) cout << ans[i] << '\n';
}
