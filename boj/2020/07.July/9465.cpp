#include <iostream>

using namespace std;

int t, n;
int r1[100001];
int r2[100001];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    for(int tc = 0 ; tc < t ; tc++)
    {
        int answer = 0;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> r1[i];                                           // 값을 배열에 입력
        for(int i = 0 ; i < n ; i++)
            cin >> r2[i];

        r1[1] += r2[0];                                             // 1번 열의 경우 먼저 따로 처리를 해줌
        r2[1] += r1[0];                                             // 가능한 값이 대각선 위치밖에 없으므로, 해당 위치의 스티커값을 더해준다.

        for(int i = 2, maxi, temp ; i < n ; i++)                    // 2번 열부터 반복 시작
        {
            temp = r1[i-2] > r2[i-2] ? r1[i-2] : r2[i-2];           // a b #   -> # 의 자리에서 가능한 최댓값은, a c d 세 자리 중 최댓값을 더한 값
            maxi = r2[i-1] > temp ? r2[i-1] : temp;                 // c d e
            r1[i] += maxi;
            if(r1[i] > answer) answer = r1[i];

            temp = r2[i-2] > r1[i-2] ? r2[i-2] : r1[i-2];           // a b c    -> # 의 자리에서 가능한 최댓값은, a b d 세 자리 중 최댓값을 더한 값
            maxi = r1[i-1] > temp ? r1[i-1] : temp;                 // d e #
            r2[i] += maxi;
            if(r2[i] > answer) answer = r2[i];
        }

        if(n == 1) cout << (r1[0] > r2[0] ? r1[0] : r2[0]) << endl;
        else if(n == 2) cout << (r1[1] > r2[1] ? r1[1] : r2[1]) << endl;
        else cout << answer << '\n';
    }
}