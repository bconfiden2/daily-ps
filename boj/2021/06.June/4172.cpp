#include <iostream>
#include <cmath>

using namespace std;

int cur;
int values[1000001] = {1};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1 ; i <= 1000000 ; i++) // 미리 dp 배열 구해놓기
    {                                   // 주어진 수식에 맞는 값들
        values[i] = (values[int(i-sqrt(i))] + values[int(log(i))] + values[int(i*sin(i)*sin(i))]) % 1000000;
    }

    cin >> cur;
    while(cur != -1)                    // -1 이 나올 때 까지 인덱스를 입력받아서 출력
    {
        cout << values[cur] << '\n';
        cin >> cur;
    }
}