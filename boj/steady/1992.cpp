#include <iostream>

using namespace std;

char temp[64][64];
int video[64][64];

void solve(int row, int col, int size)              // 시작점 row, col, 길이 size
{
    int first = video[row][col];                    // 이번 동영상이 유효한지 비교할 시작점의 값
    if(size == 1)
    {                                               // 길이가 1이면 무조건 유효하므로 값 출력 후 종료
        cout << first;
        return;
    }
    bool able = true;                               
    for(int r = row ; r < row + size ; r++)
    {
        for(int c = col ; c < col + size ; c++)
        {
            if(video[r][c] != first)                // 해당 동영상을 쭉 검사해서
            {
                able = false;                       // 다른게 하나라도 있으면 압축불가능 표시
                break;
            }
        }
        if(able == false) break;
    }
    if(able)                                        // 압축 가능한 동영상이면 해당 값으로 출력
    {
        cout << first;
    }
    else                                            // 불가능할 경우엔 다시 4 분야로 나눠서 압축을 시도
    {
        int temp = size / 2;                        
        cout << "(";                                // 압축 시작
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < 2 ; j++)            // 4등분 한 좌표값들을 구해서 해당 부분 각자 압축 처리
            {                                         
                solve(row + temp * i, col + temp * j, temp);
            }
        }
        cout << ")";                                 // 압축 종료
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {                                                       // 숫자로 쭉 입력받으면 1과 0들을 구분하지 않으니까
            cin >> temp[row][col];                              // 문자형으로 먼저 입력 받고
            if(temp[row][col] == '1') video[row][col] = 1;      // 해당 숫자로 다시 채워줌
            else video[row][col] = 0;
        }
    }
    solve(0, 0, n);                                             // 재귀 시작
    cout << '\n';
}