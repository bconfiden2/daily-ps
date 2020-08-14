#include <iostream>

using namespace std;

int n, m, temp, answer;
int a = 0, b = 1;                       // 특정 구간을 가리키는 왼쪽 인덱스 a, 오른쪽 인덱스 b
int data[10001];                        // 누적합의 차를 통해 구간의 합을 구함

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        data[i+1] = data[i] + temp;     // 각 위치의 누적합들을 구해 놓는다
    }
    while(a != n)
    {
        temp = data[b] - data[a];       // 두 위치값의 차이가
        if(temp == m)                   // 구하려는 m 과 같다면 (구간 사이의 합이 m 이라면)
        {
            answer++;                   // 답을 1 증가
            a++;
        }
        else if(temp < m)               // 만약 m 보다 작다면
        {
            if(b == n) break;           // 오른쪽이 더이상 갈곳이 없으면 종료
            b++;                        // 오른쪽 위치를 한칸 옮김
        }
        else a++;                       // m 보다 클 경우 왼쪽 위치를 한칸 옮김
    }
    cout << answer << endl;
}