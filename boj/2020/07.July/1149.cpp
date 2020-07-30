#include <iostream>

using namespace std;

int n;
int colors[1000][3];        // rgb 값 입력 배열
int answer[1000][3];        // 각각의 최솟값을 담을 DP 배열

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
    }
    answer[0][0] = colors[0][0];
    answer[0][1] = colors[0][1];                                        // 첫번째 집은 따로 처리를 해준다
    answer[0][2] = colors[0][2];
    for(int r = 1 ; r < n ; r++)                                        // 두번째 집부터 n번째 집까지 각각의 최솟값을 구함
    {
        for(int c = 0 ; c < 3 ; c++)                                    // 각 집의 rgb 색깔별로
        {
            int mini = 1 << 30;
            for(int i = 0 ; i < 3 ; i++)                                // 직전 집 rgb 값들의 최솟값을 구함
            {                                   
                if(i == c) continue;                                    // 같은 색깔은 제외
                if(answer[r - 1][i] < mini) mini = answer[r - 1][i];
            }
            answer[r][c] = mini + colors[r][c];                         // 해당 최솟값 + 현재 rgb 값을 현재 최솟값으로 저장
        }
    }
    int minimum = 1 << 30;
    for(int i = 0 ; i < 3 ; i++)                                        // n - 1 번째 행의 rgb 값에는 전체 집을 색칠하는 각각의 최솟값들이 들어 있음
    {
        if(answer[n - 1][i] < minimum) minimum = answer[n - 1][i];
    }
    cout << minimum << '\n';
}